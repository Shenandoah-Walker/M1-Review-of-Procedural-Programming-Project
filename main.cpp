//Rock, Paper, Scissors Program

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

string determineRoundWinner(int userChoice, int computerChoice);

/*
  Function: userScoreUpdate
  Purpose: Updates the user's score and the computer's score.
  Parameters:
  - userChoice: The user's choice as an integer.
  - computerChoice: The computer's choice as an integer.
  - userScore: The user's score as an integer.
  - computerScore: The computer's score as an integer.
  Returns: None.
  Preconditions: The user's choice and the computer's choice are valid integers.
  Postconditions: The user's score is updated or the computer's score is updated, depending on the result of the game.
*/

void scoreUpdate(int userChoice, int computerChoice, int& userScore, int& computerScore);


/*
  Function: determineTournamentWinner
  Purpose: Determines the winner of the tournament based on the user's score and the computer's score.
  Parameters:
  - userScore: The user's score as an integer.
  - computerScore: The computer's score as an integer.
  Returns: The winner of the tournament as a string.
  Preconditions: The user's score and the computer's score are valid integers.
  Postconditions: The winner of the tournament is returned as a string.
*/

string determineTournamentWinner(int& userScore, int& computerScore);

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

  //Write menu and get user's choice (The user's choice is validated in the createMenu function.)
  userChoice = createMenu();

  //If the player chooses to continue, determine the winner and display the computer choice and result of the round.
  if (userChoice != 4) {

    cout << "The computer chose: " << computerChoice << endl;
    cout << endl;
    cout << determineRoundWinner(userChoice, computerChoice) << endl;

    //Update the user's score and the computer's score
    scoreUpdate(userChoice, computerChoice, userScore, computerScore);

  }
  //If the player chooses to quit, display the winner of the tournament, thank the player for playing, and end the program.
  else {
    cout << determineTournamentWinner(userScore, computerScore) << endl;
    cout << "Thank you for playing!" << endl;
    return 0;
       }

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

  cout << endl;
  cout << "Enter your choice: ";
  cin >> choice;

  //Validate the user's choice.
  while (choice < 1 || choice > 4) {
    cin.clear();
    cin.ignore(1000, '\n');  
    cout << endl;
    cout << "Invalid choice. Please try again." << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> choice;
  }

  return choice;
}

  string determineRoundWinner(int userChoice, int computerChoice) {

    //For each possible combination of userChoice and computerChoice that results in a win for the user, return "You win!"
    if ((userChoice == 1 && computerChoice == 3) || (userChoice == 2 && computerChoice == 1) || (userChoice == 3 && computerChoice == 2)) {
      return "You win!";
    }

    //If userChoice and computerChoice are the same, return "This round resulted in a draw."
    else if (userChoice == computerChoice) {
      return "This round resulted in a draw.";
    }

    //If the user chooses to quit, return an empty string.
    else if (userChoice == 4) {
      return " ";
    }

    //If none of the above conditions are met (which means that the combinations resulted in a win for the computer), return "The computer wins."
    else {
      return "The computer wins.";
    }
  }

  void scoreUpdate(int userChoice, int computerChoice, int& userScore, int& computerScore) {

    //If the user wins the round, increment the user's score by 1. 
    if (determineRoundWinner(userChoice, computerChoice) == "You win!") {
      userScore++;
    }
    //If the computer wins the round, increment the computer's score by 1.
    if (determineRoundWinner(userChoice, computerChoice) == "The computer wins.") {
      computerScore++;
    }
  }

    string determineTournamentWinner(int& userScore, int& computerScore) {

      //If the user's score is greater than the computer's score, return "You won the tournament!"
      if (userScore > computerScore) {
        return "You won the tournament!";
      }

      //If the computer's score is greater than the user's score, return "The computer won the tournament."
      else if (userScore < computerScore) {
        return "The computer won the tournament.";
      }

      //If the user's score and the computer's score are the same, return "The tournament resulted in a draw."
      else {
        return "The tournament resulted in a draw.";
      }

    }
