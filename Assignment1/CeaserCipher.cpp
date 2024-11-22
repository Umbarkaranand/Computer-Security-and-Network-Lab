/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

string encrypt(string str,int key){
    string encryptString="";
    for(auto a:str){
        if(isalpha(a)){
            
            char base = islower(a)? 'a':'A';
            a = (a-base+key) % 26 + base;
        }
        encryptString+=a;
       
    }
    
    return encryptString;
}

string decrypt(string str,int key){
    string decryptString ="";
    for(auto a:str)
    {
        if(isalpha(a)){
            char base = islower(a)? 'a':'A';
            a=(a-base-key+26) % 26 + base;
        }
        decryptString+=a;
    }
    
    return decryptString;
}

int main()
{
    string str = encrypt("anand",3);
    cout<<"Encrypted String : "<<str<<endl;
     cout<<"Decrypted String : "<<decrypt(str,3)<<endl;

    return 0;
}