#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <string>

// Define a struct for a Pokemon
class Pokemon {
public:
    std::string name; //need to put std::, using namespace std is bad practice idk
    int hp;
    int attack;
    bool isCaptured;
    bool isDodging;
    double winRate;

    Pokemon();

    void initializePokemon(std::string pname, int php, int pattack);
    void displayPokemon(Pokemon ally, Pokemon enemy);
    double winRate_catch();
    int calculateDamage(int attack);

    void catchPokemon(Pokemon &enemy);
    void operator -= (int damage);


};
