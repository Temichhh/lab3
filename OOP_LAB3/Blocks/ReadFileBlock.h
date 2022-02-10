

#ifndef CPP_LAB3_READFILEBLOCK_H
#define CPP_LAB3_READFILEBLOCK_H

#include "../IBlock.h"
#include <fstream>


namespace Workflow {

    class ReadFileBlock : public IBlock {

    private:
        std::unique_ptr<Text> text_;
        std::string file_name_;

    public:

        void work() override;

        void input(std::optional<std::unique_ptr<Text>>) override;

        [[nodiscard]] std::optional<std::unique_ptr<Text>> output() override;

        void setArguments(const std::vector<std::string>&) override;

        ReadFileBlock();

        ~ReadFileBlock() override = default;
    };
}


#endif //CPP_LAB3_READFILEBLOCK_H
