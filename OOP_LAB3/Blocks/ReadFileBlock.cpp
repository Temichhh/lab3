//
// Created by argem on 02.11.2021.
//

#include "ReadFileBlock.h"

using namespace std;
using namespace Workflow;


void ReadFileBlock::work(){

    ifstream fin(file_name_);

    if(!fin.is_open())
        throw FileNotFoundException("Can`t open file: " + file_name_);

    text_ = make_unique<Text>();
    while(!fin.eof()){
        string s;
        getline(fin, s);
        text_->push_back(move(s));
    }

    fin.close();
}


void ReadFileBlock::setArguments(const vector<std::string> &argv) {

    if(argv.empty())
        throw ArgBlockException("Not enough arguments for readfile");
    file_name_ = argv[0];
}


void ReadFileBlock::input(std::optional<std::unique_ptr<Text>> text) {

    if(text){
        throw IOBlockException("Input resource passed for readfile");
    }
}


std::optional<std::unique_ptr<Text>> ReadFileBlock::output(){

    return {move(text_)};
}

ReadFileBlock::ReadFileBlock(): text_(nullptr) {}
