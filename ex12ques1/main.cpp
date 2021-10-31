#include <fstream>
#include <iostream>
using namespace std;
int main(void)
{
    char name[20];
    int grade;
    bool readGrades = true;
    bool readNames = true;
    ifstream namesFile("names.txt");
    ifstream gradesFile("grades.txt");
    ofstream outputFile("roster.txt");
    //while both files have information
    //as long as both have not reached the end of the files
    do{
        gradesFile >> grade;
        if (gradesFile.eof())
        {
            cout << grade << endl;
            readGrades = false;
            gradesFile.close();
            cout << "finished reading grades before names" << endl;
            break;
        }
        namesFile >> name;
        if (strcmp(name, "") == 0)
        {
            readNames = false;
            cout << "finished reading names before grades" << endl;
            break;
        }
        outputFile << name << " " << grade << endl;
        
    } while ((readGrades)&&(readNames));
    //if there are still names without grades
        while (readNames) 
        {   
            namesFile >> name;
            if (strcmp(name, "") == 0)
            {
                readNames = false;
                namesFile.close();
                break;
            }
            cout << name << endl;
        }
    
    //if there are still grades without names
        while (readGrades)
        {
            gradesFile >> grade;
            if (gradesFile.eof())
            {
                gradesFile.close();
                readGrades = false;
                break;   
            }           
            cout << grade << endl;
        }
    
    outputFile.close();
    return 0;
}
/**Sample Input and Output:
names.txt:
Elkana
Chana
Penina
Eli
Shmuel
Shaul
Hanaar
grades.txt:
100
90
80
70
60
roster.txt(output):
Elkana 100
Chana 90
Penina 80
Eli 70
Shmuel 60
Example 2:**/

