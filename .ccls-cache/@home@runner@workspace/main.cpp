//Rock, Paper, Scissors Program

#include <iostream>
#include <fstream>

using namespace std;

const int maxTestScores = 50;

/*
Function: getTestData
Purpose: To read the data from the file 
Parameters: 
 - studentName: an array of strings that will hold the names of the students
 - testScores: a 2D array of integers that will hold the test scores of the students
 - numStudentsRecords: an integer that will hold the number of student records read from the file
 Returns: The number of student records read from the file
 Preconditions: The file must already be open and validated.
 Postconditions: The students' names will be stored in the studentName array and the test scores will be stored in the testScores array. 
*/

int getTestData(string studentName[], int testScores[][maxTestScores], int numStudentsRecords);

/*
Function: calcAverage
Purpose: To calculate the average test score for each student. The test scores array is passed by reference to this function, and the averages are returned in a new array of doubles called averages.
Parameters: 
