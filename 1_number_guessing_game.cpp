#include <iostream>
#include <cstdlib>


#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    int randomNumber = rand() % 100 + 1; 
    int userGuess = 0;

    std::cout << "Guess the number (between 1 and 100): ";

    while (userGuess != randomNumber) {
        cin >> userGuess;
        
        if (userGuess > randomNumber) {
            cout << "Too high! Try again: ";
        } else if (userGuess < randomNumber) {
          cout << "Too low! Try again: ";
        } else {
            cout << "Congratulations! You guessed it!" <<endl;
        }
    }

    return 0;
}
