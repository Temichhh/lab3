

#ifndef CPP_LAB3_BLOCKNOTFOUNDEXCEPTION_H
#define CPP_LAB3_BLOCKNOTFOUNDEXCEPTION_H


#include "../WorkflowException.h"


namespace Workflow {

    class BlockNotFoundException : public WorkflowException {

    public:

        explicit BlockNotFoundException(std::string msg) : WorkflowException(std::move(msg)){};

        ~BlockNotFoundException() override = default;
    };

}


#endif //CPP_LAB3_BLOCKNOTFOUNDEXCEPTION_H
