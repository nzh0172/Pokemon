#include "pokemon.h"
#include "chance.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

Pokemon::Pokemon()
{
    name = "test";
    hp = 0;
    attack = 0;
    isCaptured = false;
}

void Pokemon::initializePokemon(std::string pname, int php, int pattack) {
    name = pname;
    hp = php;
    attack = pattack;
}
void Pokemon::displayPokemon(Pokemon ally, Pokemon enemy) {
    cout << "Your Pokemon\t\tOpponent's Pokemon" << endl;
    cout << "Name: " << ally.name << "\t\tName:" << enemy.name << endl;
    cout << "HP: " << ally.hp << "\t\t\tHP:" << enemy.hp << endl;
    cout << "Attack: " << ally.attack << "\t\tAttack:" << enemy.attack << endl;
    cout << "_____________________________________________" << endl;
}
double Pokemon::winRate_catch() {
    double winRate;
    Pokemon enemy;
    if (enemy.hp < 100 && enemy.hp > 80) {
        winRate = 0.3;
        return winRate * (double)randomInRange(0, 1);
    }
    else if (enemy.hp < 80 && enemy.hp > 40) {
        winRate = 0.5;
        return winRate * (double)randomInRange(0, 1);
    }
    else if (enemy.hp < 40 && enemy.hp > 0) {
        winRate = 0.8;
        return winRate;
    }
    
}

int Pokemon::calculateDamage(int attack) {
    return rand() % attack + 1;
}
void Pokemon::catchPokemon(Pokemon enemy)
{
    if (enemy.winRate_catch() != 0) {
        cout << enemy.winRate_catch() << endl;
        cout << "Pokemon has been captured!" << endl;
    }
    else {
        cout << "Pokemon has escaped from Pokeball!" << endl;
    }
}
int Pokemon::getHP() {
    return hp;
}
int Pokemon::getAttack() {
    return attack;
}

