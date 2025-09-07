#include <iostream>
#include "./Logger.hpp"

int main() {
    using namespace pentester;
    Logger log;

    log.log<"Hello, &&, & World">("Pentester");
}