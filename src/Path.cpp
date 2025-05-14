#include "../lib/Path.hpp"

const std::string PATH::getPath(const std::string& path) {
    std::ifstream file(path);
    std::string before = "../";
    std::string result = "";
    result = file.is_open() ? path : before + path;
    file.close();
    return result;
}