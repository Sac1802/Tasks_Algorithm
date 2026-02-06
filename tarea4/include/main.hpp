#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>


class UserSystem
{
private:
    // Stores each email/username and the number of times it has been requested.
    // Key   -> username
    // Value -> count of occurrences
    std::unordered_map<std::string, int> emails;

public:
    int validateValue(const std::string &value);
    void updateValue(const std::string &value, int newValue);
    std::string generateNewValue(const std::string &value, int currentValue);
    std::string insertValues(const std::string &value);
};



#endif