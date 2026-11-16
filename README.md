# CIS 165 - Lab 8: Lottery Simulation with Arrays and Loops

## How to Compile and Run
To compile and run this program from the terminal, use the following commands:

**Lottery Program:**
`g++ -std=c++17 -Wall -Wextra lottery.cpp -o lottery`
`./lottery`

* Note: I use a Mac, and so my terminal compiles slightly differently than a Windows machine. More specifically, I use `clang++` instead of `g++`*

## Program Plan

**lottery.cpp Plan:**
1. Declare a named constant `SIZE` set to `5`, two five-element integer arrays named `winningDigits` and `player`, and an integer `match_count` initialized to `0`.
2. Seed the random number generator once using `srand(time(0))`.
3. Use a `for` loop from `0` to `SIZE - 1` to populate each element of `winningDigits` with `rand() % 10` so every digit is between `0` and `9`.
4. Prompt the user to enter five digits and use a `for` loop to read each input into `player[i]`.
5. Use a `for` loop to compare `winningDigits[i]` and `player[i]` at the same index `i`, incrementing `match_count` whenever they are equal.
6. Output all five elements of `winningDigits`, all five elements of `player`, and the final `match_count` with clear labels.

## Test Tables

| Program and test | Test / data | Expected result | Actual output | Match or correction |
| :--- | :--- | :--- | :--- | :--- |
| **lottery.cpp** (partial match) | Fixed winning `[7,4,9,1,3]`; player `[4,2,9,7,3]` | 2 matches | Winning: 7 4 9 1 3, Player: 4 2 9 7 3, Matches: 2 | ✅ Match |
| **lottery.cpp** (all match) | Fixed winning `[7,4,9,1,3]`; player `[7,4,9,1,3]` | 5 matches | Winning: 7 4 9 1 3, Player: 7 4 9 1 3, Matches: 5 | ✅ Match |
| **lottery.cpp** (no match) | Fixed winning `[7,4,9,1,3]`; player `[0,0,0,0,0]` | 0 matches | Winning: 7 4 9 1 3, Player: 0 0 0 0 0, Matches: 0 | ✅ Match |
| **lottery.cpp** (repeated digits) | Fixed winning `[1,1,2,2,3]`; player `[1,2,2,3,3]` | 3 matches | Winning: 1 1 2 2 3, Player: 1 2 2 3 3, Matches: 3 | ✅ Match |
| **lottery.cpp** (extra fixed test: reversed order) | Fixed winning `[7,4,9,1,3]`; player `[3,1,9,4,7]` | 1 match | Winning: 7 4 9 1 3, Player: 3 1 9 4 7, Matches: 1 | ✅ Match |
| **lottery.cpp** (final random run) | Random winning `[2,8,4,0,6]`; player `[2,5,4,9,1]` | 2 matches (all winning digits 0-9; matches at indices 0 and 2) | Winning: 2 8 4 0 6, Player: 2 5 4 9 1, Matches: 2 | ✅ Match |

*Extra Fixed Test Explanation:* I tested player input `[3,1,9,4,7]` against the fixed winning array `[7,4,9,1,3]` to verify that even when the player enters all five winning digits in reverse order, the program only counts the single position where the indices actually align (index `2`, where both arrays hold `9`).

* Note: I temporarily replaced the random array generation with the fixed test arrays to verify exact match counts, and then restored the `rand() % 10` loop and completed a final compile and random test run before committing.*

## Code Explanations

**How does the random expression keep every digit between 0 and 9?**
The expression `rand() % 10` divides the random integer by `10` and returns only the remainder. Because the remainder of dividing any non-negative integer by `10` can only be `0, 1, 2, 3, 4, 5, 6, 7, 8,` or `9`, every generated element is guaranteed to stay within the inclusive `0` through `9` range.

**Why does a matching digit in another position not count?**
The comparison loop uses a single index variable `i` to check `if (winningDigits[i] == player[i])`. It only compares the element at index `i` in `winningDigits` directly against the element at the exact same index `i` in `player`, never checking across different indices.

**Trace the count through the example arrays.**
With `winningDigits` as `[7, 4, 9, 1, 3]` and `player` as `[4, 2, 9, 7, 3]`, `match_count` starts at `0`. At `i = 0`, `7 == 4` is false (`match_count` stays `0`). At `i = 1`, `4 == 2` is false (`match_count` stays `0`). At `i = 2`, `9 == 9` is true, so `match_count` increments to `1`. At `i = 3`, `1 == 7` is false (`match_count` stays `1`). At `i = 4`, `3 == 3` is true, so `match_count` increments to `2`, which is the final count after the loop finishes.

**Why do array loops stop before SIZE, and what did your fixed tests establish?**
C++ array indexing starts at `0`, meaning an array of size `5` has valid indices from `0` through `4` (`SIZE - 1`). Stopping the loop at `i < SIZE` prevents the program from accessing index `5`, which is out-of-bounds memory. My fixed tests established that the comparison loop accurately counts `0`, partial, repeated-digit, and full `5`-digit matches strictly by index before re-enabling random number generation.
