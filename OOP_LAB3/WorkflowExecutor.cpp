//
// Created by argem on 04.11.2021.
//

#include "WorkflowExecutor.h"


using namespace std;
using namespace Workflow;


void WorkflowExecutor::loadFromFile(const string & file_name) {

    ConfigFileParser parser;
    parser.extract(file_name);
    auto blocks_map = parser.getBlocks();

    conveyor_.clear();
    for(int i : parser.getBlocksConveyor()){

        auto it = blocks_map.find(i);
        if(it==blocks_map.end())
            throw BlockNotFoundException("Can`t find description of block: " + to_string(i));

        auto block = it->second;
        auto factory = getBlockFactoryByName(block.first);

        if(factory==nullptr){
            throw BlockNameException("Тo blocks of this type: " + block.first);
        }

        conveyor_.push_back(factory->createBlock());
        conveyor_.back()->setArguments(block.second);
    }
}


void WorkflowExecutor::execute() {

    if(conveyor_.empty()){
        //если конвейера нет, то ничего не делаем
        return;
    }

    conveyor_[0]->work();
    for(size_t i=1; i<conveyor_.size(); ++i){
        conveyor_[i]->input(conveyor_[i-1]->output());
        conveyor_[i]->work();
    }
}


std::unique_ptr<IBlockFactory> WorkflowExecutor::getBlockFactoryByName
                            (const std::string& block_name) {

    if(block_name == "readfile")
        return make_unique<BlockFactory<ReadFileBlock>>();

    if(block_name == "writefile")
        return make_unique<BlockFactory<WriteFileBlock>>();

    if(block_name == "sort")
        return make_unique<BlockFactory<SortBlock>>();

    if(block_name == "replace")
        return make_unique<BlockFactory<ReplaceBlock>>();

    if(block_name == "grep")
        return make_unique<BlockFactory<GrepBlock>>();

    if(block_name == "dump")
        return make_unique<BlockFactory<DumpBlock>>();

    return nullptr;
}

