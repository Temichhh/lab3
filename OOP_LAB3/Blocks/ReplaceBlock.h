

#ifndef CPP_LAB3_REPLACEBLOCK_H
#define CPP_LAB3_REPLACEBLOCK_H

#include "InternalBlock.h"
#include <regex>


namespace Workflow{

    class ReplaceBlock: public InternalBlock{

    private:
        std::string old_word_, new_word_;

    public:

        void work() override;

        void setArguments(const std::vector<std::string>&) override;

        ReplaceBlock() = default;

        ~ReplaceBlock() override = default;
    };
}


#endif //CPP_LAB3_REPLACEBLOCK_H
