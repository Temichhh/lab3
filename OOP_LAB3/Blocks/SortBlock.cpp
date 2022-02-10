//
// Created by argem on 02.11.2021.
//

#include "SortBlock.h"


void Workflow::SortBlock::work() {

    if(text_==nullptr){
        throw ResourceBlockException("Sort block doesn`t own the text resource");
    }

    std::sort(text_->begin(), text_->end());
}


void Workflow::SortBlock::setArguments(const std::vector<std::string> &argv) {
    //ничего не делаем
}
