

#ifndef CPP_LAB3_BLOCKEXCEPTION_H
#define CPP_LAB3_BLOCKEXCEPTION_H


#include <exception>
#include <string>


namespace Workflow {

    class BlockException: public std::exception{

    private:
        std::string msg_;

    public:

        explicit BlockException(std::string msg): msg_(std::move(msg)) {};

        [[nodiscard]] const char* what() const noexcept override{
            return msg_.c_str();
        }

        ~BlockException() override = default;
    };

}


#endif //CPP_LAB3_BLOCKEXCEPTION_H
