#include "Rogue.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;
Rogue::Rogue(string nameInput)  { //Overloaded Constructor
  name = nameInput;
  playerType = "Rogue";
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

void Rogue::attackMenu(){ //Display class's ability
  cout << setfill('-') << setw(82) << "" << endl;
  cout <<"Please select your move:" << endl;
  cout << "1. Sneak Attack (+5 damage, -1 stamina)" << endl;
  cout << "2. Heavy Slash (+10 damage, -5 stamina)" << endl;
  cout << "3. Evade (negate 5-10 damage, -1 stamina)" << endl;
  cout << "4. Playing Dirty (+20 damage, +10 health & +5 Stamina)" << endl;
  cout << "5. Take Potion" << endl;
  cout << "6. Flee (result in Defeat)" << endl;
  cout << setfill('-') << setw(82) << "" << endl;
}

void Rogue::printAllStat()  { //Display all stats
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

//Rogue's movesets
void Rogue::move1()  {
  cout << getName() << " is using sneak attack!" << endl;
  Stamina -= 1;
}

void Rogue::move2(){
  cout << getName() << " is using heavy slash!" << endl;
  Stamina -= 5;
}

void Rogue::move3(){
  cout << getName() << " is using evade!" << endl;
  Stamina -= 1;
  Health += 10;
}

void Rogue::move4(){
  cout << getName() << " gain an advantage!" << endl;
  Health += 10;
  Stamina += 5;
}

void Rogue::displayPlayer()  {
  if(name == "Opponent")  { //Display Rogue opponent (i couldnt figure a good assassin art)
    cout << "Health: " << Health << "\t Stamina: " << Stamina << "\t Mana: " << Mana << endl;
    cout << "                            ░░    ░░░░░░    ░░░░        " << endl;
    cout << "                            ░░  ▓▓▓▓▒▒▓▓▒▒  ░░          " << endl;
    cout << "                              ░░██▓▓▒▒▓▓▓▓              " << endl;
    cout << "                              ░░▓▓▓▓░░▓▓▓▓░░            " << endl;
    cout << "                      ░░      ██▓▓▒▒░░▒▒▓▓██           " << endl;
    cout << "                      ▒▒▒▒▒▒▒▒▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▒▒░░░░    " << endl;
    cout << "                      ░░░░░░░░██▓▓▒▒▒▒▒▒▒▒▓▓░░░░░░░░    " << endl;
    cout << "                        ░░░░▒▒▓▓  ▒▒  ▒▒▒▒▒▒▒▒░░░░      " << endl;
    cout << "                            ▓▓▓▓          ▓▓▓▓          " << endl;
    cout << "                          ░░▓▓▓▓██████▓▓▓▓▓▓▓▓▒▒        " << endl;
    cout << "                          ▓▓▓▓░░▓▓  ░░░░░░  ▓▓▓▓        " << endl;
    cout << "                              ▓▓▒▒░░  ▒▒▒▒▒▒            " << endl;
    cout << "                            ▓▓▓▓▒▒▒▒▓▓▒▒▓▓▓▓▓▓▒▒        " << endl;
    cout << "                          ▓▓▓▓▒▒▓▓▓▓▒▒▓▓▓▓▒▒▓▓▓▓▒▒      " << endl;
    cout << "                      ░░▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▒▒██▒▒▓▓░░      " << endl;
    cout << "                    ▒▒▓▓▓▓██▓▓▒▒░░░░░░░░░░████▒▒▓▓      " << endl;
    cout << "                    ▓▓████▓▓██░░░░▒▒▒▒░░░░████▓▓▓▓▒▒    " << endl;
    cout << "                ░░▓▓▓▓██▓▓██░░▓▓▒▒▒▒▒▒▒▒▒▒▓▓██▓▓▓▓▓▓    " << endl;
    cout << "                ▒▒▒▒▓▓      ▓▓▓▓▓▓▒▒▓▓▒▒▓▓▓▓████▓▓██    " << endl;
    cout << "                ░░▒▒      ▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░    " << endl;
    cout << "            ░░▒▒          ▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓░░░░░░    " << endl;
    cout << "          ░░░░          ▒▒████████████████▓▓██▓▓        " << endl;
    cout << "        ▒▒░░            ██████████████████▓▓▓▓██░░      " << endl;
    cout << "      ▒▒░░              ▓▓██████████████████▓▓████      " << endl;
    cout << "  ░░░░░░                ▓▓▓▓██████████▓▓████▓▓▓▓██      " << endl;
    cout << "░░░░░░                ░░████▓▓██▓▓██▓▓▓▓██████▓▓▓▓▒▒    " << endl;
    cout << "▒▒░░                  ░░▓▓▓▓▓▓██████░░▓▓██████▓▓▓▓▓▓    " << endl;
    cout << "                        ▓▓▓▓▓▓██▓▓▓▓  ▒▒▓▓████▓▓▓▓▓▓    " << endl;
    cout << "                        ▒▒▓▓▓▓▓▓▓▓      ░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓" << endl;
    cout << "                      ▓▓▓▓▓▓▓▓▓▓            ░░▒▒▒▒▒▒░░  " << endl;
    cout << "██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▓▓▒▒▒▒░░▒▒▒▒▒▒████▒▒▒▒████▒▒▒▒" << endl;
    cout << "██▓▓▓▓▓▓▒▒▒▒▓▓██████████████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓██" << endl;
    cout << "████████████████████████████████████████████████████████" << endl;
  }

  else  { //Display Rogue player
    cout << "                      ░░                   " << endl;
    cout << "                    ▒▒▓▓      ░░            " << endl;
    cout << "                  ░░▓▓░░                     " << endl;
    cout << "                  ▒▒▓▓▓▓    ░░               " << endl;
    cout << "                  ▓▓▓▓██  ░░                 " << endl;
    cout << "                ▒▒██████░░                  " << endl;
    cout << "                ▒▒▒▒▓▓▒▒██░░                  " << endl;
    cout << "              ▒▒▒▒░░░░▓▓▓▓▓▓                   " << endl;
    cout << "            ░░▓▓▓▓▓▓▓▓▓▓██▒▒▓▓                 " << endl;
    cout << "            ▒▒██▓▓▒▒▓▓▓▓▓▓██▓▓▓▓                " << endl;
    cout << "        ░░▒▒████▒▒▓▓▓▓██▒▒▓▓▓▓▓▓▒▒             " << endl;
    cout << "        ░░▓▓██▓▓▓▓▓▓▓▓██████▓▓▒▒            " << endl;
    cout << "          ░░▒▒██▓▓▒▒▓▓▓▓▓▓██▒▒▓▓             " << endl;
    cout << "          ▒▒▓▓▒▒▓▓▓▓██████▓▓████           " << endl;
    cout << "          ░░██▓▓▓▓██████████▓▓██           " << endl;
    cout << "            ▓▓▓▓██████████▓▓████▓▓▒▒       " << endl;
    cout << "          ░░▓▓▓▓██████████████████            " << endl;
    cout << "          ▓▓▒▒██████████████▓▓████            " << endl;
    cout << "          ▓▓░░▓▓████████████▓▓████▒▒           " << endl;
    cout << "        ░░▓▓▒▒██████████████▓▓██████          " << endl;
    cout << "        ▒▒▓▓▓▓██████████▓▓████████████        " << endl;
    cout << "        ████▓▓████████████████████████▒▒      " << endl;
    cout << "        ████████████████░░██▓▓██▒▒▒▒████        " << endl;
    cout << "      ░░▓▓▓▓▓▓░░      ░░  ▓▓██                  " << endl;
    cout << "          ▒▒██            ▒▒██░░            " << endl;
    cout << "          ▓▓██            ░░▓▓░░              " << endl;
    cout << "          ██▓▓              ▓▓██             " << endl;
    cout << "        ░░██                                  " << endl;
  }
  
}