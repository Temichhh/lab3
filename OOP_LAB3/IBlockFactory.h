

#ifndef CPP_LAB3_IBLOCKFACTORY_H
#define CPP_LAB3_IBLOCKFACTORY_H

#include "IBlock.h"


namespace Workflow{

    class IBlockFactory{

    public:

        [[nodiscard]] virtual std::unique_ptr<IBlock> createBlock() const = 0;

        virtual ~IBlockFactory() = default;
    };

}


#endif //CPP_LAB3_IBLOCKFACTORY_H
