//
// Created by argem on 02.11.2021.
//

#include "InternalBlock.h"

using namespace std;
using namespace Workflow;


void InternalBlock::input(std::optional<std::unique_ptr<Text>> text) {

    if(!text){
        throw IOBlockException("No input resource passed for block");
    }

    text_ = move(text.value());
}


std::optional<std::unique_ptr<Text>> InternalBlock::output() {

    return {move(text_)};
}


InternalBlock::InternalBlock(): text_(nullptr) {}
