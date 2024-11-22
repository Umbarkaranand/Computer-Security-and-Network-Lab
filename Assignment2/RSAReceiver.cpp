#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

long long mod_expr(long long base,long long expr,long long mod){
    long long result=1;
    base=base%mod;
    while(expr>0){
        if(expr%2==1){
            result=(base*result)%mod;
        }
        expr=expr>>1;
        base=(base*base)%mod;
    }
    
    return result;
}

long long decrypt(long long msg,long long d,long long n){
    return mod_expr(msg,d,n);
}
int main()
{
    long long d,n;
    
    ifstream keyFile("key.txt");
    keyFile >> d >> n;
    keyFile.close();
    
    cout<<"reciever private key :("<<d<<","<<n<<")\n";
    
    long long ciphertext;
    ifstream inFile("message.txt");
    inFile >> ciphertext;
    inFile.close();
    
    cout<<"received encrypted message is : "<<ciphertext<<endl;
    auto start_decrypt = high_resolution_clock::now();
    long long plainText = decrypt(ciphertext,d,n);
    auto end_decrypt = high_resolution_clock::now();
    
    cout<<"received plain message is : "<<plainText<<endl;
    return 0;
}