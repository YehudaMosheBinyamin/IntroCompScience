#include <fstream>
#include <iostream>
using namespace std;
/**
 * @author Yehuda Moshe Binyamin
 * @brief A program which takes grades from grades.txt, and names from names.txt and combines the information in roster.txt
 * If there are a different amount of grades and names, the unnescessary names/grades will be printed to the screen with an appropriate message
 * @param
 * @return
*/
int main(void)
{
    char name[50];
    int grade;
    bool readGrades = true;
    bool readNames = true;
    ifstream namesFile("names.txt");
    ifstream gradesFile("grades.txt");
    ofstream outputFile("roster.txt");
    //while both files have information
    //as long as both have not reached the end of the files
    namesFile >> name;
    gradesFile >> grade;
    while (!gradesFile.eof() && !namesFile.eof())
    {
        outputFile << name << " " << grade << endl;
        namesFile >> name;
        gradesFile >> grade;
        if (gradesFile.eof() && !namesFile.eof())
        {
            cout << "finished reading grades before names" << endl;
            cout << name << endl;
            outputFile << name << endl;
        }
        if (!gradesFile.eof() && namesFile.eof())
        {
            cout << "finished reading names before grades" << endl;
            cout << grade << endl;
            outputFile << grade;
        }
    }
    namesFile >> name;
    while (!namesFile.eof())
    {
        cout << name << endl;
        namesFile >> name;
    }
    gradesFile >> grade;
    while (!gradesFile.eof())
    {
        cout << grade << endl;
        gradesFile >> grade;
    }
    namesFile.close();
    gradesFile.close();
    outputFile.close();
    return 0;
}
/**Sample Execution 1:
names.txt
Elkana
Chana
Penina
Eli
Shmuel
Shaul
Hanaar

grades.txt
100
90
80
70
60


roster.txt output file:
Elkana 100
Chana 90
Penina 80
Eli 70
Shmuel 60


Screen:

finished reading grades before names
Shaul
Hanaar

Sample Execution 2:

names.txt

Elkana
Chana
Penina
Eli
Shmuel

grades.txt

100
90
80
70
60
50
40

roster.txt output file:
Elkana 100
Chana 90
Penina 80
Eli 70
Shmuel 60


Screen output:
finished reading names before grades
50
40

**/

