//Aim: To write and execute program for character stuffing and de-stuffing.
//Theory: In character stuffing, at the starting an ASCII sequence DLESTX and at the end DLEETX is transmitted for synchronization But when DLE occurs in the data itself then the systems adds one more DLE alone with present one so at the receiver it detects one DLE such that DLE of data will be safe.
//Example:
//i)	Original data : MSRITECE
//Stuffed data: DLESTX MSRITECE DLEETX
//ii)	Original data DLE MSRITECEDLE
//Stuffed data: DLESTX DLEDLE MSRITECEDLE DLE DLEETX

#include <stdio.h>
#include <string.h>

void byteStuffing(char *input, char *output) {
    int j = 0;
    const char *start = "DLE STX ";
    const char *end = " DLE ETX";

    // Add start delimiter
    strcpy(output, start);
    j = strlen(output);

    // Process input
    for (int i = 0; input[i] != '\0'; i++) {
        if (strncmp(&input[i], "DLE", 3) == 0) {
            // Escape DLE
            strcpy(&output[j], "DLE DLE ");
            j += 8;
            i += 2;  // Skip the "DLE" characters in the input
        } else if (strncmp(&input[i], "ETX", 3) == 0) {
            // Escape ETX
            strcpy(&output[j], "DLE ETX ");
            j += 8;
            i += 2;  // Skip the "ETX" characters in the input
        } else {
            // Copy normal characters
            output[j++] = input[i];
        }
    }

    // Add end delimiter
    strcpy(&output[j], end);
}

int main() {
    char input[100], output[200];

    printf("Enter the data:\n");
    scanf("%[^\n]", input);

    byteStuffing(input, output);

    printf("\nByte stuffed stream is:\n%s\n", output);

    return 0;
}
