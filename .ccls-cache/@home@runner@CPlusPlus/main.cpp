#include <iostream>
#include <random>

using namespace std;

/*
Function: createMenu
Purpose: Creates a menu for the user to choose from and verifies that the user's choice is valid.
Parameters: None
Returns: The user's choice as an integer.
Preconditions: None
Postconditions: The user's choice is returned as an integer.
 */
int createMenu();

/*
Function: determineWinner
Purpose: Determines the winner of the game based on the user's choice and the computer's choice.
Parameters:
 - userChoice: The user's choice as an integer.
 - computerChoice: The computer's choice as an integer.
Returns: The winner of the game as a string.
Preconditions: The user's choice and the computer's choice are valid integers.
Postconditions: The winner of the game is returned as a string.
 */

string determineWinner(int userChoice, int computerChoice);

/*
  Function: userScoreKeeper
  Purpose: Keeps track of the user's score.
  Parameters:
  - userChoice: The user's choice as an integer.
  - computerChoice: The computer's choice as an integer.
  - userScore: The user's score as an integer.
  Returns: The user's score as an integer.
  Preconditions: The user's choice and the computer's choice are valid integers.
  Postconditions: The user's score is returned as an integer.
*/

void userScoreKeeper(int userChoice, int computerChoice, int& userScore);

int main() {
  //Create and initialize variables
  int userChoice = 0;
  int computerChoice = 0;
  int userScore = 0;
  int computerScore = 0;

  //Generate a random number between 1 and 3 for the computer's choice and store it in the computerChoice variable.
  random_device engine;
  uniform_int_distribution<int> computerChoiceDist(1, 3);
  

  //Write header
  cout << "Welcome to Rock, Paper, Scissors!" << endl;

  while (userChoice != 4) {

  //Generate a random number between 1 and 3 for the computer's choice and store it in the computerChoice variable.
  computerChoice = computerChoiceDist(engine);
    
  //Write menu and get user's choice
  userChoice = createMenu();

  //Determine the winner and display the computer choice and result of the round.
  cout << "The computer chose: " << computerChoice << endl;
  cout << determineWinner(userChoice, computerChoice) << endl;

  //Keep track of the user's score and the computer's score
    userScoreKeeper(userChoice, computerChoice, userScore);

    cout << "user: " << userScore << endl;
    cout << "computer: " << computerScore << endl;
  }
  
  if (userChoice == 4) {
    cout << "Thank you for playing!" << endl;
    return 0;
  }
  
}

int createMenu() {
  int choice = 0;

  //Write a menu for the game and get the user's choice.
  cout << endl;
  cout << "Please choose from the following menu." << endl;
  cout << "1. Rock" << endl;
  cout << "2. Paper" << endl;
  cout << "3. Scissors" << endl;
  cout << "4. Quit" << endl;

  cin >> choice;

  //Validate the user's choice.
  if (choice < 1 || choice > 4) {
    cout << "Invalid choice. Please try again." << endl;
    cin >> choice;
  }
  
  return choice;
}

  string determineWinner(int userChoice, int computerChoice) {

    if ((userChoice == 1 && computerChoice == 3) || (userChoice == 2 && computerChoice == 1) || (userChoice == 3 && computerChoice == 2)) {
      return "You win!";
    }

    else if (userChoice == computerChoice) {
      return "It's a tie.";
    }

    else if (userChoice == 4) {
      return " ";
    }

    else {
      return "The computer wins.";
    }
  }

  void userScoreKeeper(int userChoice, int computerChoice, int &userScore) {
    
    if (determineWinner(userChoice, computerChoice) == "You win!") {
      userScore++;
    }
      
  
  }