#include "Knight.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;
Knight::Knight(string nameInput)  { //Overloaded Constructor
  name = nameInput;
  playerType = "Knight";
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

void Knight::attackMenu()  { // Display class's ability
  cout << setfill('-') << setw(82) << "" << endl;
  cout <<"Please select your move:" << endl;
  cout << "1. Light Attack (+5 damage, -1 stamina)" << endl;
  cout << "2. Heavy Attack (+10 damage, -5 stamina)" << endl;
  cout << "3. Shield (negate 5-10 damage, -1 stamina)" << endl;
  cout << "4. Valor (+20 damage, +15 health)" << endl;
  cout << "5. Take Potion" << endl;
  cout << "6. Flee (result in Defeat)" << endl;
  cout << setfill('-') << setw(82) << "" << endl;
}

void Knight::printAllStat()  { //Display all stats
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

//Character's movesets
void Knight::move1(){ 
  cout << getName() << " is using light attack!" << endl;
  Stamina -= 1;
}

void Knight::move2(){
  cout << getName() << " is using heavy attack" << endl;
  Stamina -= 5;
}

void Knight::move3(){
  cout << getName() << " is blocking with their shield!" << endl;
  Stamina -= 1;
  Health += 10;
}

void Knight::move4(){
  cout << getName() << " activated Valor!" << endl;
  Health += 15;
}

void Knight::displayPlayer()  {
  if(name == "Opponent")  { //Display the Knight opponent
    cout << "Health: " << Health << "\t Stamina: " << Stamina << "\t Mana: " << Mana << endl;
    cout << "                      ▓▓██▓▓              " << endl;
    cout << "                  ██████▒▒████████        " << endl;
    cout << "                ▒▒░░░░▒▒░░▒▒▒▒▒▒▒▒▓▓      " << endl;
    cout << "              ░░▓▓░░░░░░░░▒▒▒▒░░▒▒▓▓░░    " << endl;
    cout << "              ██░░░░░░░░░░░░░░░░▒▒▒▒██    " << endl;
    cout << "              ██░░░░░░░░░░░░░░░░▒▒▒▒██    " << endl;
    cout << "              ██░░░░░░░░░░░░░░▒▒▒▒▒▒██    " << endl;
    cout << "              ██░░████████████░░▒▒▒▒██    " << endl;
    cout << "              ██░░████████████▒▒▒▒▒▒██    " << endl;
    cout << "              ██░░░░████████░░▒▒▒▒▒▒██    " << endl;
    cout << "              ██░░░░░░████░░▒▒▒▒▒▒▒▒██    " << endl;
    cout << "              ██░░░░░░████░░░░▒▒▒▒▒▒██    " << endl;
    cout << "              ████░░░░████░░▒▒▒▒▒▒████    " << endl;
    cout << "                  ████████████████████    " << endl;
    cout << "                ██▒▒▒▒▒▒▒▒▒▒▒▒██▓▓▓▓▓▓██  " << endl;
    cout << "            ████▒▒██▒▒▒▒▒▒▒▒██▓▓▓▓▓▓▓▓▓▓██" << endl;
    cout << "  ██████████▒▒██▒▒██▒▒▒▒▒▒▒▒██▓▓▓▓▓▓▓▓▓▓██" << endl;
    cout << "  ██░░░░░░░░▒▒██░░██▒▒▒▒▒▒▒▒██▓▓▓▓▓▓▓▓▓▓██" << endl;
    cout << "    ████████▒▒██████████████████▓▓▓▓▓▓██  " << endl;
    cout << "            ██    ██▒▒▒▒▒▒▒▒▒▒▒▒██████    " << endl;
    cout << "                  ██▒▒▒▒████▒▒▒▒██        " << endl;
    cout << "                  ██████    ██████        " << endl;
    
  }
  else  { // Display Knight player
      
    cout << "                ████                        ████                    " << endl;
    cout << "            ████░░░░██                    ██░░  ████                " << endl;
    cout << "          ██▒▒    ██                        ██░░    ██              " << endl;
    cout << "        ▓▓░░    ▓▓                            ▓▓░░    ██            " << endl;
    cout << "        ██░░    ██                            ██░░    ██            " << endl;
    cout << "        ██░░    ██                            ██░░░░  ██            " << endl;
    cout << "        ██░░░░  ░░██    ████████████████    ██░░░░░░  ██            " << endl;
    cout << "        ████░░░░  ░░██  ██▒▒▒▒          ██  ██░░░░░░░░██            " << endl;
    cout << "          ████░░░░░░██  ██▒▒▒▒▒▒          ░░██░░░░░░██              " << endl;
    cout << "            ██████████░░██▒▒▒▒▒▒          ██████████                " << endl;
    cout << "              ██████░░██▒▒██████████████  ████████                  " << endl;
    cout << "                  ████▓▓▒▒██████████████  ████                      " << endl;
    cout << "                    ██▒▒▒▒▒▒▒▒░░████▒▒░░  ██                        " << endl;
    cout << "                    ██▒▒▒▒▒▒    ████      ██                        " << endl;
    cout << "                    ██░░░░▒▒    ████      ██                        " << endl;
    cout << "            ██████████    ▒▒    ████      ██████                    " << endl;
    cout << "          ██  ▒▒    ▒▒██████████████████████▒▒▒▒██                  " << endl;
    cout << "          ██  ▒▒    ▒▒██▒▒▒▒████████████████▒▒  ██                  " << endl;
    cout << "          ████  ▒▒▒▒██    ██    ░░░░▒▒▒▒████████                    " << endl;
    cout << "      ▒▒████░░████████    ██    ░░░░▒▒▒▒████░░  ████████████        " << endl;
    cout << "      ▒▒████████████████▒▒▒▒██    ░░▒▒████████              ████    " << endl;
    cout << "      ▒▒██  ██░░    ████▒▒    ████  ██████████  ▒▒              ██  " << endl;
    cout << "  ██    ░░██░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████▒▒██                ██" << endl;
    cout << "    ▒▒██████░░██████████████████████████████  ████                ██" << endl;
    cout << "▒▒▒▒██      ██░░    ████▒▒▒▒██▒▒▒▒▒▒██▒▒████▒▒  ▒▒              ██  " << endl;
    cout << "████          ████  ██░░░░████  ░░████  ░░██    ▒▒          ████    " << endl;
    cout << "                  ██████████  ██████████████    ████████████        " << endl;
    cout << "                  ████░░██          ████  ██                        " << endl;
    cout << "                  ██████              ██████                        " << endl;
    cout << "                ██████                  ████                        " << endl;
    cout << "                ██▒▒▒▒                  ██▒▒▒▒                      " << endl;
  }
}