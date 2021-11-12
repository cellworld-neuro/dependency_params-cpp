#include <params_cpp/key.h>

namespace params_cpp{

    Key::Key(const std::vector<std::string> &aliases): aliases(aliases) {

    }

    bool Key::match(const std::string &param) const {
        for (auto alias:aliases){
            if (alias == param) return true;
        }
        return false;
    }

    Key::Key(const std::string &alias) {
        aliases.push_back(alias);
    }

    Key::Key(const std::string &alias0, const std::string &alias1) {
        aliases.push_back(alias0);
        aliases.push_back(alias1);
    }

    Key::Key(const std::string &alias0, const std::string &alias1, const std::string &alias2) {
        aliases.push_back(alias0);
        aliases.push_back(alias1);
        aliases.push_back(alias2);
    }

    Key::Key(const std::string &alias0, const std::string &alias1, const std::string &alias2,
             const std::string &alias3) {
        aliases.push_back(alias0);
        aliases.push_back(alias1);
        aliases.push_back(alias2);
        aliases.push_back(alias3);
    }
}