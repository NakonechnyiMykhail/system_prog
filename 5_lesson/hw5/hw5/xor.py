# Python3 program to implement XOR - Encryption 
  
# The same function is used to encrypt and 
# decrypt 

# Encrypted String: 5<<?p?"<4 
# Decrypted String: Hello World
from os import urandom


def genkey(length: int) -> bytes:
    """Generate key."""
    return urandom(length)
    

def xor_strings(s, t) -> bytes:
    """xor two strings together."""
    if isinstance(s, str):
        # Text strings contain single characters
        return b"".join(chr(ord(a) ^ ord(b)) for a, b in zip(s, t))
    else:
        # Python 3 bytes objects contain integer values in the range 0-255
        return bytes([a ^ b for a, b in zip(s, t)])


def encryptDecrypt(inpString): 
  
    # Define XOR key 
    # Any character value will work 
    xorKey = 'P'; 
  
    # calculate length of input string 
    length = len(inpString); 
  
    # perform XOR operation of key 
    # with every caracter in string 
    for i in range(length): 
      
        inpString = (inpString[:i] + 
             chr(ord(inpString[i]) ^ ord(xorKey)) +
                     inpString[i + 1:]); 
        print(inpString[i], end = ""); 
      
    return inpString; 
  
# Driver Code 
if __name__ == '__main__': 
    # version 1
    #sampleString = "Hello World"; 
  
    ## Encrypt the string 
    #print("Encrypted String: ", end = ""); 
    #sampleString = encryptDecrypt(sampleString); 
    #print("\n"); 
  
    ## Decrypt the string 
    #print("Decrypted String: ", end = ""); 
    #encryptDecrypt(sampleString); 

    # version 2
    message = 'Hello World'
    print('Message:', message)

    key = genkey(len(message))
    print('Key:', key)

    cipherText = xor_strings(message.encode('utf8'), key)
    print('cipherText:', cipherText)
    print('decrypted:', xor_strings(cipherText, key).decode('utf8'))

    # Verify
    if xor_strings(cipherText, key).decode('utf8') == message:
        print('Unit test passed')
    else:
        print('Unit test failed')

  
# This code is contributed by Princi Sing