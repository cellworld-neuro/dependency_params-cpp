#include <params_cpp/parser.h>


namespace params_cpp{

    std::string not_found("");

    Parser::Parser(int argc, char **argv) {
        program = argv[0];
        for (int c=1;c<argc;c++)
            raw.push_back(argv[c]);
    }

    const std::string &Parser::get(const Key &key) const {
        bool next = false;
        for (auto &p:raw ){
            if (next) return p;
            if (key.match(p)) next = true;
        }
        return not_found;
    }

    bool Parser::contains(const Key &key) const {
        for (auto &p:raw )
            if (key.match(p)) return true;
        return false;
    }

    bool Parser::contains(const std::vector<Key> &keys) const {
        for (auto &key:keys)
            if (!contains(key)) return false;
        return true;
    }

    const std::string &Parser::get(int pos) {
        int c = 0;
        for (auto &p:raw ){
            if (p.starts_with('-')) c--;
            else {
                if (c == pos) return p;
                c++;
            }
        }
        return not_found;
    }
}