#include "String.h"

namespace {
    void my_strcpy(char* dest, const char* src) {
        while ((*dest++ = *src++));
    }

    void my_strcat(char* dest, const char* src) {
        while (*dest) {
            dest++;
        }
        while ((*dest++ = *src++));
    }
}

String::String(const char* cString) {
    if (cString) {
        mData = new char[std::strlen(cString) + 1];
        my_strcpy(mData, cString);
    }
    else {
        mData = new char[1];
        mData[0] = '\0';
    }
}

String::String(const std::string& stlString) : String(stlString.c_str()) {}

String::String(const String& other) {
    mData = new char[std::strlen(other.mData) + 1];
    my_strcpy(mData, other.mData);
}

String::String(String&& other) noexcept : mData(other.mData) {
    other.mData = nullptr;
}

String::~String() {
    delete[] mData;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        char* newData = new char[std::strlen(other.mData) + 1];
        my_strcpy(newData, other.mData);
        delete[] mData;
        mData = newData;
    }
    return *this;
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] mData;
        mData = other.mData;
        other.mData = nullptr;
    }
    return *this;
}

char& String::operator[](std::size_t index) {
    return mData[index];
}

const char& String::operator[](std::size_t index) const {
    return mData[index];
}

String& String::operator+=(const String& rhs) {
    std::size_t newLength = std::strlen(mData) + std::strlen(rhs.mData);
    char* newData = new char[newLength + 1];
    my_strcpy(newData, mData);
    my_strcat(newData, rhs.mData);
    delete[] mData;
    mData = newData;
    return *this;
}

String::operator const char* () const {
    return mData;
}

const char* String::c_str() const {
    return mData;
}

std::size_t String::size() const {
    return std::strlen(mData);
}

void String::print() const {
    std::cout << mData;
}

String operator+(const String& lhs, const String& rhs) {
    String result(lhs);
    result += rhs;
    return result;
}

String operator+(const String& lhs, const std::string& rhs) {
    return lhs + String(rhs);
}

String operator+(const std::string& lhs, const String& rhs) {
    return String(lhs) + rhs;
}

String operator+(const String& lhs, const char* rhs) {
    return lhs + String(rhs);
}

String operator+(const char* lhs, const String& rhs) {
    return String(lhs) + rhs;
}

bool operator==(const String& lhs, const String& rhs) {
    return std::strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}
