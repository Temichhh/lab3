

#ifndef CPP_LAB3_INTERNALBLOCK_H
#define CPP_LAB3_INTERNALBLOCK_H

#include "../IBlock.h"


namespace Workflow{

    class InternalBlock: public IBlock{

    protected:
        std::unique_ptr<Text> text_;
        //нехорошо иметь protected-поле
    public:

        void input(std::optional<std::unique_ptr<Text>>) override;

        [[nodiscard]] std::optional<std::unique_ptr<Text>> output() override;

        InternalBlock();

        ~InternalBlock() override = default;

    };
}


#endif //CPP_LAB3_INTERNALBLOCK_H
