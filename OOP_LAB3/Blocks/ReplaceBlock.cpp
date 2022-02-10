//
// Created by argem on 02.11.2021.
//

#include "ReplaceBlock.h"

using namespace std;
using namespace Workflow;


void ReplaceBlock::work() {

    if(text_==nullptr){
        throw ResourceBlockException("Replace block doesn`t own the text resource");
    }

    vector<string> new_text;
    regex ex(old_word_);
    for(const auto &line : *text_){
        new_text.push_back(regex_replace(line, ex, new_word_));
    }

    *text_ = move(new_text);
}


void ReplaceBlock::setArguments(const vector<std::string> &argv) {

    if(argv.size()<2)
        throw ArgBlockException("Not enough arguments for replace");

    old_word_ = argv[0];
    new_word_ = argv[1];
}
