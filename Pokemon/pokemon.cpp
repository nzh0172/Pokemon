#include "pokemon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;

Pokemon::Pokemon()
{
    name = "test";
    hp = 0;
    attack = 0;
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
int Pokemon::calculateDamage(int attack) {
    return rand() % attack + 1;
}
int Pokemon::getHP() {
    return hp;
}
int Pokemon::getAttack() {
    return attack;
}

