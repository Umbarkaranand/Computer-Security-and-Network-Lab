#include <iostream>
#include <string>
using namespace std;


string scrambeledDecrypt(string msg){
    int n = msg.size();
    int mid=n/2;
    string left = msg.substr(0,mid);
    string right = msg.substr(mid);
    return right+left;
}

string decryptSubstitude(string msg,int key){
    string result;
    for(auto a:msg){
        result+=char((a-key+256)%256);
    }
    return result;
}

string decrypt(string msg,int key){
  
    string scrambeledDecryptString = scrambeledDecrypt(msg);
    return decryptSubstitude(scrambeledDecryptString,key);
}

string substitude(string msg,int key){
    string result;
    for(auto a:msg){
        result+=char((a+key)%256);
    }
    return result;
}

string scrambeledEncrypt(string msg){
    int n = msg.size();
    int mid = (n+1)/2;
    string left = msg.substr(0,mid);
    string right = msg.substr(mid);
    return right+left;
}
string encrypt(string msg,int key){
   
    string substitudeString = substitude(msg,key);
    return scrambeledEncrypt(substitudeString);
}
// Main
int main() {
    string msg;
    cout << "Enter the message to encrypt: ";
    cin >> msg;

    int key;
    cout << "Enter substitution key: ";
    cin >> key;

    string encryptedMsg = encrypt(msg, key);
    cout << "Encrypted message: " << encryptedMsg << endl;

    string decryptedMsg = decrypt(encryptedMsg, key);
    cout << "Decrypted message: " << decryptedMsg << endl;

    return 0;
}
