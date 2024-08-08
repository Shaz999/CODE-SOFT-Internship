#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int randomNumber = rand() % 100 + 1; 
    int userGuess = 0;

    cout << "Guess the number (between 1 and 100): ";

    while (true) {
        cin >> userGuess;

        if (userGuess > randomNumber) {
            cout << "Too high! Try again: ";
        } else if (userGuess < randomNumber) {
            cout << "Too low! Try again: ";
        } else {
            cout << "Congratulations! You guessed it!" << endl;
            break; 
        }
    }

    return 0;
}
