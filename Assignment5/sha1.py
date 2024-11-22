import hashlib

def compute_sha1_hash(message):
   
    sha1_hash = hashlib.sha1()
    
    sha1_hash.update(message.encode())
    
    # Return the hexadecimal digest of the hash
    return sha1_hash.hexdigest()
    
def main():
    message = input("Enter message : ")
    hashResult = compute_sha1_hash(message)
    print("hash code :",hashResult)
    
if __name__ == "__main__":
    main()