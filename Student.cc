#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream>
#include "generateRandomId.cc"

using namespace std;

const int maxRow = 10;
string studentId[maxRow] = {};
string studentNames[maxRow] = {};
string studentEmail[maxRow] = {};
string studentPassword[maxRow] = {};
string studentRole[maxRow] = {};
string studentAge[maxRow] = {};

class Student
{
    string password;
    string names;
    string email;
    string age;
    string role;

public:
    void createStudent();
    void viewStudent();
    void viewAllStudents();
    void updateStudent(string id, string newName,string newEmail, string newAge, string newPassword);
    void deleteStudent(string id);
    void openStudentsFile();
    void saveStudentToFile();
    void sortStudentsNames();
};

void Student::createStudent()
{
    string names;
    string email;
    string age;
    string password;

    srand(time(NULL));
    cin.ignore();
    cout << "Enter your names" << endl;
    getline(cin, names);
    cout << "Enter your email" << endl;
    getline(cin, email);
    cout << "Enter your age" << endl;
    getline(cin, age);
    cout << "Enter your password" << endl;
    getline(cin, password);

    for (int x = 0; x < maxRow; x++)
    {
        if (studentId[x] == "\0")
        {
            studentId[x] = RandomString(15);
            studentNames[x] = names;
            studentEmail[x] = email;
            studentAge[x] = age;
            studentPassword[x] = password;
            studentRole[x] = "student";
            break;
        }
    }
}

void Student::viewAllStudents()
{
    int counter = 0;

    cout << "Students List" << endl;
    cout << "=============" << endl;
    cout << endl;

    for (int x = 0; x < maxRow; x++)
    {
        if (studentId[x] != "\0")
        {
            counter++;
            cout << studentId[x] << "               " << studentNames[x] << "                   " << studentEmail[x] << "      " << studentAge[x] << "               " << studentPassword[x] << endl;
        }
    }

    if (counter == 0)
    {
        cout << "No students in the system" << endl;
    }

    cout << "-------------------------------" << endl;
}

void Student::updateStudent(string id, string newName,string newEmail, string newAge, string newPassword){
    int counter =0;

    for(int x=0;x<maxRow;x++){
        if(studentId[x] == id){
            counter ++;
            studentNames[x] = newName;
            studentEmail[x] = newEmail;
            studentAge[x] = newAge;
            studentPassword[x] = newPassword;
            cout<<"Student updated successfully"<<endl;
             break;
        }
    }

    if(counter == 0){
        cout<<"Student not found"<<endl;
    }
}

void Student::openStudentsFile()
{
    string line;

    ifstream studentsFile;

    studentsFile.open("students.txt");

    if (studentsFile.is_open())
    {
        int x = 0;

        while (getline(studentsFile, line))
        {
            string delimeter = ",";
            size_t pos = 0;
            std::string token;
            int counter=0;
            while ((pos = line.find(delimeter)) != std::string::npos)
            {
                token = line.substr(0, pos);
                line.erase(0, pos + delimeter.length());
                if(counter==1){
                    studentId[x] = token;
                } else if(counter==2){
                    studentNames[x] = token;
                } else if(counter==3){
                    studentEmail[x] = token;
                } else if(counter==4){
                    studentAge[x] = token;
                } else if(counter==5){
                    studentPassword[x] = token;
                } else if(counter==6){
                    studentRole[x] = token;
                }

                counter++;
            }
            x++;
        }
    }
    else
    {
        cout << "Unable to open the file" << endl;
    }
}

void Student::saveStudentToFile()
{
    ofstream studentsFile;
    studentsFile.open("students.txt");

    for (int x = 0; x < maxRow; x++)
    {
        if (studentId[x] == "\0")
        {
            break;
        }
        else
        {
            studentsFile << "," + studentId[x] + "," + studentNames[x] + "," + studentEmail[x] + "," + studentAge[x] + "," + studentPassword[x] + "," + studentRole[x] + ","<<endl;
        }
    }
}


void Student::sortStudentsNames(){
    // sort(studentNames, studentNames + maxRow);
    sort(begin(studentNames), end(studentNames));
    for(auto n: studentNames){
        cout<<n<<endl;
    }
}

int main()
{
    Student std;
    int option;
    string newName;
    string newEmail;
    string newAge;
    string newPassword;
    string id;

    std.openStudentsFile();

    cout << "Welcome to the student  board" << endl;
    cout << "-----------------------------" << endl;

    do
    {

        cout << "1. create new student" << endl;
        cout << "2. view all students" << endl;
        cout<<  "3. update student"<<endl;  
        cout<<  "4. sort students"<<endl;
        cout << "5. Exit the system " << endl;
        cout << "Enter your option" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            std.createStudent();
            break;

        case 2:

            std.viewAllStudents();
            break;

        case 3:
             cin.ignore();
             cout<<"Enter the student id"<<endl;
             getline(cin,id);
             cout<<"Enter the new name"<<endl;
             getline(cin,newEmail);
             cout<<"Enter the new email"<<endl;
             getline(cin,newEmail);
             cout<<"Enter the new age"<<endl;
             getline(cin,newAge);
             cout<<"Enter the new password"<<endl;
             getline(cin,newPassword);
             std.updateStudent(id,newName,newEmail,newAge,newPassword);
             break;


        case 4:
             std.sortStudentsNames();
             break;
                  
        default:

            cout << "Invalid option" << endl;
            break;
        }

    } while (option != 5);

    std.saveStudentToFile();

    cout << "Student details saved to file";

    return 0;
}