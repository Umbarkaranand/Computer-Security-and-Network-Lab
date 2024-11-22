/******************************************************************************
Assignmnet No. 2 : Monoalphabetic Cipher
refernce link : https://onecompiler.com/cpp/3wjrmt5qn
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
unordered_map<char,char> mp;

void mapFun(){
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    random_device rd;
    mt19937 g(rd());
    shuffle(alphabet.begin(), alphabet.end(), g);
    for(int i=0;i<alphabet.size();i++){
        mp['a'+i]=alphabet[i];
    }
    
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    shuffle(alphabet.begin(), alphabet.end(), g);
    for(int i=0;i<alphabet.size();i++){
        mp['A'+i]=alphabet[i];
    }
}

string encrypt(string msg){
    string returnMsg;
    for(int i=0;i<msg.size();i++){
        if(isalpha(msg[i]))
            returnMsg+=mp[msg[i]];
        else returnMsg+=msg[i];
    }
    
    return returnMsg;
}

string decrypt(string msg){
    string returnMsg;
    for(int i=0;i<msg.size();i++){
        if(isalpha(msg[i])){
            for(auto a:mp){
                if(a.second==msg[i]){
                    returnMsg+=a.first;
                    break;
                }
            }
        }
        else returnMsg+=msg[i];
    }
    
    return returnMsg;
}

int main()
{
     
    mapFun();
    string msg;
    cout<<"enter message for encryption :"<<endl;
    getline(cin,msg);
    
    string encryptedMsg = encrypt(msg);
    cout<<"Encrypted message is : "<<encryptedMsg<<endl;
    
    string decryptedMsg = decrypt(encryptedMsg);
    cout<<"Decrypted message is : "<<decryptedMsg<<endl;
    
    return 0;
}