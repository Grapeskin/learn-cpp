#include "cstdio"
#include "spdlog/fmt/bundled/core.h"
#include "spdlog/spdlog.h"
#include "json/json.h"
#include <fstream>
#include <ios>

int main() {
  // https://fmt.dev/latest/index.html
  spdlog::info("hello, world");
  spdlog::info("Hello, {name}! The answer is {number}. Goodbye, {name}.",
               fmt::arg("name", "World"), fmt::arg("number", 42));
  Json::Value root;

  // http://open-source-parsers.github.io/jsoncpp-docs/doxygen/index.html
  // Read from file
  Json::CharReaderBuilder rbuilder;
  rbuilder["collectComments"] = false;
  std::string errs;
  std::fstream f;
  f.open("/home/ubuntu/GitRepo/learn-cpp/src/test.json", std::ios::in);
  if (!f.is_open()) {
    spdlog::error("file open failed.");
  }
  bool ok = Json::parseFromStream(rbuilder, f, &root, &errs);
  spdlog::info(root.toStyledString());
  spdlog::info(root["encoding"].asString());

  // Read from string.
  const std::string rawJson = R"({"Age": 20, "Name": "colin"})";
  std::unique_ptr<Json::CharReader> const reader(rbuilder.newCharReader());
  if (!reader->parse(rawJson.c_str(), rawJson.c_str() + rawJson.length(), &root,
                     &errs)) {
    spdlog::error("parse failed");
  }
  spdlog::info("Age: {}, Name: {}", root["Age"].asInt(),
               root["Name"].asString());

  return 0;
}