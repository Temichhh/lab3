

#ifndef CPP_LAB3_WORKFLOWEXCEPTION_H
#define CPP_LAB3_WORKFLOWEXCEPTION_H


#include <exception>
#include <string>


namespace Workflow {

    class WorkflowException: public std::exception{

    private:
        std::string msg_;

    public:

        explicit WorkflowException(std::string msg): msg_(std::move(msg)) {}

        [[nodiscard]] const char* what() const noexcept override{
            return msg_.c_str();
        }

        ~WorkflowException() override = default;
    };

}

#endif //CPP_LAB3_WORKFLOWEXCEPTION_H
