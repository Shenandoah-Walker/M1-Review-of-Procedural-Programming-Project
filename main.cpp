//Gradebook program

#include <iostream>
#include <fstream>

using namespace std;

const int maxTestScores = 50;

/*
Function: getTestData
Purpose: To read the data from the file 
Parameters: 
 - inputFile: a reference to an ifstream object that will be used to read the data from the file
 - studentName: an array of strings that will hold the names of the students
 - testScores: a 2D array of integers that will hold the test scores of the students
 - numStudentsRecords: an integer that will hold the number of student records read from the file
 Returns: The number of student records read from the file
 Preconditions: The file must already be open and validated.
 Postconditions: The students' names will be stored in the studentName array and the test scores will be stored in the testScores array. 
*/

int getTestData(ifstream &inputFile, string studentName[], int testScores[][maxTestScores], int numStudentsRecords);

/*
Function: calcAverage
Purpose: To calculate the average test score for each student. The test scores array is passed by reference to this function, and the averages are returned in a new array of doubles called averages.
Parameters: 
  - testScores: a 2D array of integers that holds the test scores of the students
  - numStudentsRecords: an integer that holds the number of student records read from the file
  - averages: an array of doubles that will hold the average test scores of the students
Returns: The averages array of doubles
Preconditions: The testScores array must already hold the test scores of the students.
Postconditions: The averages array will hold the average test score for each student.
*/

 void calcAverage(int testScores[][maxTestScores], int numStudentsRecords, double averages[]);

/*
Function: calcLetterGrade
Purpose: Calculates a letter grade from an average test score. This function is provided
with the test score and returns the letter grade.
Parameters:
 - average: a double that holds the average test score of a student
Returns: The letter grade as a char
Preconditions: The average must be a valid double.
Postconditions: The letter grade will be returned as a char.
*/

char calcLetterGrade(double average);

/*
Function: createReport
Purpose: To produce the formatted report. This function is provided with the student
names array and the averages array. It then outputs the students name, average test score
and letter grade. The report should have labeled columns and the data should be aligned in
columns.
Parameters:
 - studentName: an array of strings that holds the names of the students
 - averages: an array of doubles that holds the average test scores of the students
 - numStudentsRecords: an integer that holds the number of student records read from the file
 - letterGrade: a char that holds the letter grade of a student
Returns: None
Preconditions: The studentName and averages arrays must already hold the names and average test scores of the students.
Postconditions: The report will be printed to the console.
*/

void createReport(string studentName[], double averages[], int numStudentsRecords);

int main() {
}