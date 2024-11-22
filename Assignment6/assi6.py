import hashlib 
import random

def gcd(a,b):
    while b!=0:
        a,b=b,a%b
    
    return a

def is_prime(num):
    
    if(num<=1):
        return False
    
    for i in range (2,num):
        if(num%i==0):
            return False
    
    return True
    

def modInverse(a,m):
    for i in range (1,m):
        if (a*i)%m==1:
            return i;
            
    return None
    
def genrateKey():
    p=q=1
    
    while not is_prime(p):
        p=random.randint(100,1000)
        
    while not is_prime(q) or p==q:
        q=random.randint(100,1000)
        
    n=p*q
    phi=(p-1)*(q-1)
    e=random.randint(1,phi)
    while gcd(e,phi)!=1:
        e=random.randint(1,phi)
    
    d=modInverse(e,phi)
    
    return ((e,n),(d,n))
    
    
def rsa_encrypt(msg,public_key):
    e,n=public_key
    encrypt_msg=[pow(ord(char),e,n) for char in msg]
    return encrypt_msg

def rsa_decrypt(msg,private_key):
    d,n=private_key
    decrypt_msg=''.join([chr(pow(char,d,n)) for char in msg])
    return decrypt_msg
    
def signgenrate(msg,private_key):
    hash_msg = hashlib.sha256(msg.encode()).hexdigest()
    signature = rsa_encrypt(hash_msg,private_key)
    return signature

def verifysign(msg,signature,public_key):
    hash_msg = hashlib.sha256(msg.encode()).hexdigest()
    verify = rsa_decrypt(signature,public_key)
    return verify==hash_msg

if __name__=="__main__":
    print("Generating RSA key..")
    public_key,private_key=genrateKey()
    print("Public key : ",public_key)
    print("private key : ",private_key)
    
    msg="annad"
    encrypt_msg = rsa_encrypt(msg,public_key)
    print("Plain test :",msg)
    print("Enrypted message :",encrypt_msg)
    signature = signgenrate(msg,private_key)
    print("Signature : ",signature)
    
   
    decrypt_msg=rsa_decrypt(encrypt_msg,private_key)
    isSignatureValid = verifysign(decrypt_msg,signature,public_key)
    print("decrypt message :",decrypt_msg)
    
    if(isSignatureValid):
        print("signature is valid message intigrity verified")
    else:
        print("Invalid signature")