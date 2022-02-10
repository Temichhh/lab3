

#ifndef CPP_LAB3_WRITEFILEBLOCK_H
#define CPP_LAB3_WRITEFILEBLOCK_H

#include "DumpBlock.h"


namespace Workflow {

    class WriteFileBlock : public DumpBlock {

    public:

        [[nodiscard]] std::optional<std::unique_ptr<Text>> output() override;

        WriteFileBlock() = default;

        ~WriteFileBlock() override = default;
    };

}

#endif //CPP_LAB3_WRITEFILEBLOCK_H
