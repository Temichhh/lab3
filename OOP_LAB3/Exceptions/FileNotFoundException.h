

#ifndef CPP_LAB3_FILENOTFOUNDEXCEPTION_H
#define CPP_LAB3_FILENOTFOUNDEXCEPTION_H


#include <exception>
#include <string>


namespace Workflow {

    class FileNotFoundException: std::exception {

    private:
        std::string msg_;

    public:

        explicit FileNotFoundException(std::string msg): msg_(std::move(msg)){}

        [[nodiscard]] const char* what() const noexcept override{
            return msg_.c_str();
        }

        ~FileNotFoundException() override = default;
    };

}

#endif //CPP_LAB3_FILENOTFOUNDEXCEPTION_H
