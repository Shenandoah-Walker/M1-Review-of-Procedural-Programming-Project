#include <iostream>

using namespace std;

// Create a function that makes a menu ranging from 1-4 and returns the value of the choice
int menu();

int main() {
  int choice = 0;

  choice = menu();
}

int menu() {
  int choice = 0;
  cout << "Welcome to Rock, Paper, Scissors! Please ch" << endl;
  cout << "1. Rock" << endl;
  cout << "2. Paper" << endl;
  cout << "3. Scissors" << endl;
  cout << "4. Quit" << endl;

  cin >> choice;

  if (choice < 1 || choice > 4) {
    cout << "Invalid choice" << endl;
    cin >> choice;
  }
  return choice;
}