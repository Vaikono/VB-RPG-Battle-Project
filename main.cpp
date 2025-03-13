#include "Character.h"
#include "Knight.h"
#include "Mage.h"
#include "Rogue.h"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void mainMenu();     // Print the main menu
void printPicture(); // Print a picture in the beginning of the program
void printEnding();  // Print a picture in the end of the program

int main() {
  string charName; // Name of the character
  int choice;      // A input to navigate the menu/program
  int option;      // A secondary input to navigate the menu/program
  Character *
      player; // Pointer for the character class as well as the user's character
  string filename = "savefile1.txt"; // The saving file

  cout << "Welcome to Clash of Guild!" << endl;
  printPicture();
  cout << setfill('-') << setw(82) << "" << endl;
  cout << "A turn-based combat game where you will be fighting against your "
          "fellow guildmates!"
       << endl;
  cout << setfill('-') << setw(82) << "" << endl;
  cout << "General rules of Combat:" << endl;
  cout << setfill('-') << setw(82) << "" << endl;
  cout << "- You and your opponent will take turn dealing damage" << endl;
  cout << "- Every other rounds, you can use your class ultimate" << endl;
  cout << "- You will lose 1 damage if your stamina or mana fall under 0 "
       << endl;
  cout << "- You have 2 potions to restore your health, stamina, or mana"
       << endl;
  cout << "- If you win, you will gain 1 level (100 exp)" << endl;
  cout << "- If you lose, you will gain half a level (50 exp)" << endl;
  cout << "- Most importantly, good luck and have fun!" << endl;
  cout << "- Note: make sure you save your game or else you might regret it"
       << endl;
  cout << setfill('-') << setw(82) << "" << endl;

  cout << "Please select the following options:" << endl;
  cout << "1. Create a new character" << endl;
  cout << "2. Load Save File" << endl;
  cout << setfill('-') << setw(82) << "" << endl;
  cin >> option;

  cout << setfill('-') << setw(82) << "" << endl;

  // Two options from the starting menu: Create new or load a saving file.
  if (option == 1) {
    cout << "Please name your character:" << endl;
    cin >> charName;
    cout << setfill('-') << setw(82) << "" << endl;

    cout << "Please select your class: " << endl;
    cout << "(1) Knight" << endl;
    cout << "(2) Mage" << endl;
    cout << "(3) Rogue" << endl;
    cout << setfill('-') << setw(82) << "" << endl;

    while (!(cin >> choice)) { // This code is to ensure the user input only
                               // integer and prevent errors.
      cin.clear();
      cin.ignore();
    }
    cout << setfill('-') << setw(82) << "" << endl;

    bool done = false;
    // A game loop for character creation
    while (!done) {
      if (choice == 1) { // Create a Knight character
        player = new Knight(charName);
        cout << "Character created!" << endl;
        player->displayPlayer();
        done = true;
        break;
      } else if (choice == 2) { // Create a Mage character
        player = new Mage(charName);
        cout << "Character created!" << endl;
        player->displayPlayer();
        done = true;
        break;
      } else if (choice == 3) { // Create a Rogue character
        player = new Rogue(charName);
        cout << "Character created!" << endl;
        player->displayPlayer();
        done = true;
        break;
      } else { // Ensure the user input correctly
        cout << "Please input 1, 2, or 3" << endl;
        while (!(cin >> choice)) {
          cin.clear();
          cin.ignore();
        }
        cout << setfill('-') << setw(82) << "" << endl;
      }
    }

  } else if (option == 2) { // The option to load in save file
    cout << "Loading File:" << endl;
    player = player->loadCharacter(filename);
    player->displayPlayer();
  } else { // Ensure the user input correctly
    cout << "Please pick an option" << endl;
    while (!(cin >> option)) {
      cin.clear();
      cin.ignore();
    }
  }

  // Print the main menu after the starting menu
  mainMenu();
  cin >> choice;
  cout << setfill('-') << setw(82) << "" << endl;

  bool isDone = false;

  // Loop the main menu featuring the main functions:
  // Battle
  // Display Character's stats
  // Save and quit
  // Quit without saving
  while (!isDone) {

    if (choice == 1) { // The battle function ("random" opponent)
      player->battle(player);
      mainMenu();
      cin >> choice;
      cout << setfill('-') << setw(82) << "" << endl;
    }

    else if (choice == 2) { // Show all the character's stats
      player->displayPlayer();
      player->printAllStat();
      mainMenu();
      cin >> choice;
      cout << setfill('-') << setw(82) << "" << endl;
    }

    else if (choice == 3) { // Save file and quit
      player->saveInfo(filename);
      cout << "Saving and quiting..." << endl;
      delete player;
      isDone = true;
      printEnding();
    }

    else if (choice == 4) { // Quit without saving file
      cout << "Quitting without saving..." << endl;
      cout << "Hope you won't regret it..." << endl;
      delete player;
      isDone = true;
      printEnding();
    }

    else { // Ensure the user input correctly and prevent errors.
      cout << "Please input the correct value" << endl;
      while (!(cin >> choice)) {
        cin.clear();
        cin.ignore();
      }
      cout << setfill('-') << setw(82) << "" << endl;
    }
  }

  return 0;
}

void mainMenu() { // Print the main menu and its functions
  cout << setfill('-') << setw(82) << "" << endl;
  cout << "Please pick your option:" << endl;
  cout << "1: Battle" << endl;
  cout << "2: Check Stats" << endl;
  cout << "3: Save & Quit" << endl;
  cout << "4. Quit without Saving" << endl;
  cout << setfill('-') << setw(82) << "" << endl;
}

void printPicture() { // Print a fun picture
  cout << "██████████████████████████████████████████████████████████" << endl;
  cout << "████░░██████████████████████████████████████████████▓▓░░██" << endl;
  cout << "██████████████████████████████████████████████████████████" << endl;
  cout << "████████    ████      ░░              ░░  ████      ██████" << endl;
  cout << "▓▓██████      ██      ██    ▒▒      ▒▒    ████      ██████" << endl;
  cout << "▓▓██████      ██  ██    ██  ████▒▒  ████  ████    ████████" << endl;
  cout << "████████  ██  ▒▒  ░░    ██  ████▒▒  ████  ████  ▓▓  ██████" << endl;
  cout << "████████          ██    ██    ██      ██            ██████" << endl;
  cout << "██████████████████████████████████████████████████████████" << endl;
  cout << "██████████████████████████████████████████████████████████" << endl;
}

void printEnding() { // Leave a fun easter egg. If you know this game, you get a
                     // cookie.
  cout << endl;
  cout << "      ██              ██      " << endl;
  cout << "    ██  ██          ██  ██    " << endl;
  cout << "    ██    ██      ██    ██    " << endl;
  cout << "    ██    ██████████    ██    " << endl;
  cout << "    ██████          ██████    " << endl;
  cout << "    ██                  ██    " << endl;
  cout << "  ██                      ██  " << endl;
  cout << "  ██      ██      ██      ██  " << endl;
  cout << "██                          ██" << endl;
  cout << "██        ██  ██  ██        ██" << endl;
  cout << "██          ██████          ██" << endl;
  cout << "  ██        ██  ██        ██  " << endl;
  cout << "  ██        ██  ██        ██  " << endl;
  cout << "    ██        ██        ██    " << endl;
  cout << "      ████          ████      " << endl;
  cout << "      ██  ██████████  ██      " << endl;
  cout << "      ██  ██      ██  ██      " << endl;
  cout << "        ██          ██        " << endl;
}