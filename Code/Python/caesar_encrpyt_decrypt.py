alphabets = "abcdefghijklmnopqrstuvwxyz"
alpha_list = [i for i in alphabets]
l = len(alpha_list)
data=input("Enter some data (string): \t")
data_list=list(data.lower())
key=int(input("Enter a key index: preferably 0-3: \t"))


def encrypt(data_list):
    newchar=""
    res=""
    for i in data_list:
        if i in alpha_list:
            for j in range(l):
                if alpha_list[j]==i and ord(i)+key<=122:
                    newchar=chr((ord(i)+key)%123)
                    res+=newchar
                elif alpha_list[j]==i and ord(i)+key>122:
                    newchar=chr((ord(i)+key)%122+96)
                    res+=newchar
        else:
            res+=i
    return res
    
def decrypt(encrypted_text,key):
    newchar=""
    res=""
    for i in encrypted_text:
        if i in alpha_list:
            for j in range(l):
                if alpha_list[j]==i and ord(i)-key>=97:
                    newchar=chr((ord(i)-key))
                    res+=newchar
                elif alpha_list[j]==i and ord(i)-key<97:
                    newchar=chr((ord(i)-key)+26)
                    res+=newchar
        else:
            res+=i
    return res
    
enc_res = encrypt(data_list)    

print("The cipher text for this data is: \t", enc_res)
print()

while True:
    n = int(input("Enter the key index for decryption: \t"))
    if n!=key:
        print("Try again, wrong guess!")
    else:
        dec_res = decrypt(enc_res,n)        

        print("decrypted text is: \t",dec_res)
        break

#Note: fix for previously ignoring special characters added, possible issues- Upper/Lowercase conversions
