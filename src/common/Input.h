#pragma once
#include <cstdlib>
#include <iostream>

// Safe console input: keeps asking until the value parses correctly.
template <class T>
T ask(const char* msg) {
    T v;
    std::cout << msg;
    while (!(std::cin >> v)) {
        if (std::cin.eof()) std::exit(0);
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid, try again: ";
    }
    return v;
}
