

#ifndef CPP_LAB3_IBLOCK_H
#define CPP_LAB3_IBLOCK_H

#include <vector>
#include <string>
#include <optional>
#include <memory>

#include "Exceptions/BlockExceptions/ResourceBlockException.h"
#include "Exceptions/BlockExceptions/ArgBlockException.h"
#include "Exceptions/BlockExceptions/IOBlockException.h"
#include "Exceptions/FileNotFoundException.h"


namespace Workflow {

    using Text = std::vector<std::string>;
    

    class IBlock {

    public:
        virtual void work() = 0;

        virtual void input(std::optional<std::unique_ptr<Text>>) = 0;

        [[nodiscard]] virtual std::optional<std::unique_ptr<Text>> output()= 0;

        virtual void setArguments(const std::vector<std::string>&) = 0;

        virtual ~IBlock() = default;
    };
}

#endif //CPP_LAB3_IBLOCK_H
