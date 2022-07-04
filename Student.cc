#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<fstream>
#include "generateRandomId.cc"

using  namespace std;


const int maxRow = 10;
string studentId[maxRow] = {};
string studentNames[maxRow] = {};
string studentEmail[maxRow] = {};
string studentPassword[maxRow] = {};
string studentRole[maxRow] = {};
string studentAge[maxRow] = {};


class Student{
    string password;
    string names;
    string email;
    string age;
    string role;

    public:
     
     void createStudent();
     void viewStudent();
     void viewAllStudents();
     void updateStudent(int id);
     void deleteStudent(int id);
     void openStudentsFile();
     void saveStudentToFile();
};

void Student::createStudent(){
    string names;
    string email;
    string age;
    string password;
    
    srand(time(NULL));
    cin.ignore();
    cout<<"Enter your names"<<endl;
    getline(cin,names);
    cout<<"Enter your email"<<endl;
    getline(cin,email);
    cout<<"Enter your age"<<endl;
    getline(cin,age);
    cout<<"Enter your password"<<endl;
    getline(cin,password);


    for(int x=0; x<maxRow; x++){
        if(studentId[x] == "\0"){
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

void Student::viewAllStudents(){
    int counter =0;

    cout <<"Students List"<<endl;
    cout<<"============="<<endl;
    cout<<"ID                             Names                         Email            Age                   Password     "<<endl;
    cout<<endl;

    for(int x=0;x<maxRow;x++){
        if(studentId[x] != "\0"){
            counter++;
            cout<<studentId[x]<<"               "<<studentNames[x]<<"                   "<<studentEmail[x]<<"      "<<studentAge[x]<<"               "<<studentPassword[x]<<endl;
        }
    }

    if(counter == 0){
        cout<<"No students in the system"<<endl;
    }

    cout<<"-------------------------------"<<endl;
}


Student::openStudentsFile(){
    string line;

    ifstream studentsFile;

    studentsFile.open("students.txt");

    if(studentsFile.is_open()){
        int x=0;
        
        while (getline(studentsFile,line))
        {
            int l = line.length();
            studentId[x] = line.substr(0,15);
            studentNames[x] = line.substr(15,1-15);
            studentEmail[x] = line.substr(15,2-15);
            studentAge[x] = line.substr(15,3-15);
            studentPassword[x] = line.substr(15,4-15);
            studentRole[x] = line.substr(15,5-15);
        }
        
    }
}


int main(){
    Student std;
    int option;

    cout<<"Welcome to the student  board"<<endl;
    cout<<"-----------------------------"<<endl;

    do{

    cout<<"1. create new student"<<endl;
    cout<<"2. view all students"<<endl;
    cout<<"3. Exit the system "<<endl;
    cout<<"Enter your option"<<endl;
    cin>>option;

    switch (option)
    {
    case 1:
        std.createStudent();
        break;
    
    case 2:

        std.viewAllStudents();
        break;

    default:

       cout<<"Invalid option"<<endl;
        break;
    }

    } while(option != 3);

    return 0;
}