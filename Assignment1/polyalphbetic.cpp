#include<bits/stdc++.h>
using namespace std;

string generateKey(string msg,string key){
    string resultKey;
    int index=0;
    for (char c : msg) {
        if (isalpha(c)) { // Add key character only for alphabetic characters
            if (index == key.size()) {
                index = 0;
            }
            resultKey += key[index++];
        } else {
            resultKey += c; // Keep spaces and non-alphabetic characters unchanged
        }
    }
    return resultKey;
}


string encrypt(string msg,string key){
    string encryptString;
    for(int i=0;i<msg.size();i++){
        if(isalpha(msg[i])){
            
            char base = isupper(msg[i])? 'A':'a';
            int index = (toupper(msg[i])-'A'+toupper(key[i])-'A')%26;
            encryptString+=(char)(base+index);
        }
       else encryptString+=msg[i];
    }
    return encryptString;
}

string decrypt(string msg,string key){
    string decryptString;
    for(int i=0;i<msg.size();i++){
        if (isalpha(msg[i])) {
            // For both uppercase and lowercase
            char base = isupper(msg[i]) ? 'A' : 'a';
            int index = (toupper(msg[i]) - 'A' - (toupper(key[i]) - 'A') + 26) % 26;
            decryptString += (char)(index + base);
        } else {
            decryptString += msg[i]; // Keep spaces and non-alphabetic characters unchanged
        }
    }
    
    return decryptString;
}


int main()
{
    string key="ayush";
    string msg="geeks for geek";
    
 
    key=generateKey(msg,key);
    string encryptMsg=encrypt(msg,key);
    cout<<"encrypted message : "<<encryptMsg<<endl;
    
    string decryptMsg=decrypt(encryptMsg,key);
    cout<<"decrypted message : "<<decryptMsg<<endl;
    return 0;
}