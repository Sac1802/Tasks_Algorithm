#include <iostream>
#include <vector>

std::vector<std::vector<long long>> memoization;

/**
 * This function calculates how many combinations can be formed for a given value of n.
 * It uses previous results (n-1 and n-2) to avoid recalculating everything from scratch.
 * It stores the results in the "memoization" array.
 */
void maximCombination(int n)
{
    if (n == 1)
    {
        memoization[0][n] = 1;
        memoization[1][n] = 1;
        return;
    }
    if (n == 2)
    {
        memoization[0][n] = 1;
        memoization[1][n] = 1;
        return;
    }

    memoization[0][n] = memoization[1][n - 1] + memoization[1][n - 2];
    memoization[1][n] = memoization[0][n - 1] + memoization[0][n - 2];
}

/**
 * Main function of the program:
 * Reads the number n, prepares the memory to store results,
 * calculates the combinations step by step, and displays the final result.
 */
int main(void)
{
    int n;
    if (!(std::cin >> n)) return 0;

    memoization.assign(2, std::vector<long long>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        maximCombination(i);
    }

    std::cout << memoization[0][n] + memoization[1][n] << std::endl;

    return 0;
}

