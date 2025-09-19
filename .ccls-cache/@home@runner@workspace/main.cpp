//Rock, Paper, Scissors Program

#include <iostream>
#include <fstream>

using namespace std;

/*
Function: getNames
Purpose: A function to read the data from the file. This function should be provided with a file object
for a file that has already been opened successfully. The function should read the data from
the file into the names and test scores parallel arrays. The function should also return the
number of student records stored on the file.
Parameters: ifstream&, string[], int[], int
Returns: int
Preconditions: The file must be opened successfully.
Postconditions: The names and test scores arrays will be filled with data from the file.
*/

int getNames(ifstream&, string[], int[], int[]);

/*
Function: calculateAverage
Purpose: A function to calculate the averages of all the students. This function should be provided
with the test scores array and return the averages in the averages array.
Parameters: int[][], int[]
Returns: void
Preconditions: The test scores array must be filled with data.
Postconditions: The averages array will be filled with the averages of the students.
*/

void calculateAverage(int[][], int[]);

/*
Function: calculateLetterGrade
Purpose: A function to calculate a letter grade from an average test score. This function is provided
with the test score and returns the letter grade.
Parameters: int
Returns: char
Preconditions: The test score must be a valid test score.
Postconditions: The letter grade will be returned.
*/

char calculateLetterGrade(int);

/*
Function: createReport
Purpose: A function to produce the formatted report. This function is provided with the student
  names array and the averages array. It then outputs the students name, average test score
  and letter grade. The report should have labeled columns and the data should be aligned in
  columns.
Parameters: string[], int[]
Returns: void
Preconditions: The names and averages arrays must be filled with data.
Postconditions: The report will be displayed on the screen.
  */

int main() {

    string fileName;
  //Create a file object to use for file input.
    ifstream inFile;
  
  //Create a string array to hold the names of the students. The array should be able to hold 50 names.
    string names[50];
  //Create a 2D array with a row for each student and a column for each test score. The array should be able to hold 50 students and 10 test scores.
    int testScores[50][10];
  //Create an array to hold the average test scores for each student. The array should be able to hold 50 averages.
    int averages[50];

    //Ask the user which file they would like to open.
    cout << "Enter the name of the file you would like to open: ";
    cin >> fileName;
    //Open the file.
    inFile.open(fileName);
    //If the file failed to open, close the file and display an error message. Then, allow the user to enter another file name.
    while (inFile.fail()) {
        inFile.close();
        cout << "Error opening file. Please enter another file name: ";
        cin >> fileName;
        inFile.open(fileName);
    }
      
  
  
}