#include <array>
#include <iostream>
#include <stdio.h>
#include <string>

int main() {
  std::string cmd;
  while (1) {
    std::getline(std::cin, cmd);
    std::cout << cmd << std::endl;

    auto pPipe = ::popen(cmd.c_str(), "r");
    std::array<char, 256> buffer;

    std::string result;

    while (!std::feof(pPipe)) {
      auto bytes = std::fread(buffer.data(), 1, buffer.size(), pPipe);
      result.append(buffer.data(), bytes);
    }

    auto rc = ::pclose(pPipe);

    std::cout << result;
  }
}
