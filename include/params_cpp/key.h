#pragma once
#include <string>
#include <vector>

namespace params_cpp {
    struct Key {
        Key(const std::vector<std::string> &aliases);
        Key(const std::string &alias);
        Key(const std::string &alias0, const std::string &alias1);
        Key(const std::string &alias0, const std::string &alias1, const std::string &alias2);
        Key(const std::string &alias0, const std::string &alias1, const std::string &alias2, const std::string &alias3);
        bool match(const std::string &param) const;
        std::vector<std::string> aliases;
    };
}