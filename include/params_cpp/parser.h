#pragma once
#include <string>
#include <vector>
#include <params_cpp/key.h>

namespace params_cpp {
    struct Parser {
        Parser (int argc, char **argv);
        std::string program;
        std::vector<std::string> raw;
        bool contains(const Key &key) const;
        bool contains(const std::vector<Key> &keys) const;
        const std::string &get(const Key &key, const std::string &) const;
        const std::string &get(const Key &key) const;
        const std::string &get(int pos);
    };
}