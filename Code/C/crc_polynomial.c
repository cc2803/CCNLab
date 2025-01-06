//Algorithm:
//1.Given a bit string, append 0S to the end of it (the number of 0s is the same as the degree of the generator polynomial) let B(x) be the polynomial corresponding to B.
//2.Divide B(x) by some agreed on polynomial G(x) (generator polynomial) and determine the remainder R(x). This division is to be done using Modulo 2 Division.
//3.Define T(x) = B(x) –R(x) (T(x)/G(x) => remainder 0)
//4.Transmit T, the bit string corresponding to T(x).
//5,Let T’ represent the bit stream the receiver gets and T’(x) the associated polynomial. The receiver divides T1 (x) by G(x). If there is a 0 remainder, the receiver concludes T = T’ and no error occurred otherwise, the receiver concludes an error occurred and requires a retransmission.

#include<stdio.h>
#include<string.h>

#define POLY_LENGTH strlen(generator)

char inputData[128], checksum[128], generator[] = "10110";
int dataLength, index, shift;

void xorOperation() {
    for (shift = 1; shift < POLY_LENGTH; shift++) {
        checksum[shift] = (checksum[shift] == generator[shift]) ? '0' : '1';
    }
}

void calculateChecksum() {
    for (index = 0; index < POLY_LENGTH; index++) {
        checksum[index] = inputData[index];
    }
    do {
        if (checksum[0] == '1') {
            xorOperation();
        }
        for (shift = 0; shift < POLY_LENGTH - 1; shift++) {
            checksum[shift] = checksum[shift + 1];
        }
        checksum[shift] = inputData[index++];
    } while (index <= dataLength + POLY_LENGTH - 1);
}

int main() {
    printf("\nEnter data: ");
    scanf("%s", inputData);
    
    printf("\nGenerating Polynomial is: %s", generator);
    
    dataLength = strlen(inputData);
    for (index = dataLength; index < dataLength + POLY_LENGTH - 1; index++) {
        inputData[index] = '0';
    }
    
    printf("\nModified data is: %s", inputData);
    
    calculateChecksum();
    
    printf("\nChecksum is: %s", checksum);
    
    // Prepare for receiver side
    for (index = dataLength; index < dataLength + POLY_LENGTH - 1; index++) {
        inputData[index] = checksum[index - dataLength];
    }
    
    printf("\nFinal codeword is: %s", inputData);
    
    int testError, errorPos;
    printf("\nTest error detection (0 = Yes, 1 = No)? ");
    scanf("%d", &testError);
    
    if (testError == 0) {
        printf("\nEnter position to insert error: ");
        scanf("%d", &errorPos);
        
        // Flip the bit at the error position
        inputData[errorPos] = (inputData[errorPos] == '1') ? '0' : '1';
        
        printf("\nErroneous data: %s", inputData);
        printf("\nError detected");
    } else {
        printf("\nNo error detected");
    }
    
    return 0;
}

