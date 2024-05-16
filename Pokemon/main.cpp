#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

// Define a struct for a Pokemon
struct Pokemon {
    string name;
    int hp;
    int attack;
};

// Function prototypes
void initializePokemon(Pokemon& pokemon, string name, int hp, int attack);
void displayPokemon(const Pokemon& pokemon);
int calculateDamage(int attack);
int getUserAttackChoice();

// Function to set cursor position
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// Create two Pokemon
Pokemon playerPokemon;
Pokemon opponentPokemon;
int main() {
    // Seed the random number generator
    srand(time(0));



    // Initialize Pokemon
    initializePokemon(playerPokemon, "Pikachu", 100, 20);
    initializePokemon(opponentPokemon, "Charmander", 100, 15);

    // Display initial Pokemon stats
    cout << "Your Pokemon:" << endl;
    displayPokemon(playerPokemon);
    cout << "\nOpponent's Pokemon:" << endl;
    displayPokemon(opponentPokemon);

    // Start the battle
    while (playerPokemon.hp > 0 && opponentPokemon.hp > 0) {
        // Player's turn
        int userChoice = getUserAttackChoice();
        int playerDamage;
        if (userChoice == 1) {
            playerDamage = calculateDamage(playerPokemon.attack);
        }
        else {
            playerDamage = calculateDamage(playerPokemon.attack * 2); // Double damage for special attack
        }
        opponentPokemon.hp -= playerDamage;
        cout << "You attacked the opponent for " << playerDamage << " damage." << endl;

        // Check if opponent fainted
        if (opponentPokemon.hp <= 0) {
            cout << "Opponent's Pokemon fainted! You win!" << endl;
            break;
        }

        // Opponent's turn
        int opponentDamage = calculateDamage(opponentPokemon.attack);
        playerPokemon.hp -= opponentDamage;
        cout << "Opponent attacked you for " << opponentDamage << " damage." << endl;

        // Check if player fainted
        if (playerPokemon.hp <= 0) {
            cout << "Your Pokemon fainted! You lose!" << endl;
            break;
        }

        // Display updated Pokemon stats
        cout << "\nYour Pokemon:" << endl;
        displayPokemon(playerPokemon);
        cout << "\nOpponent's Pokemon:" << endl;
        displayPokemon(opponentPokemon);

        // Pause before next round
        cout << "\nPress Enter to continue...";
        cin.ignore();
    }

    return 0;
}

// Function to initialize a Pokemon
void initializePokemon(Pokemon& pokemon, string name, int hp, int attack) {
    pokemon.name = name;
    pokemon.hp = hp;
    pokemon.attack = attack;
}

// Function to display Pokemon stats
void displayPokemon(const Pokemon& pokemon) {
    cout << "Name: " << pokemon.name << endl;
    cout << "HP: " << pokemon.hp << endl;
    cout << "Attack: " << pokemon.attack << endl;
}

// Function to calculate damage
int calculateDamage(int attack) {
    // Generate a random number between 1 and attack
    return rand() % attack + 1;
}

// Function to get user's attack choice using arrow keys
int getUserAttackChoice() {
    int choice = 1; // Default choice
    int key;
    bool selected = false;
    while (!selected) {
        system("cls"); // Clear screen
        
        displayPokemon(playerPokemon);
        cout << endl;
        displayPokemon(opponentPokemon);
        cout << endl;


        cout << "Choose your attack:" << endl;
        // Highlight the selected choice
        if (choice == 1) {
            cout << "-> Normal Attack" << endl;
            cout << "   Special Attack (Double Damage)" << endl;
        }
        else {
            cout << "   Normal Attack" << endl;
            cout << "-> Special Attack (Double Damage)" << endl;
        }
        // Wait for arrow key input
        key = _getch();
        switch (key) {
        case 72: // Up arrow key
            if (choice > 1)
                choice--;
            break;
        case 80: // Down arrow key
            if (choice < 2)
                choice++;
            break;
        case 13: // Enter key
            selected = true;
            break;
        }
    }
    return choice;
}
