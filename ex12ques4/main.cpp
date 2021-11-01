#include<iostream>
using namespace std;
#include<fstream>
#include "Student.h"
/*Glabal array of Student-s*/
Student studArr[50];
/**
 * @brief Copies Student instances from input file to global studArr array
 * @param fileName Input file
 * @return numStudents Number of students read
*/
int CopyToStudArray(const char fileName[25]);
/**
 * @brief Prints numStudents students from global studArr
 * @param numStudents Number of students read from file
*/
void print(int numStudents);
/**
 * @author Yehuda Moshe Binyamin
 * @brief Driver code-to read student info from file and print that to the screen
 * @param  
 * @return 
*/
int main(void)
{
    size_t numStudents=CopyToStudArray("students.txt");
    print(numStudents);
    return 0;
}

int CopyToStudArray(const char fileName[25])
{
    size_t numStudents = 0;
    size_t index = 0;
    ifstream inputFile(fileName);
    if (!inputFile)
    {
        cerr << "An error has occurred-cannot open file" << endl;
        exit(-1);
    }
    inputFile >> studArr[index].id >> studArr[index].name >> studArr[index].mark;
    while (!inputFile.eof())
    {
        index++;
        numStudents++;
        inputFile >> studArr[index].id >> studArr[index].name >> studArr[index].mark;
    }
    inputFile.close();
    return numStudents;
}

void print(int numStudents)
{
    for (size_t i = 0; i < numStudents; ++i)
    {
        cout << "name: " << studArr[i].name << " id: " << studArr[i].id << " mark: " << studArr[i].mark << endl;
    }
}
/**Sample Execution:
name: Elkana id : 1234 mark : 100
name : Chana id : 5678 mark : 90
name : Penina id : 9090 mark : 80
name : Eli id : 6868 mark : 70
name : Shmuel id : 4321 mark : 60
**/