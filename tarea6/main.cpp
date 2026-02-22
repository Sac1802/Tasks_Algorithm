#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<int> calculate_table(std::string pattern)
{
    int m = pattern.length();
    std::vector<int> table(m);
    int j = 0;
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j])
            j++;
        table[i] = j;
    }
    return table;
}

std::string find_pattern(std::string pattern, std::string line, std::vector<int> &table)
{
    int state = 0;
    int lengthLine = line.length();
    std::string values;
    for (int i = 0; i < lengthLine; i++)
    {
        while (state > 0 && line[i] != pattern[state])
        {
            state = table[state - 1];
        }

        if (line[i] == pattern[state])
        {
            state++;
        }

        if (state == pattern.length())
        {
            state = table[state - 1];
            values += std::to_string(i - pattern.length() + 1);
        }
    }

    return values;
}

void find_file(std::string route, std::string pattern)
{
    std::vector<int> table = calculate_table(pattern);
    std::string secret_code = "";

    std::ifstream file(route);

    if (!file.is_open())
    {
        std::cerr << "Error not open file" << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line))
    {
        std::string index = find_pattern(pattern, line, table);
        if (index.length() != 0)
        {
            secret_code +=  index;
        }
    }
    std::cout << secret_code << std::endl;
}

int main(void)
{
    find_file("hidden_code.txt", "h2xr30");
    return 0;
}