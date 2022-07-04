#include <bits/stdc++.h>
#include<iostream>
#include<string>

using namespace  std;

const int ch_max = 26;

string RandomString (int ch){
    char alpha[ch_max] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    string result = "";

    for(int i=0;i<ch;i++){
        result = result + alpha[rand() %ch_max];     
    }
      return result; 
}

// int main(){
//     srand(time(NULL));
//     int ch = 15;
//     cout<<RandomString(ch)<<endl;
//     return 0;
// }