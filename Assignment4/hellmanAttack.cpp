#include<bits/stdc++.h>
using namespace std;

long long modExp(long long base,long long expr,long long mod){
    base=base%mod;
    long long result=1;
    while(expr>0){
        if(expr%2==1){
            result=(result*base)%mod;
        }
        expr=expr>>1;
        base=(base*base)%mod;
    }
    return result;
}

int main()
{
    long long p=21;
    long long g=2;
    
    //private key
    long long a=6;
    long long b=15;
    long long c=7;
    
    //public key
    long long A=modExp(g,a,p);
    long long B=modExp(g,b,p);
    long long C=modExp(g,c,p);
    
    int choice;
    cout << "Choose an option:\n";
    cout << "1. Exchange Public Keys between Sidd and Namu\n";
    cout << "2. Perform Man-In-The-Middle Attack by Sahil\n";
    cin >> choice;
    
    if (choice == 1) {
    // Public key exchange between Sidd and Namu
    cout << "A's Public Key: " << A << endl;
    cout << "B's Public Key: " << B << endl;
    // Sidd and Namu compute their shared secret
    long long AA = modExp(B, a, p);
    long long BB = modExp(A, b, p);
    cout << "A computes shared secret: " << AA << endl;
    cout << "B computes shared secret: " << BB << endl;
    if (AA == BB) {
    cout << "Secure communication established." << endl;
    } else {
    cout << "Shared secrets do not match!" << endl;
    }
}
    else if(choice==2){
        cout << "A's Public Key: " << A << endl;
        cout << "B's Public Key: " << B << endl;
        cout << "C's Public Key: " << C << endl;
        
        long long AC = modExp(C,a,p);
        cout<<"A computes shared secrets with C:"<<AC<<endl;
        long long BC = modExp(C,b,p);
        cout<<"B computes shared secrets with C:"<<BC<<endl;
        long long CA = modExp(A,c,p);
        cout<<"C computes shared secrets with A:"<<CA<<endl;
        long long CB = modExp(B,c,p);
        cout<<"C computes shared secrets with B:"<<CB<<endl;
        
        if(AC==CA and BC==CB)
            cout<<"Man-In-The-Middle attack successful. Sahil can intercept and modify messages." << endl;
        else
            cout<<"attack failes";
    }

    
    return 0;
}