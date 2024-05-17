#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "pokemon.h"

using namespace std;


int getUserAttackChoice();

// Function to set cursor position
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// Create two Pokemon
Pokemon ally;
Pokemon enemy;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Initialize Pokemon
    ally.initializePokemon("Pikachu", 100, 20);
    enemy.initializePokemon("Charmander", 100, 15);


    // Display initial Pokemon stats
    ally.displayPokemon(ally, enemy);

    // Start the battle
    while (ally.hp > 0 && enemy.hp > 0) {
        // ally's turn
        int userChoice = getUserAttackChoice();
        int allyDamage;
        if (userChoice == 1) {
            allyDamage = ally.calculateDamage(ally.attack);
        }
        else if (userChoice == 2) {
            allyDamage = ally.calculateDamage(ally.attack * 2); // Double damage for special attack
        }
        else if (userChoice == 3) {
            cout << "You flee!" << endl;
        }

        enemy.hp -= allyDamage;
        cout << "_____________________________________________" << endl;
        cout << "You attacked the opponent for " << allyDamage << " damage." << endl;

        // Check if opponent fainted
        if (enemy.hp <= 0) {
            cout << "Opponent's Pokemon fainted! You win!" << endl;
            break;
        }

        // Opponent's turn
        int opponentDamage = enemy.calculateDamage(enemy.attack);
        ally.hp -= opponentDamage;
        cout << "Opponent attacked you for " << opponentDamage << " damage." << endl;

        // Check if ally fainted
        if (ally.hp <= 0) {
            cout << "Your Pokemon fainted! You lose!" << endl;
            break;
        }


        // Pause before next round
        cout << "\nPress Enter to continue...";
        cin.ignore();
    }

    return 0;
}




// Function to get user's attack choice using arrow keys
int getUserAttackChoice() {
    int choice = 1; // Default choice
    int key;
    bool selected = false;
    while (!selected) {
        system("cls"); // Clear screen
        
        ally.displayPokemon(ally, enemy);


        cout << "Choose your attack:" << endl;
        // Highlight the selected choice
        if (choice == 1) {
            cout << "-> Normal Attack" << endl;
            cout << "   Special Attack (Double Damage)" << endl;
            cout << "   Run" << endl;
        }
        else if (choice == 2) {
            cout << "   Normal Attack" << endl;
            cout << "-> Special Attack (Double Damage)" << endl;
            cout << "   Run" << endl;
        }
        else if (choice == 3) {
            cout << "   Normal Attack" << endl;
            cout << "   Special Attack (Double Damage)" << endl;
            cout << "-> Run"<< endl;
        }
        // Wait for arrow key input
        key = _getch();
        switch (key) {
        case 72: // Up arrow key
            if (choice > 1)
                choice--;
            break;
        case 80: // Down arrow key
            if (choice < 3)
                choice++;
            break;
        case 13: // Enter key
            selected = true;
            break;
        }
    }
    return choice;
}
