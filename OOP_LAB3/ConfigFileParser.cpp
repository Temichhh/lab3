//
// Created by argem on 03.11.2021.
//

#include "ConfigFileParser.h"

using namespace std;
using namespace Workflow;


vector<string> ConfigFileParser::loadFromFile(const string& file_name) {

    vector<string> text;
    ifstream fin(file_name);
    if(!fin.is_open())
        throw FileNotFoundException("Can`t open file: " + file_name);

    while (!fin.eof()) {
        string s;
        getline(fin, s);
        text.push_back(move(s));
    }
    fin.close();

    return text;
}


void ConfigFileParser::extract(const string& file_name) {

    auto text = move(loadFromFile(file_name));
    blocks_.clear();
    blocks_conveyor_.clear();

    regex block_description_re(R"( *(\d+) *= *(\w*) *([\w\.]*) *([\w\.]*) *)");
    regex conveyor_re("\\d+( *-> *\\d+)+");
    regex nums_re("\\d+");

    smatch match;
    for(const auto &line:text){

        if(regex_match(line, match, block_description_re)){

            blocks_[stoi(match[1])] = {match[2], {match[3], match[4]}};
        }
        else if(regex_match(line, match, conveyor_re)){

            blocks_conveyor_.clear();

            auto begin = sregex_iterator(line.begin(), line.end(), nums_re);
            auto end = sregex_iterator();
            for (auto it = begin; it != end; ++it) {
                blocks_conveyor_.push_back(stoi((*it).str()));
            }
        }
    }
}


[[nodiscard]] const std::unordered_map<int, std::pair<std::string, std::vector<std::string>>>&
        ConfigFileParser::getBlocks() const{
    return blocks_;
}


[[nodiscard]] const vector<int>& ConfigFileParser::getBlocksConveyor() const{
    return blocks_conveyor_;
}
