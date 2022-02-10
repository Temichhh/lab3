

#ifndef CPP_LAB3_WORKFLOWEXECUTOR_H
#define CPP_LAB3_WORKFLOWEXECUTOR_H

#include <string>
#include <vector>
#include <memory>

#include "ConfigFileParser.h"
#include "BlockFactory.h"
#include "Blocks/DumpBlock.h"
#include "Blocks/ReadFileBlock.h"
#include "Blocks/WriteFileBlock.h"
#include "Blocks/SortBlock.h"
#include "Blocks/ReplaceBlock.h"
#include "Blocks/GrepBlock.h"

#include "Exceptions/ExecutorExceptions/BlockNameException.h"
#include "Exceptions/ExecutorExceptions/BlockNotFoundException.h"


namespace Workflow {

    class WorkflowExecutor {

    private:

        std::vector<std::unique_ptr<IBlock>> conveyor_;

        static std::unique_ptr<IBlockFactory>
            getBlockFactoryByName(const std::string&);

    public:

        void loadFromFile(const std::string&);

        void execute();

        WorkflowExecutor() = default;
        ~WorkflowExecutor() = default;
    };
}


#endif //CPP_LAB3_WORKFLOWEXECUTOR_H
