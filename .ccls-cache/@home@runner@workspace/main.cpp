//Gradebook program

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//Create global constants for the maximum number of students and test scores
const int maxStudents = 50;
const int maxTestScores = 10;


/*
Function: getTestData
Purpose: To read the data from the file 
Parameters: 
 - inputFile: the file that the user inputs that will be used to read the data from the file
 - studentName: an array of strings that will hold the names of the students
 - testScores: a 2D array of integers that will hold the test scores of the students
 - numTestScores: an integer that will hold the number of test scores for each student
 Returns: The number of student records read from the file
 Preconditions: The file must already be open and validated.
 Postconditions: The students' names will be stored in the studentName array and the test scores will be stored in the testScores array. 
*/

int getTestData(ifstream &inputFile, string studentName[], int testScores[maxStudents][maxTestScores], int &numTestScores);

/*
Function: calcAverage
Purpose: To calculate the average test score for each student. The test scores array is passed by reference to this function, and the averages are returned in a new array of doubles called averages.
Parameters: 
  - testScores: a 2D array of integers that holds the test scores of the students
  - numStudentsRecords: an integer that holds the number of student records read from the file
  - numTestScores: an integer that holds the number of test scores for each student
  - averages: an array of doubles that will hold the average test scores of the students
Returns: The averages array of doubles
Preconditions: The testScores array must already hold the test scores of the students.
Postconditions: The averages array will hold the average test score for each student.
*/

 void calcAverage(int testScores[maxStudents][maxTestScores], int numStudentRecords, int numTestScores, double averages[]);

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
Returns: None
Preconditions: The studentName and averages arrays must already hold the names and average test scores of the students.
Postconditions: The report will be printed to the console.
*/

void createReport(const string studentName[], const double averages[], int numStudentRecords);

int main() {
    //Create the arrays to hold the student names, test scores, and averages
    string studentName[maxStudents];
    int testScores[maxStudents][maxTestScores];
    double averages[maxStudents];
 
   string fileName;

    //Initialize the number of student records and test scores to 0
   int numStudentRecords = 0;
   int numTestScores = 0;

    //Open the input file and validate it. If it fails to open, print an error message and prompt the user to enter the file name again.
    cout << "Please enter the name of the file that contains the list of students and their test scores: ";
    cin >> fileName;
  
    ifstream inputFile;
    inputFile.open(fileName);
  
    if (inputFile.fail()) {
      cout << "Error opening file. Please restart the program and enter a valid file name." << endl;
      return 1;  
  }

  numStudentRecords = getTestData(inputFile, studentName, testScores, numTestScores);
  calcAverage(testScores, numStudentRecords, numTestScores, averages);
  createReport(studentName, averages, numStudentRecords);
  inputFile.close();
  
  return 0;
  
  }

  int getTestData(ifstream &inputFile, string studentName[], int testScores[maxStudents][maxTestScores], int &numTestScores) {
    int count = 0;

    while (inputFile >> studentName[count]) {
        int col = 0;
        while (col < maxTestScores && inputFile >> testScores[count][col]) {
            col++;
        }
          //Determine the number of test scores. Because the number of test scores is the same for all students, it will only be determined once (for the first student).
          if (count == 0) {
            numTestScores = col;

        }
        count++;
    }
    //The number of student records is the same as the number of times the loop iterated, so return count.
    return count;
  }

  void calcAverage(int testScores[maxStudents][maxTestScores], int numStudentRecords, int numTestScores, double averages[]) {
    for (int count = 0; count < numStudentRecords; count++) {
        double sum = 0;
        for (int col = 0; col < numTestScores; col++) {
            sum += testScores[count][col];
        }
        averages[count] = sum / numTestScores;
    }
  }

  char calcLetterGrade(double average) {
    if (average >= 90) {
        return 'A';
    }
    else if (average >= 80 && average < 90) {
        return 'B';
    }
    else if (average >= 70 && average < 80) {
        return 'C';
    }
    else if (average >= 60 && average < 70) {
        return 'D';
    }
    else {
        return 'F';
    }
  }

void createReport(const string studentName[], const double averages[], int numStudentRecords) {
    cout << "Student Name" << setw(23) << "Average Test Score" << setw(20) << "Letter Grade" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (int count = 0; count < numStudentRecords; count++)
        cout << " " << studentName[count] << setw(20) << averages[count] << setw(20) << calcLetterGrade(averages[count]) << endl;
  
    }
  


 