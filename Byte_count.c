#include <stdio.h>

#define MAX_MESSAGE_SIZE 1024

void concatenateFrames(char destination[], char source[], int destLength, int sourceLength) {
    // Find the end of the destination string
    while (destination[destLength] != '\0') {
        ++destLength;
    }

    // Append the source data to the destination
    for (int i = 0; i < sourceLength; ++i) {
        destination[destLength++] = source[i];
    }
}

int main() {
    char concatenatedMessage[MAX_MESSAGE_SIZE] = {'\0'};
    int totalLength = 0;
    int numFrames;

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    for (int frame = 0; frame < numFrames; ++frame) {
        int numDataBits;

        printf("Enter the size of frame %d: ", frame + 1);
        scanf("%d", &numDataBits);

        if (numDataBits <= 1 || numDataBits > 8) {
            printf("Invalid size for frame %d. It should be between 2 and 8 bits.\n", frame + 1);
            return 1;
        }

        concatenatedMessage[totalLength++] = numDataBits;

        printf("Enter %d data bits for frame %d: ", numDataBits - 1, frame + 1);
        for (int i = 0; i < numDataBits - 1; ++i) {
            scanf("%d", &concatenatedMessage[totalLength]);
            ++totalLength;
        }
    }

    printf("Final concatenated data: ");
    for (int i = 0; i < totalLength; ++i) {
        printf("%d ", concatenatedMessage[i]);
    }
    printf("\n");

    return 0;
}
