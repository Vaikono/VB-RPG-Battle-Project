#ifndef MAGE_H
#define MAGE_H
#include <string>
#include <cctype>
#include "Character.h"

class Mage: public Character {
  public:
  Mage(string);
  void attackMenu() override;
  void printAllStat() override;
  void move1() override;
  void move2() override;
  void move3() override;
  void move4() override;
  void displayPlayer() override;

};


#endif