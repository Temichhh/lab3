

#ifndef CPP_LAB3_IOBLOCKEXCEPTION_H
#define CPP_LAB3_IOBLOCKEXCEPTION_H


#include "../BlockException.h"


namespace Workflow {

    class IOBlockException: public BlockException {

    public:

        explicit IOBlockException(std::string msg): BlockException(std::move(msg)){}

        ~IOBlockException() override = default;
    };

}

#endif //CPP_LAB3_IOBLOCKEXCEPTION_H
