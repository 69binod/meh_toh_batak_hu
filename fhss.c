#include <stdio.h>

int main()
{
    // Declare variables
    int data_length;

    // Prompt the user to enter the length of the data
    printf("Enter the length of the data: ");

    // Read the length of the data entered by the user
    scanf("%d", &data_length);

    // Declare an array to store the entered data
    int data[data_length];
    int expanded_data[data_length];

    // Prompt the user to enter the data (0s and 1s)
    printf("Enter the data (0s and 1s): ");

    // Loop to read each data bit entered by the user
    for (int i = 0; i < data_length; i++)
    {
        // Read each data bit and store it in the array
        scanf("%d", &data[i]);
    }

    // Print the expanded data
    printf("Expanded data: \n");

    // Loop to generate and print the expanded data sequence
    int j = 1;
    for (int i = data_length - 1; i >= 0; i--)
    {
        expanded_data[i] = data[i] * j;
        j = j * 10;
    }
    for (int i = 0; i < data_length; i++)
    {
        printf("%0*d ", data_length, expanded_data[i]); // dynamically set field width based on data_length
        printf("\n"); // Move to the next line for the next sequence
    }
    printf("-----------------------------\n");
    // printing the fhss signal according to time
    for (int i = 0; i < data_length; i++)
    {
        printf("t%d\t", i);
        for(int j= i; j >= 0; j--){
            printf("%0*d ", data_length, expanded_data[i]); // dynamically set field width based on data_length
        }
        printf("\n");
    }
    printf("\n");

    
    // Return 0 to indicate successful completion of the program
    return 0;
}
