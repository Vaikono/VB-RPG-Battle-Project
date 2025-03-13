#include "Character.h"
#include "Knight.h"
#include "Mage.h"
#include "Rogue.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

//Character's functionality

Character::Character()  { //Default Constructor
  Level = 0;
  expCount = 0;
  MAX_EXP = 100 + (Level * 50);
  Health = 100 + (Level * 5);
  Stamina = 100 + (Level * 5);
  Mana = 100 + (Level * 5);
}

void Character::setName(string input)  { // Set Name
  name = input;
}

string Character::getName()  { // Return name
  return name;
}

void Character::takeDamage(int num)  { // Deal damage to the character affected
  Health -= num;
}

int Character::getHealth()  { // Return character's health
  return Health;
}

int Character::getPotion()  { // Return the number of potions
  return numPotions;
}


void Character::takePotion()  { // The function for the character to use a potion
  int pChoice;
  int MAX_HEALTH = 100 + (Level * 50);
  int MAX_STAMINA = 100 + (Level * 50);
  int MAX_MANA = 100 + (Level * 50);
  
  cout << "What would you like to restore?" << endl;
  cout << "1. Health" << endl;
  cout << "2. Stamina" << endl;
  cout << "3. Willpower" << endl;
  cin >> pChoice;
  if(pChoice == 1){
    if(Health == MAX_HEALTH)  {
      cout << "Character is already at full health!" << endl;
    }
    else if(Health + 50 > MAX_HEALTH)  {
        int leftover;
        leftover = (Health + 50) - MAX_HEALTH;
        Health += leftover;
        cout << "Health restored!" << endl;
      }
    else if(Health + 50 < MAX_HEALTH){
      Health += 50;
      cout << "Health restored!" << endl;
    }
  }
  
  else if(pChoice == 2){
    if(Stamina == MAX_STAMINA)  {
      cout << "Character is already at full stamina!" << endl;
    }
    else if(Stamina + 50 > MAX_STAMINA)  {
        int leftover;
        leftover = (Stamina + 50) - MAX_STAMINA;
        Stamina += leftover;
        cout << "Stamina restored!" << endl;
      }
    else if(Stamina + 50 < MAX_STAMINA){
      Stamina += 50;
      cout << "Stamina restored!" << endl;
    }
  }

  else if(pChoice == 3){
    if(Mana == MAX_MANA)  {
      cout << "Character is already at full Mana!" << endl;
    }
    else if(Mana + 50 > MAX_MANA)  {
        int leftover;
        leftover = (Mana + 50) - MAX_MANA;
        Mana += leftover;
        cout << "Mana restored!" << endl;
    }
    else if(Mana + 50 < MAX_MANA){
      Mana += 50;
      cout << "Mana restored!" << endl;
    }
  }

  else  {
    cout << "Select the option to use your potion on" << endl;
    cin >> pChoice;
    }
}


void Character::Restore()  { // Restore the character's stats
  Health = 100 + (Level * 5);
  Stamina = 50 + (Level * 5);
  Mana = 50 + (Level * 5);
  numPotions = 2;
}

void Character::printStatus()  { // Print the status of the character
  cout << setfill('-') << setw(82) << "" << endl;
  cout << getName() << endl;
  cout << "Health: " << Health << endl;
  cout << "Stamina: " << Stamina << endl;
  cout << "Mana: " << Mana << endl;
}

void Character::printAllStat()  { // Ignore this. This was a copy paste for my derived classes.
  cout << setfill('-') << setw(82) << "" << endl;
  cout << "Name: " << getName() << endl;
  cout << "Level: " << Level << endl;
  cout << "Exp: " << expCount << "/" << MAX_EXP << endl;
  cout << "Health: " << Health << endl;
  cout << "Stamina: " << Stamina << endl;
  cout << "Mana: " << Mana << endl;
}

void Character::expGain(int num)  { // Give character exp after a fight
  int exp = num;
  expCount += exp;
  if(expCount >= MAX_EXP){
    int carryover;
    carryover = expCount - MAX_EXP;
    levelUp();
    expCount += carryover;
    skillPoints += 1;
    cout << getName() << " leveled up!" << endl;
  }
}

void Character::levelUp(){ // Level up a character
  Level += 1;
  expCount = 0;
}

void Character::useSP()  { // The function for the character to use their skill points
  int userChoice;
  if(skillPoints > 0)  {
    do{
      cout << "Which attribute could you like to use your skill point(s) on?" << endl;
      cout << "1. Vitality" << endl;
      cout << "2. Endurance" << endl;
      cout << "3. Willpower" << endl;
      cout << "4. Strength" << endl;
      cin >> userChoice;
      if(userChoice == 1)  {
        Vitality += 1;
        skillPoints -= 1;
        cout << "Vitality Upgraded" << endl;
      }
      else if(userChoice == 2)  {
        Endurance += 1;
        skillPoints -= 1;
        cout << "Endurance Upgraded" << endl;
      }
      else if(userChoice == 3)  {
        Willpower += 1;
        skillPoints -= 1;
        cout << "Willpower Upgraded" << endl;
      }
      else if(userChoice == 4)  {
        Strength += 1;
        skillPoints -= 1;
        cout << "Strength Upgraded" << endl;
      }
      else  {
        cout << "Please pick an attribute..." << endl;
        while (!(cin >> userChoice)) {
        cin.clear();
        cin.ignore();
        }
      }
    }while(skillPoints > 0);
    
  }
}

string Character::getType()  { // Return the character's class
  return playerType;
}

//Save and Load Functions
void Character::saveInfo(string fileName){ //Save character's information
  ofstream outFS;
  outFS.open(fileName);

  if(!outFS.is_open()) {
    cout << "File could not be open" << endl;
    exit(1);
  }
  outFS << name << endl;
  outFS << playerType << endl;
  outFS << Level <<  endl;
  outFS << expCount << endl;
  outFS << MAX_EXP << endl;
  outFS << Health << endl;
  outFS << Stamina << endl;
  outFS << Mana << endl;
  outFS << Vitality << endl;
  outFS << Endurance << endl;
  outFS << Willpower << endl;
  outFS << Strength << endl;
  outFS << skillPoints << endl;
  outFS << numPotions << endl;


  outFS.close();
  
}

Character* Character::loadCharacter(string filename){ //Load character's info from save file
  ifstream inFS;
  inFS.open(filename);

  if(!inFS.is_open())  {
    cout << "Could not load file" << endl;
    exit(1);
  }

  Character* player;
  string name;
  string classType;
  
  inFS >> name;
  inFS >> classType;
  
  if(classType == "Knight"){
    player = new Knight(name);
    player->playerType = classType;
  }
  else if(classType == "Mage"){
    player = new Mage(name);
    player->playerType = classType;
  }
  else if(classType == "Rogue"){
    player = new Rogue(name);
    player->playerType = classType;
  }
  
  inFS >> player->Level;
  inFS >> player->expCount;
  inFS >> player->MAX_EXP;
  inFS >> player->Health;
  inFS >> player->Stamina;
  inFS >> player->Mana;
  inFS >> player->Vitality;
  inFS >> player->Endurance;
  inFS >> player->Willpower;
  inFS >> player->Strength;
  inFS >> player->skillPoints;
  inFS >> player->numPotions;
  
  inFS.close();
  
  return player;
}




//Battle function
void Character::battle(Character* player)  { //This function took the most brain cells
  Character* opp = rngOpp();

  //Conditions for the battle functions (yes, there's a good amount)
  bool fin = false;
  bool playerTurn = true;
  bool oppTurn = true;
  int choice;
  int oppChoice;
  int round = 1;
  int cooldown = 0;
  int oppCD = 0;
  bool playerDeath = false;
  bool oppDeath = false;

  do  {
    opp->displayPlayer(); //Show the opponent on the screen
    player->printStatus(); //Show the player's current status
    player->attackMenu(); //Show the player's options
    cout << "Round: " << round << endl; //Show the number of rounds
    cin >> choice;
    
    while(playerTurn)  { //Player's procedure to deal damage
      if(choice == 1)  { // Moveset 1
        player->move1();
        opp->takeDamage(5 + (player->Strength * 5));
        playerTurn = false;
        oppTurn = true;
        break;
      }
        
      else if(choice == 2)  { // Moveset 2
        player->move2();
        opp->takeDamage(10 + (player->Strength * 5));
        playerTurn = false;
        oppTurn = true;
        break;
      }
        
      else if(choice == 3)  { //Moveset 3
        player->move3();
        playerTurn = false;
        oppTurn = true;
        break;
      }
        
      else if(choice == 4)  { // Ultimate ability
        if(cooldown == 4)  { //Condition for the ultimate
          player->move4();
          opp->takeDamage(20 + (player->Strength * 5));
          cooldown = 0;
          playerTurn = false;
          oppTurn = true;
          break;
        }
        else{
          cout <<"Your ultimate is not ready" << endl;
          cin >> choice;
        }
      }

      else if(choice == 5)  { // Potion function
        if(player->getPotion() <= 0){
          cout << "You don't have any potions left" << endl;
        }
        else if(player->getPotion() > 0){
          player->takePotion();
        }
        playerTurn = false;
        oppTurn = true;
        break;
      }

      else if(choice == 6)  { // Flee function (result in defeat)
        cout << player->getName() << " flee from the battle..." << endl;
        playerDeath = true;
        fin = true;
        playerTurn = false;
        oppTurn = true;
        break;
      }
        
      else { //Ensure the user input correct
        cout << "Please input the correct attack number" << endl;
        while (!(cin >> choice)) {
          cin.clear();
          cin.ignore();
        }
      }
    }
  
    while(oppTurn){ //Opponent's procedure to do damage
      oppChoice = (rand() % 5) + 1; //Generate random moves
      if(oppChoice == 1)  { //Move set 1
          opp->move1();
          player->takeDamage(5+ (opp->Strength * 5));
          playerTurn = true;
          oppTurn = false;
          break;
        }
          
        else if(oppChoice == 2)  { // Move set 2
          opp->move2();
          player->takeDamage(10 + (opp->Strength * 5));
          playerTurn = true;
          oppTurn = false;
          break;
        }
          
        else if(oppChoice == 3)  { // Move set 3
          opp->move3();
          playerTurn = true;
          oppTurn = false;
          break;
        }
          
        else if(oppChoice == 4)  { //Opponent's ultimate ability
          if(oppCD == 0)  {
            opp->move4();
            player->takeDamage(20 + (opp->Strength * 5));
            oppCD = 0;
            playerTurn = true;
            oppTurn = false;
            break;
          }
          else{
            oppChoice = 3;
          }
        }
          
        else if(choice == 5)  { //Opponent's potion function
        if(opp->getPotion() <= 0){
          cout << "Opponent has no potions left" << endl;
        }
        else if(opp->getPotion() > 0){
          opp->takePotion();
        }
        playerTurn = false;
        oppTurn = true;
        break;
      }
      // No flee option for the opponent because it's unnecessary >:)

    }

    round += 1;
    
    if(cooldown < 4)  { // User's ultimate cooldown mechanic
       cooldown += 1;
    }
    else{
      cout << "Your ultimate is ready!" << endl;
    }

    if(oppCD < 4)  { //Opponent's ultimate cooldown mechanic
       oppCD += 1;
    }
    else{
      cout << "Opponent's ultimate is ready!" << endl;
    }

    
  
    if(player->getHealth() <= 0)  { //Condition for the user's defeat
      playerDeath = true;
      fin = true;
    }
    else if(opp->getHealth() <= 0)  { //Condition for the user's victory
      oppDeath = true;
      fin = true;
    }

    if(player->Stamina <= 0)  { //Penalty for negative stamina
      player->takeDamage(1);
    }

    if(player->Mana <= 0)  { //Penalty for negative mana
      player->takeDamage(1);
    }

  }while(!fin);

  if(oppDeath){ //Display victory screen (hooray!)
    
    cout << setfill('-') << setw(82) << "" << endl;
    cout << "        d8b        888                           " << endl;
    cout << "        Y8P        888                           " << endl;
    cout << "                   888                           " << endl;
    cout << "888  888888 .d8888b888888 .d88b. 888d888888  888 " << endl;
    cout << "888  888888d88P    888   d88  88b888P   888  888 " << endl;
    cout << "Y88  88P888888     888   888  888888    888  888 " << endl;
    cout << " Y8bd8P 888 Y88b.   Y88b. Y88..88P888    Y88b 888 " << endl;
    cout << "  Y88P  888  Y8888P Y888   Y88P  888      Y88888 " << endl;
    cout << "                                             888 " << endl;
    cout << "                                        Y8b d88P " << endl;
    cout << "                                          Y88P  " << endl;
    
    player->expGain(100); //Gain exp
    cout << setfill('-') << setw(82) << "" << endl;
    cout << getName() << " gained 100 exp" << endl;
    cout << setfill('-') << setw(82) << "" << endl;
  }
  
  if(playerDeath)  { // Display defeat screen (git gud)
    
    cout << setfill('-') << setw(82) << "" << endl;
    cout << "     888         .d888                888    " << endl;
    cout << "     888        d88P                  888    " << endl;
    cout << "     888        8888                  888    " << endl;
    cout << " .d88888 .d88b. 888888 .d88b.  8888b. 888888 " << endl;
    cout << "d88  888d8P  Y8b888   d8P  Y8b     88b888    " << endl;
    cout << "888  88888888888888   88888888.d888888888    " << endl;
    cout << "Y88b 888Y8b.    888   Y8b.    888  888Y88b.  " << endl;
    cout << " Y88888   Y8888 888    Y8888  Y888888  Y8888 " << endl;
    
    player->expGain(50); //Gain exp
    cout << setfill('-') << setw(82) << "" << endl;
    cout << getName() << " gained 50 exp" << endl;
    cout << setfill('-') << setw(82) << "" << endl;
  }
  

  player->Restore(); //Restore the character after the battle
  delete opp;
}

Character* Character::rngOpp()  { //Randomly generate an opponent
  int classNum;
  classNum = (rand() % 3) + 1;
  if(classNum == 1)  {
      Knight* opp = new Knight("Opponent");
      cout << "Opponent found!" << endl;
      return opp;
    }
    else if(classNum == 2)  {
      Mage* opp = new Mage("Opponent");
      cout << "Opponent found!" << endl;
      return opp;
    }
    else if(classNum == 3)  {
      Rogue* opp = new Rogue("Opponent");
      cout << "Opponent found!" << endl;
      return opp;
    }
}

Character::~Character(){  //Deconstructor
  cout << "Cleaning up the scene..." << endl;
}
