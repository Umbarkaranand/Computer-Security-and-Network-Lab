#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;

long long generatePrime(long long n){
    while(true){
        bool is_prime=true;
        for(int i=2;i<sqrt(n);i++){
            if(n%i==0){
                is_prime=false;
                break;
            }
        }
        if(is_prime)return n;
        n++;
    }
}

long long gcd(long long a,long long b){
    while(b!=0){
        long long t=b;
        b=a%b;
        a=t;
    }
    return a;
}

void generateKey(long long &e,long long &d,long long &n){
    long long p = generatePrime(61);
    long long q = generatePrime(67);
    
    n=p*q;
    long long phi=(p-1)*(q-1);
    
    e=3;
    while(gcd(e,phi)!=1){
        e+=2;
    }
    
    d=0;
    for(int k=1;;k++){
        if((k*phi+1)%e==0){
            d=(k*phi+1)/e;
            break;
        }
    }
}


long long modexpr(long long base,long long expr,long long mod){
    long long result=1;
    base=base%mod;
    
    while(expr>0){
        if(expr%2==1){
            result=(base*result)%mod;
        }
        expr=expr>>1;
        base = (base*base)%mod;
    }
    
    return result;
}

long long encryptmsg(long long base,long long expr,long long mod){
    return modexpr(base,expr,mod);
}

int main()
{
    long long e,d,n;
    
    auto start_keygen = high_resolution_clock::now();
    generateKey(e,d,n);
    auto end_keygen = high_resolution_clock::now();
    auto keyDuration = duration_cast<microseconds>(end_keygen-start_keygen);
    
    cout<<"senders end :"<<endl;
    cout<<"senders public key : ("<<e<<","<<n<<")\n";
    
    long long msg;
    cout<<"Enter message for encryption (numeric only):";
    cin>>msg;
    
    auto start_encrypt = high_resolution_clock::now();
    long long ciphertext = encryptmsg(msg,e,n);
    auto end_encrypt = high_resolution_clock::now();
    auto keygenDuration = duration_cast<microseconds>(end_encrypt-start_encrypt);
    
    cout<<"encrypted text : "<<ciphertext;
    ofstream outFile("message.txt");
    outFile << ciphertext;
    outFile.close();
    
   ofstream keyFile("key.txt");
    keyFile << d <<" "<< n;
    keyFile.close();
    return 0;
}