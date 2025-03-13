#include "Mage.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;
Mage::Mage(string nameInput)  { //Overloaded Constructor
  name = nameInput;
  playerType = "Mage";
  Level = 0;
  expCount = 0;
  MAX_EXP = 100 + (Level * 50);
  Health = 100 + (Level * 5) + (Vitality * 5);
  Stamina = 100 + (Level * 5) + (Endurance * 5);
  Mana = 100 + (Level * 5) + (Willpower * 5);
  Vitality = 0;
  Endurance = 0;
  Willpower = 0;
  Strength = 0;
  skillPoints = 0;
  numPotions = 2;
}

void Mage::attackMenu(){ // Display class's ability
  cout << setfill('-') << setw(82) << "" << endl;
  cout <<"Please select your move:" << endl;
  cout << "1. Basic Magic (+5 damage, -1 mana)" << endl;
  cout << "2. Expert Magic (+10 damage, -5 mana)" << endl;
  cout << "3. Cast Bubble (negate 5-10 damage, -1 mana)" << endl;
  cout << "4. Complex Magic (+20 damage, +15 mana)" << endl;
  cout << "5. Take Potion" << endl;
  cout << "6. Flee (result in Defeat)" << endl;
  cout << setfill('-') << setw(82) << "" << endl;
}

void Mage::printAllStat()  { //Display all stats
  cout << "Name: " << getName() << endl;
  cout << "Level: " << Level << endl;
  cout << "Exp: " << expCount << "/" << MAX_EXP << endl;
  cout << "Health: " << Health << endl;
  cout << "Stamina: " << Stamina << endl;
  cout << "Mana: " << Mana << endl;
  cout << "Vitality: " << Vitality << endl;
  cout << "Endurance: " << Endurance << endl;
  cout << "Willpower: " << Willpower << endl;
  cout << "Strength: " << Strength << endl;
  cout << "Skill point(s): " << skillPoints << endl;
  if(skillPoints > 0)  {
    char input;
    cout << "Would you like upgrade your attribute? (y/n)" << endl;
    cin >> input;
    if(!isalpha(input)){
      cout << "Please enter a letter (y/n) " << endl;
      cin >> input;
    }
    else if(isalpha(input) && input == 'y'){
      useSP();
    }
    else if(isalpha(input) && input == 'n'){
      cout << "Saving your skill point(s)..." << endl;
    }
    else  {
      cout << "Please enter (y) or (n)" << endl;
      cin >> input;
    }
  }
}

//Mage's movesets
void Mage::move1(){
  cout << getName() << " is using basic magic!" << endl;
  Mana -= 1;
}

void Mage::move2(){
  cout << getName() << " is using expert magic!" << endl;
  Mana -= 5;
}

void Mage::move3(){
  cout << getName() << " is casting a protective bubble!" << endl;
  Health += 10;
  Mana -= 1;
}

void Mage::move4(){
  cout << getName() << " is conjuring a storm!" << endl;
  Mana += 15;
}

void Mage::displayPlayer(){
  if(name == "Opponent")  { //Display Mage opponent
    cout << "Health: " << Health << "\t Stamina: " << Stamina << "\t Mana: " << Mana << endl;
    cout << "                                       ██                          " << endl;
    cout << "                                       ██                          " << endl;
    cout << "                                     ████                          " << endl;
    cout << "                                  ▒▒▓▓▓▓▓▓                         " << endl;
    cout << "                                  ▓▓▒▒▒▒██                         " << endl;
    cout << "                                  ▓▓▓▓▒▒░░▓▓                       " << endl;
    cout << "                                   ▓▓▓▓▓▓▓▓██                      " << endl;
    cout << "                              ░░▒▒▒▒░░▓▓▓▓▓▓▓▓                     " << endl;
    cout << "          ░░                  ░░▓▓▓▓▒▒▓▓░░▓▓▒▒                     " << endl;
    cout << "                        ▒▒▒▒██▓▓▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒░░▒▒▒▒             " << endl;
    cout << "       ░░          ██▓▓▓▓████████████▓▓████▓▓▓▓▓▓▓▓▒▒██▓▓▓▓        " << endl;
    cout << "      ░░  ▒▒░░░░            ██░░    ░░░░░░░░░░▓▓░░                 " << endl;
    cout << "        ▒▒░░░░              ██▓▓    ▒▒▓▓▓▓▓▓▓▓██                   " << endl;
    cout << "▒▒  ▒▒░░  ▒▒░░░░▒▒  ▒▒      ██████▒▒░░██████▒▒▒▒                   " << endl;
    cout << "        ▒▒░░░░            ▓▓░░░░░░░░░░░░░░░░░░▒▒▓▓                 " << endl;
    cout << "       ░░  ▒▒░░░░         ██  ▓▓▒▒▒▒  ██  ░░░░░░▓▓                 " << endl;
    cout << "       ░░      ░░         ██░░░░██▒▒  ░░░░░░░░▓▓██                 " << endl;
    cout << "        ██▒▒██░░          ██░░░░▒▒▒▒  ░░░░░░  ▒▒        ██████████ " << endl;
    cout << "          ▓▓██            ██  ░░▒▒▒▒░░░░░░░░  ██        ██░░░░░░██ " << endl;
    cout << "         ██▒▒████         ██    ▒▒████░░      ░░░░      ██▓▓    ▓▓ " << endl;
    cout << "         ██▒▒████         ██    ▒▒████░░      ░░░░      ██▓▓    ▓▓ " << endl;
    cout << "         ██    ▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓                ▓▓▓▓██░░░░░░▓▓    ▓▓ " << endl;
    cout << "        ░░░░  ▒▒▒▒██▓▓▒▒▒▒▓▓██  ░░▒▒▒▒      ▓▓▓▓▓▓▓▓▓▓░░▓▓      ▓▓ " << endl;
    cout << "         ▓▓██▓▓▒▒░░██▓▓▓▓▒▒▒▒▓▓▒▒          ▓▓▓▓▓▓▒▒▓▓██░░  ▓▓    ▓▓ " << endl;
    cout << "           ░░██▓▓▓▓░░██▓▓▒▒▒▒▓▓▓▓    ░░░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒██ " << endl;
    cout << "             ██░░      ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░▒▒▓▓████▓▓          " << endl;
    cout << "             ██░░        ██▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓▒▒░░▒▒▓▓░░              " << endl;
    cout << "             ██░░        ██▓▓░░░░▒▒▒▒▒▒▓▓▒▒▒▒░░▓▓░░                " << endl;
    cout << "             ░░░░      ██▓▓▓▓▓▓░░▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓░░                " << endl;
    cout << "             ░░▓▓      ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░▓▓▓▓▓▓▓▓                " << endl;
    cout << "             ░░▓▓    ██▓▓▒▒▓▓▒▒▒▒▒▒▓▓▓▓░░░░░░▓▓▓▓▓▓██              " << endl;
    cout << "                     ██▓▓▓▓▓▓▒▒░░░░▒▒▓▓▒▒░░▒▒▒▒▓▓▓▓██              " << endl;
    cout << "                  ██▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓██            " << endl;
    cout << "               ░░▒▒██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▒▒          " << endl;
    cout << "                  ░░  ░░░░░░░░░░░░░░░░  ░░░░░░░░░░░░░░░░            " << endl;
  }
    
  else  { // Display Mage player
    cout << "             ░░▓▓▒▒                              " << endl;
    cout << "               ▒▒▒▒▒▒▒▒                        ░░       " << endl;
    cout << "               ░░  ▒▒▒▒▒▒                      ▒▒       " << endl;
    cout << "                 ▓▓▒▒▒▒▒▒░░                  ░░▒▒        " << endl;
    cout << "                 ▒▒▒▒▒▒▒▒  ░░                ░░░░            " << endl;
    cout << "                 ░░▒▒▒▒▒▒▓▓▓▓                ▒▒░░       " << endl;
    cout << "                 ██▒▒▒▒▒▒▒▒▒▒▒▒              ▒▒         " << endl;
    cout << "           ░░  ▓▓██  ▒▒▒▒▒▒▒▒▓▓▒▒████▒▒  ░░░░▒▒░░      " << endl;
    cout << " ░░░░░░░░░░  ▒▒▓▓██▓▓▒▒▒▒▒▒▒▒▓▓████████▒▒░░  ▒▒░░       " << endl;
    cout << " ░░░░░░      ░░  ██▓▓▓▓▓▓▓▓▓▓▓▓████████▓▓░░░░  ░░       " << endl;
    cout << "          ░░░░  ▓▓▓▓▓▓▒▒░░████▓▓██████▒▒    ░░  ░░    " << endl;
    cout << "        ░░░░░░▓▓▓▓░░░░    ░░████▓▓▓▓▓▓▓▓  ░░  ░░░░  ░░" << endl;
    cout << "        ░░██▒▒▓▓██░░░░░░    ████▓▓    ░░  ░░░░  ░░▒▒▒▒ " << endl;
    cout << "          ▒▒▒▒▓▓▓▓░░▒▒      ▓▓▒▒▓▓  ▒▒▓▓░░░░░░▒▒▒▒▒▒░░ " << endl;
    cout << "          ▒▒▒▒▒▒▓▓░░▒▒▒▒    ░░░░▓▓▒▒▓▓▓▓▓▓▓▓▒▒▒▒░░    " << endl;
    cout << "        ░░▒▒▒▒▒▒▒▒████      ░░  ▓▓▒▒▓▓▒▒▒▒░░░░        " << endl;
    cout << "        ░░▒▒▒▒▒▒▒▒▒▒░░        ▒▒▒▒▒▒▒▒▒▒▒▒            " << endl;
    cout << "        ░░▒▒▒▒▒▒▒▒▓▓▒▒░░▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒            " << endl;
    cout << "        ░░▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░             " << endl;
    cout << "           ▓▓▓▓▒▒▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▓▓▒▒░░             " << endl;
    cout << "             ░░▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░            " << endl;
    cout << "             ▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒░░░░░░░░▒▒▒▒              " << endl;
    cout << "             ▒▒▓▓▓▓▒▒▒▒▒▒░░                             " << endl;
    cout << "             ▒▒▓▓▓▓▒▒▒▒▒▒░░                            " << endl;
    cout << "             ▒▒▓▓▓▓▒▒▒▒▒▒░░                             " << endl;
    cout << "             ▒▒▓▓▓▓▒▒▒▒▒▒▒▒                             " << endl;
    cout << "             ░░▓▓██▒▒▒▒▒▒▒▒░░                          " << endl;
    cout << "             ░░▒▒▓▓▓▓▓▓▒▒▒▒▒▒░░                         " << endl;
    cout << "       ░░▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒░░                " << endl;
    cout << "     ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░             " << endl;
    cout << "     ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒           " << endl;
    cout << "         ░░▒▒▒▒▒▒░░░░  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░         " << endl;
    cout << "                          ▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒          " << endl;
    cout << "                            ▒▒▓▓▒▒▒▒▒▒░░                " << endl;
  }
}