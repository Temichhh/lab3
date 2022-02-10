

#ifndef CPP_LAB3_ARGBLOCKEXCEPTION_H
#define CPP_LAB3_ARGBLOCKEXCEPTION_H


#include "../BlockException.h"


namespace Workflow {

    class ArgBlockException: public BlockException {

    public:

        explicit ArgBlockException(std::string msg): BlockException(std::move(msg)){}

        ~ArgBlockException() override = default;
    };

}


#endif //CPP_LAB3_ARGBLOCKEXCEPTION_H
