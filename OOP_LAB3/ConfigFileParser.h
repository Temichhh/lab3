

#ifndef CPP_LAB3_CONFIGFILEPARSER_H
#define CPP_LAB3_CONFIGFILEPARSER_H

#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <regex>

#include "Exceptions/FileNotFoundException.h"


namespace Workflow{


    class ConfigFileParser{

    private:
        std::unordered_map<int, std::pair<std::string, std::vector<std::string>>> blocks_;
        std::vector<int> blocks_conveyor_;

        static std::vector<std::string> loadFromFile(const std::string&);

    public:

        void extract(const std::string&);

        [[nodiscard]] const std::unordered_map<int, std::pair<std::string, std::vector<std::string>>>&
            getBlocks() const;

        [[nodiscard]] const std::vector<int>& getBlocksConveyor() const;

        ConfigFileParser() = default;

        ~ConfigFileParser() = default;
    };
}


#endif //CPP_LAB3_CONFIGFILEPARSER_H
