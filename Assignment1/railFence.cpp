/*
    Assignment No. 1C : RailFence Algorithm
    referce link : https://www.geeksforgeeks.org/rail-fence-cipher-encryption-decryption/
*/


#include<bits/stdc++.h>
using namespace std;


string encrypt(string msg,int key){
    char rail[key][msg.size()];
    
    for(int i=0;i<key;i++)
        for(int j=0;j<msg.size();j++)
            rail[i][j]='\n';
    
    int row=0,col=0;
    bool dir_down=false;
    for(int i=0;i<msg.size();i++){
        
        if(row==0 or row==key-1)
            dir_down =!dir_down;
        
        rail[row][col++]=msg[i];
        dir_down? row++ : row--;
    }
    
    string encrpedMsg;
    for(int i=0;i<key;i++)
        for(int j=0;j<msg.size();j++){
            if(rail[i][j]!='\n')
                encrpedMsg+=rail[i][j];
        }
    
    return encrpedMsg;
}

string decrypt(string msg,int key){
    char rail[key][msg.size()];
    
    for(int i=0;i<key;i++){
        for(int j=0;j<msg.size();j++)
            rail[i][j]='\n';
    }
    
    bool dir_down=false;
    int row=0,col=0;
    for(int i=0;i<msg.size();i++){
        if(row==0 or row==key-1)
            dir_down=!dir_down;
        
        rail[row][col++]='*';
        dir_down?row++:row--;
    }
    
    int index=0;
    for(int i=0;i<key;i++)
        for(int j=0;j<msg.size();j++)
            if(rail[i][j]=='*' and index<msg.size())
                rail[i][j]=msg[index++];
    
    string result;
    row=0,col=0;
    dir_down=false;
    for(int i=0;i<msg.size();i++)
    {
        if(row==0 or row==key-1)
            dir_down=!dir_down;
            
        if(rail[row][col]!='*')
         result+=rail[row][col++];
         
        dir_down?row++:row--;
    }
    
    return result;
}

int main(){
    
    string msg;
    cout<<"Enter message for encryption :"<<endl;
    getline(cin,msg);
    
    int key;
    cout<<"enter Key :"<<endl;
    cin>>key;
    
    string encrpedMsg = encrypt(msg,key);
    cout<<"Encryped message : "<<encrpedMsg<<endl;
    
    string decrpedMsg = decrypt(encrpedMsg,key);
    cout<<"Decryped message : "<<decrpedMsg<<endl;
    
    return 0;
}