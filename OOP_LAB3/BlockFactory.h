

#ifndef CPP_LAB3_BLOCKFACTORY_H
#define CPP_LAB3_BLOCKFACTORY_H

#include "IBlockFactory.h"


namespace Workflow {

    template <typename BlockType>
    class BlockFactory: public IBlockFactory {

    public:

        [[nodiscard]] std::unique_ptr<IBlock> createBlock() const override;

        BlockFactory() = default;
        ~BlockFactory() override = default;
    };

    template<class BlockType>
    std::unique_ptr<IBlock> BlockFactory<BlockType>::createBlock() const {

        return std::make_unique<BlockType>();
    }

}


#endif //CPP_LAB3_BLOCKFACTORY_H
