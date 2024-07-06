#include <fstream>
#include <ios>

#include "cstdio"
#include "json/json.h"
#include "spdlog/fmt/fmt.h"
#include "spdlog/spdlog.h"

int main() {
    Json::Value json(Json::objectValue);
    json["key"] = "value";
    printf("%s", json.toStyledString().c_str());
    spdlog::info("hello, world");
    return 0;
}