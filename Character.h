#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <cctype>
using namespace std;

class Character {

  protected: //Character's attributes
  string name;
  string playerType;
  int Level;
  int expCount;
  int MAX_EXP;
  int Health;
  int Stamina;
  int Mana;
  int Vitality;
  int Endurance;
  int Willpower;
  int Strength;
  int skillPoints;
  int numPotions;

  public: //Character's base functions (yes, there's a lot im sorry)
  Character();
  void setName(string);
  string getName();
  void takeDamage(int);
  void takePotion();
  int getPotion();
  int getHealth();
  void Restore();
  void expGain(int);
  void levelUp();
  void useSP();
  void printStatus();
  void saveInfo(string);
  Character* loadCharacter(string);
  string getType();
  virtual void attackMenu() = 0;
  virtual void printAllStat() = 0;
  virtual void move1() = 0;
  virtual void move2() = 0;
  virtual void move3() = 0;
  virtual void move4() = 0;
  virtual void displayPlayer() = 0;
  void battle(Character* player);
  Character* rngOpp();
  virtual ~Character();
  
};

#endif