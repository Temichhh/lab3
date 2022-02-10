

#ifndef CPP_LAB3_BLOCKNAMEEXCEPTION_H
#define CPP_LAB3_BLOCKNAMEEXCEPTION_H


#include "../WorkflowException.h"


namespace Workflow {

    class BlockNameException : public WorkflowException {

    public:

        explicit BlockNameException(std::string msg): WorkflowException(std::move(msg)){}

        ~BlockNameException() override = default;
    };

}

#endif //CPP_LAB3_BLOCKNAMEEXCEPTION_H
