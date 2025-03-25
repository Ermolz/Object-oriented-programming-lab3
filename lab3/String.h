#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>
#include <string>

class String {
public:
    explicit String(const char* cString = "");
    explicit String(const std::string& stlString);
    String(const String& other);
    String(String&& other) noexcept;
    ~String();

    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;

    char& operator[](std::size_t index);
    const char& operator[](std::size_t index) const;

    String& operator+=(const String& rhs);
    operator const char* () const;

    const char* c_str() const;
    std::size_t size() const;
    void print() const;

    friend String operator+(const String& lhs, const String& rhs);
    friend bool operator==(const String& lhs, const String& rhs);
    friend bool operator!=(const String& lhs, const String& rhs);

private:
    char* mData;
};

String operator+(const String& lhs, const std::string& rhs);
String operator+(const std::string& lhs, const String& rhs);
String operator+(const String& lhs, const char* rhs);
String operator+(const char* lhs, const String& rhs);

#endif // STRING_H
