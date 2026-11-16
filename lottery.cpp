/******************************************************************************
Made in OnlineGDB by C.J. Merendino
Lab 8 - Program 1 - Lottery Simulation
This program simulates a five-digit lottery by generating random winning digits, reading five player digits, and counting matching digits in corresponding positions.
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int SIZE = 5;
    int winningDigits[SIZE];
    int player[SIZE];
    int match_count = 0;

    // Seed
    srand(time(0));

    // Populate winningDigits with random digits from 0 through 9
    for (int i = 0; i < SIZE; i++) {
        winningDigits[i] = rand() % 10;
    }
    
    
    // Prompt user for five digits and store them in the player array
    cout << "Enter 5 lottery digits (0 through 9), separated by spaces: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> player[i];
    }

    // Compare corresponding positions only to count exact matches
    for (int i = 0; i < SIZE; i++) {
        if (winningDigits[i] == player[i]) {
            match_count++;
        }
    }

    // Display all five winning digits
    cout << "Winning digits: ";
    for (int i = 0; i < SIZE; i++) {
        cout << winningDigits[i] << " ";
    }
    cout << endl;

    // Display all five player digits
    cout << "Player digits:  ";
    for (int i = 0; i < SIZE; i++) {
        cout << player[i] << " ";
    }
    cout << endl;

    // Display total match count
    cout << "Matching digits: " << match_count << endl;

    return 0;
}