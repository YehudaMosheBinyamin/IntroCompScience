#include<iostream>
using namespace std;
#include<fstream>

/**
 * @brief Reads a file of grades and returns the average of its elements
 * @param inputFile Reference to field to read grades from
 * @return averageGradeOfFile Average of all grades in file
*/

float AverageFromFile(ifstream& inputFile)
{
    size_t countGrades = 0;
    float sumGrades = 0;
    float averageGradeOfFile;
    float currentGrade;
    if (!inputFile)
    {
        cerr << "Problem opening the file" << endl;
        exit(-1);
    }
    inputFile >> currentGrade;
    while (!(inputFile.eof()))
    {
        sumGrades += currentGrade;
        countGrades++;
        inputFile >> currentGrade;
    }
    averageGradeOfFile = sumGrades / countGrades;
    return averageGradeOfFile;
}


/**
 * @author yehuda Moshe Binyamin
 * @brief Program to print file which has the higherst average of grades out of all the grade files
 * @param
 * @return
*/

int main(void)
{
    size_t indexMaxAverage = 0;
    float averageOfFile[4];
    ifstream gradesOne = ifstream("grade1.txt");
    averageOfFile[0] = AverageFromFile(gradesOne);
    ifstream gradesTwo = ifstream("grade2.txt");
    averageOfFile[1] = AverageFromFile(gradesTwo);
    ifstream gradesThree = ifstream("grade3.txt");
    averageOfFile[2] = AverageFromFile(gradesThree);
    ifstream gradesFour = ifstream("grade4.txt");
    averageOfFile[3] = AverageFromFile(gradesFour);
    float maxAverage = averageOfFile[0];
    for (size_t i = 1; i < 4; ++i)
    {
        if (averageOfFile[i] > maxAverage)
        {
            maxAverage = averageOfFile[i];
            indexMaxAverage = i;
        }
    }
    cout << "highest average found in file " << indexMaxAverage + 1 << endl;//+1 since intuitevely people count from 1 and not 0 like a computer
    return 0;
}
/**
Screen:
highest average found in file 2
From files:
grade1.txt:
1
2
3
4
grade2.txt
2
4
6
8
10
12
grade3.txt
1
3
grade4.txt
5
1
3
**/