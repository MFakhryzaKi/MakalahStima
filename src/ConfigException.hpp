#pragma once

#include <exception>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class ConfigException : public exception {
protected:
    string message;
    int line;

public:
    ConfigException(const string& message, const int& line) : message(message), line(line) {}
    string toString () {
        return "Config error pada line " + to_string(line) + ": " + message;
    }
};
