#include <iostream>
#include <cassert>
#include <cstring>
#include "String.h"
#include <string>

int main() {
    // Test constructors and conversion to C-string
    String str1("Hello");
    assert(std::strcmp(str1.c_str(), "Hello") == 0);

    String str2(std::string(", world"));
    assert(std::strcmp(str2.c_str(), ", world") == 0);

    // Test operator+ with String + std::string and std::string + String
    String concat1 = str1 + str2;
    assert(std::strcmp(concat1.c_str(), "Hello, world") == 0);

    String concat2 = std::string("Say: ") + str1;
    assert(std::strcmp(concat2.c_str(), "Say: Hello") == 0);

    // Test operator+ with C-string + String and String + C-string
    String concat3 = "Start: " + str1;
    assert(std::strcmp(concat3.c_str(), "Start: Hello") == 0);

    String concat4 = str1 + " End";
    assert(std::strcmp(concat4.c_str(), "Hello End") == 0);

    // Test operator+=
    String copyStr = str1;
    copyStr += str2;
    assert(std::strcmp(copyStr.c_str(), "Hello, world") == 0);

    // Test assignment operators
    String strCopy = concat4;
    assert(std::strcmp(strCopy.c_str(), "Hello End") == 0);

    // Test move assignment
    String strMove = std::move(strCopy);
    assert(std::strcmp(strMove.c_str(), "Hello End") == 0);

    // Test operator[] and modification
    str1[0] = 'h';
    assert(std::strcmp(str1.c_str(), "hello") == 0);

    // Test equality and inequality operators
    String equalTest("Test");
    String equalTestCopy("Test");
    String diffTest("Different");
    assert(equalTest == equalTestCopy);
    assert(equalTest != diffTest);

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}
