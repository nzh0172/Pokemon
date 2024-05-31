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
    winRate = 0;
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
double Pokemon::winRate_catch(Pokemon& enemy) {
    if (enemy.hp <= 100 && enemy.hp > 80) {
        winRate = 0.2;
    }
    else if (enemy.hp < 80 && enemy.hp > 40) {
        winRate = 0.5;
    }
    else if (enemy.hp < 40 && enemy.hp >= 0) {
        winRate = 0.8;
    }
    return winRate; //0 if fail, 1 if successful
}

int Pokemon::calculateDamage(int attack) {
    return rand() % attack + 1;
}
void Pokemon::catchPokemon(Pokemon &enemy)
{
    cout << "winrate: " << winRate_catch(enemy) << endl;
    double success = randomInRange(0, 5);
    cout << success << endl;
    if (winRate_catch(enemy) <= 0.5 && success < 2) {
        cout << "Pokemon has been captured!" << endl;
        enemy.isCaptured = true;
    }
    //gives guaranteed catch
    else if (winRate_catch(enemy) >= 0.8 && success >= 3 && success <= 5 ) {
        cout << "Pokemon has been captured!" << endl;
        enemy.isCaptured = true;
    }
    else {
        cout << "Pokemon has escaped from Pokeball!" << endl;
        enemy.isCaptured = false;
    }
}
void Pokemon::operator -=(int damage) {
    hp -= damage;
    if (hp < 0)
        hp = 0;
}

