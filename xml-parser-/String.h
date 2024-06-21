#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

class String
{
    char* data;
    unsigned len;
    unsigned capacity;

    void copyFrom(const String& other);
    void free();
    void resize();

public:
    int getFileSize(std::ifstream& ifs);
    void readFile(const char* filename);
    explicit String(unsigned capacity);
    String();
    String(const char* str);
    String(const String& other);
    String& operator=(const String& other);
    ~String();

    unsigned length() const;
    const char* c_str() const;
    String& concat(const String& other);
    
    String& operator+=(const String& other);
    String& operator+=(char ch);

    char& operator[](size_t index);
    char operator[](size_t index) const;

    bool isAlnum(size_t index) const;
    bool isSpace(size_t index) const;

    String substr(size_t start, size_t end);

    friend String operator+(const String& lhs, const String& rhs);
    friend std::istream& operator>>(std::istream& is, String& str);
};

std::ostream& operator<<(std::ostream& os, const String& str);

bool operator<(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);

unsigned getNextPowerOfTwo(unsigned n);

