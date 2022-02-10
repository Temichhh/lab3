

#ifndef CPP_LAB3_RESOURCEBLOCKEXCEPTION_H
#define CPP_LAB3_RESOURCEBLOCKEXCEPTION_H


#include "../BlockException.h"


namespace Workflow {

    class ResourceBlockException: public BlockException {

    public:

        explicit ResourceBlockException(std::string msg): BlockException(std::move(msg)){}

        ~ResourceBlockException() override = default;
    };

}


#endif //CPP_LAB3_RESOURCEBLOCKEXCEPTION_H
