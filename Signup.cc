#include<iostream>
#include<string>
#include<fstream>

using namespace std;


const int MAX_ROW = 100;

string id[MAX_ROW] = {};
string names[MAX_ROW] = {};
string email[MAX_ROW] = {};
string password[MAX_ROW] = {};
int age[MAX_ROW] = {};
string role[MAX_ROW] = "student";


void writeStudentToFile(){

}

void createStudent(){

    string id;
    string email;
    string role = "student";
    string password;
    string names;
    string age;

    cout<<"\t\t\t Signup in to the system \t\t\t\t "<<endl;
    cout<<"\t\t\t ========================  \t\t\t\t "<<endl;

    cin.ignore();
    
    cout<<"\t\t\t Enter your names"<<endl;
    getline(cin,names);
    cout<<"\t\t\t Enter your age"<<endl;
    getline(cin,age);
    cout<<"\t\t\t Enter your email"<<endl;
    getline(cin,email);
    cout<<"\t\t\t Enter your password"<<endl;
    getline(cin,password);

    for(int x=0;x<MAX_ROW;x++){
       
};