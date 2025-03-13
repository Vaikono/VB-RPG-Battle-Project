#ifndef KNIGHT_H
#define KNIGHT_H
#include <string>
#include <cctype>
#include "Character.h"

class Knight: public Character {
  public:
  Knight(string);
  void attackMenu() override;
  void printAllStat() override;
  void move1() override;
  void move2() override;
  void move3() override;
  void move4() override;
  void displayPlayer() override;

};


#endif