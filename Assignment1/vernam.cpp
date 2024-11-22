#include<bits/stdc++.h>
using namespace std;

string encrypt(string msg,string key)
{
    string result;
    for(int i=0;i<msg.size();i++)
    {
        result+=msg[i]^key[i];
    }
    return result;
}


int main()
{
    string msg = "Hello";
    string key = "abcde";
    
    string cipher = encrypt(msg,key);
    cout<<"Plain text : "<<msg<<endl;
    cout<<"cipher text : ";
    for(auto c:cipher)
    {
        cout << hex <<((int)c & 0xFF) <<" ";
    }
    
    string PlainText = encrypt(cipher,key);
     cout<<"Plain text : "<<PlainText<<endl;
    
    return 0;
}