#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "pokemon.h"
#include "chance.h"

using namespace std;

int getUserAttackChoice();

// Create two Pokemon
Pokemon ally;
Pokemon enemy;

int main() {
    // Seed the random number generator
    srand((unsigned)time(NULL));

    // Initialize Pokemon
    ally.initializePokemon("Pikachu", 100, 20);
    enemy.initializePokemon("Charmander", 100, 22);

    // Display initial Pokemon stats
    ally.displayPokemon(ally, enemy);

    // Start the battle
    while (ally.hp > 0 && enemy.hp > 0) {
        // ally's turn
        int userChoice = getUserAttackChoice();
        int allyDamage = 0;
        int opponentDamage = enemy.calculateDamage(enemy.attack);

        int enemyDodge = randomInRange(0, 20);
        if (enemyDodge > 10)
            enemy.isDodging = true;
        else
            enemy.isDodging = false;

        if (userChoice == 1) {
            allyDamage = ally.calculateDamage(ally.attack);
            if (enemy.isDodging == false) {
                enemy -= allyDamage;
                ally -= opponentDamage;
            }
        }
        else if (userChoice == 2) {
            allyDamage = ally.calculateDamage(ally.attack * 2); // Double damage for special attack
            if (enemy.isDodging == false) {
                enemy -= allyDamage;
                ally -= opponentDamage;
            }
        }
        else if (userChoice == 3) {
            ally.catchPokemon(enemy);
            if (enemy.isCaptured == true) {
                cout << "\nPress Enter to exit...";
                cin.ignore();
                break;
            }
        }
        else if (userChoice == 4) {
            cout << "You flee!" << endl;
            cout << "\nPress Enter to exit...";
            cin.ignore();
            break;
        }
        
        cout << "_____________________________________________" << endl;
        cout << "You attacked the opponent for " << allyDamage << " damage." << endl;


        // Check if opponent fainted
        if (enemy.hp <= 0) {
            cout << "Opponent's Pokemon fainted! You win!" << endl;
            break;
        }
        // Opponent's turn
        if(enemy.isDodging == false)
            cout << enemy.name <<  " attacked you for " << opponentDamage << " damage." << endl;
        else
            cout << enemy.name << " dodged " << ally.name << "'s attack!" << endl;


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
            cout << "   Catch " << "(" << enemy.winRate_catch() * 100 << "% Success Rate)" << endl;
            cout << "   Run" << endl;
        }
        else if (choice == 2) {
            cout << "   Normal Attack" << endl;
            cout << "-> Special Attack (Double Damage)" << endl;
            cout << "   Catch " << "(" << enemy.winRate_catch() * 100 << "% Success Rate)" << endl;
            cout << "   Run" << endl;
        }
        else if (choice == 3) {
            cout << "   Normal Attack" << endl;
            cout << "   Special Attack (Double Damage)" << endl;
            cout << "-> Catch " << "(" << enemy.winRate_catch() * 100 << "% Success Rate)" << endl;
            cout << "   Run" << endl;
        }
        else if (choice == 4) {
            cout << "   Normal Attack" << endl;
            cout << "   Special Attack (Double Damage)" << endl;
            cout << "   Catch " << "(" << enemy.winRate_catch() * 100 << "% Success Rate)" << endl;
            cout << "-> Run" << endl;
        }
        // Wait for arrow key input
        key = _getch();
        switch (key) {
        case 72: // Up arrow key
            if (choice > 1)
                choice--;
            break;
        case 80: // Down arrow key
            if (choice < 4)
                choice++;
            break;
        case 13: // Enter key
            selected = true;
            break;
        }
    }
    return choice;
}