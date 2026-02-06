#include "main.hpp"

/**
 * Searches for a username in the map.
 * @param value The username to look up.
 * @return The number of times the username has appeared.
 *         Returns 0 if the username does not exist in the map.
 */
int UserSystem::validateValue(const std::string &value)
{
    auto finValue = emails.find(value);
    if (finValue != emails.end())
        return finValue->second;

    return 0;
}

/**
 * Updates the occurrence counter for a given username.
 * @param value The username to update.
 * @param newValue The new occurrence count.
 */
void UserSystem::updateValue(const std::string &value, int newValue)
{
    emails[value] = newValue;
}

/**
 * Generates a new unique username by appending a number
 * based on how many times the base username has appeared.
 * Example: "john" -> "john1", "john2", etc.
 *
 * @param value The original username.
 * @param currentValue The current count associated with the username.
 * @return A new generated username.
 */
std::string UserSystem::generateNewValue(const std::string &value, int currentValue)
{
    std::string newValue = value;
    newValue += std::to_string(currentValue - 1);
    return newValue;
}

/**
 * Inserts a username into the system.
 * - If the username does not exist, it is added and "OK" is returned.
 * - If it already exists, the counter is updated and a new unique
 *   username is generated and stored.
 *
 * @param value The username to insert.
 * @return "OK" if inserted for the first time, or the generated
 *         unique username if it already existed.
 */
std::string UserSystem::insertValues(const std::string &value)
{
    int validate = validateValue(value);

    if (validate == 0)
    {
        emails.insert({value, 1});
        return "OK";
    }
    else
    {
        int newVal = validate + 1;
        updateValue(value, newVal);

        std::string valueGenerated = generateNewValue(value, newVal);
        emails[valueGenerated] = 1;

        return valueGenerated;
    }
}

/**
 * Main function.
 * Reads a list of usernames from standard input,
 * processes them, and prints the results.
 */
int main()
{
    UserSystem system;
    int numberOfValues;
    std::cin >> numberOfValues;

    std::string value;
    std::vector<std::string> valuesSafe;

    for (int i = 0; i < numberOfValues; i++)
    {
        std::cin >> value;
        std::string valueInserted = system.insertValues(value);
        valuesSafe.push_back(valueInserted);
    }

    for (const std::string &v : valuesSafe)
    {
        std::cout << v << std::endl;
    }

    return 0;
}
