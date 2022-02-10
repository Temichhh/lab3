//
// Created by argem on 02.11.2021.
//

#include "GrepBlock.h"

using namespace std;
using namespace Workflow;


void GrepBlock::work() {

    if(text_== nullptr){
        throw ResourceBlockException("Grep block doesn`t own the text resource");
    }

    vector<string> new_text;

    for(auto &line : *text_){
        if(line.find(word_) != string::npos) {
            new_text.push_back(move(line));
        }
    }

    *text_ = move(new_text);
}


void GrepBlock::setArguments(const vector<std::string> & argv) {

    if(argv.empty())
        throw ArgBlockException("Not enough arguments for grep");

    word_ = argv[0];
}

