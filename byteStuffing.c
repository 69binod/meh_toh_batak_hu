#include <stdio.h>
#include <string.h>

#define FLAG "01111110" // Binary representation of FLAG
#define ESC "00011011"  // Binary representation of ESC

void byteStuff(char *input, char *stuffed) {
    int i, j;
    j = 0;

    // Prepend starting flag byte for the frame
    strcpy(stuffed, FLAG);
    j += strlen(FLAG);

    for (i = 0; input[i] != '\0'; i++) {
        if (strncmp(&input[i], FLAG, 8) == 0 || strncmp(&input[i], ESC, 8) == 0) {
            // If FLAG or ESC is found in the data, prepend it with ESC
            strcat(stuffed, ESC);
            j += strlen(ESC);
        }
        strncat(stuffed, &input[i], 1);
        j += 1;
    }

    // Append ending flag byte for the frame
    strcat(stuffed, FLAG);
    j += strlen(FLAG);

    stuffed[j] = '\0'; // Null-terminate the stuffed string
}

void byteDeStuff(char *stuffed, char *destuffed) {
    int i, j;
    j = 0;

    // Skip the starting flag byte
    for (i = 8; strncmp(&stuffed[i], FLAG, 8) != 0; i += 8) {
        if (strncmp(&stuffed[i], ESC, 8) == 0) {
            // Skip the escape character
            i += 8;
        }
        strncpy(&destuffed[j], &stuffed[i], 8);
        j += 8;
    }

    destuffed[j] = '\0'; // Null-terminate the destuffed string
}

int main() {
    char input[1024];
    char stuffed[2048]; // Increased size to accommodate potential stuffing
    char destuffed[1024];

    printf("Enter data to be stuffed: ");
    scanf("%s", input);

    byteStuff(input, stuffed);
    printf("Stuffed Frame: %s\n", stuffed);

    byteDeStuff(stuffed, destuffed);
    printf("Destuffed Frame: %s\n", destuffed);

    return 0;
}
