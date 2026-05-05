#include "ConfigLoader.h"
#include <fstream>
#include "../external/json/json.hpp"

using json = nlohmann::json;

std::vector<std::wstring> LoadBlockedProcesses() {
    std::ifstream file("config/config.json");

    json j;
    file >> j;

    std::vector<std::wstring> processes;

    for (auto& name : j["blocked"]) {
        std::string s = name;
        processes.push_back(std::wstring(s.begin(), s.end()));
    }

    return processes;
}