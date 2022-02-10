//
// Created by argem on 02.11.2021.
//

#include "DumpBlock.h"


using namespace std;
using namespace Workflow;


void DumpBlock::work() {

    if(text_== nullptr){
        throw ResourceBlockException("Dump block doesn`t own the text resource");
    }

    ofstream file_out(file_name_);

    for(size_t i=0; i<text_->size(); ++i){
        file_out << (*text_)[i];
        if(i+1 != text_->size())
            file_out << endl;
    }

    file_out.close();
}


void DumpBlock::setArguments(const vector<std::string> &argv) {

    if(argv.empty())
        throw ArgBlockException("Not enough arguments for dump");

    file_name_ = argv[0];
}


void DumpBlock::input(std::optional<std::unique_ptr<Text>> text) {

    if(!text){
        throw IOBlockException("No input resource passed for dump");
    }

    text_ = move(text.value());
}


std::optional<std::unique_ptr<Text>> DumpBlock::output() {

    return {move(text_)};
}


DumpBlock::DumpBlock(): text_(nullptr) {}
