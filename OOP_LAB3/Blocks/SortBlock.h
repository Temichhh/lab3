

#ifndef CPP_LAB3_SORTBLOCK_H
#define CPP_LAB3_SORTBLOCK_H

#include "InternalBlock.h"
#include <algorithm>

namespace Workflow{

    class SortBlock: public InternalBlock{

    public:

        void work() override;

        void setArguments(const std::vector<std::string>&) override;

        SortBlock() = default;

        ~SortBlock() override = default;
    };
}


#endif //CPP_LAB3_SORTBLOCK_H
