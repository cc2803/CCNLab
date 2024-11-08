'''
A simple program to illustrate the use of string slicing to insert bits at appropriate positions to ensure errorless transfer 
of data from transmitter to receiver using the bit stuffing encoding method.

The Algorithm involves checking for existence of flag as a substring in the data entered. If yes, an extra "1" is appended to
the string data to ensure that the substring isnt mistaken for a flag and thus avoid faulty transmission of data.
'''

flag = "01111110"

while True:
    data = input("Enter data to be transmitted (BINARY): ")
    print()

    if len(data)!=16:
        print("Incorrect data length entered, Please enter valid input!\n")

    for i in data:
        if i not in "01":
            print("Uh Oh, Incorrect data format/length, expected binary\n")
            break
    break #to exit this loop once valid input is obtained

if flag in data:
    index = data.find(flag)+len(flag)-2
    updated_data = data[:index]+"0"+data[index:]
    print(f"Updated data is:\t{updated_data}")
    
else:
    print("DATA: \t",data)
    


