

#ifndef CPP_LAB3_GREPBLOCK_H
#define CPP_LAB3_GREPBLOCK_H

#include "InternalBlock.h"


namespace Workflow{

    class GrepBlock: public InternalBlock{

    private:
        std::string word_;

    public:

        void work() override;

        void setArguments(const std::vector<std::string>&) override;

        GrepBlock() = default;

        ~GrepBlock() override = default;
    };
}


#endif //CPP_LAB3_GREPBLOCK_H
