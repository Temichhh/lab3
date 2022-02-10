

#ifndef CPP_LAB3_DUMPBLOCK_H
#define CPP_LAB3_DUMPBLOCK_H

#include "../IBlock.h"
#include <fstream>


namespace Workflow {

    class DumpBlock : public IBlock {

    private:
        std::string file_name_;
        std::unique_ptr<Text> text_;

    public:

        void work() override;

        void input(std::optional<std::unique_ptr<Text>>) override;

        [[nodiscard]] std::optional<std::unique_ptr<Text>> output() override;

        void setArguments(const std::vector<std::string>&) override;

        DumpBlock();

        ~DumpBlock() override = default;
    };
}


#endif //CPP_LAB3_DUMPBLOCK_H
