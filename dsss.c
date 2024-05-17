#include <stdio.h>

#define N 11  // Length of Barker code

int data_sequence[N] = {1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0};  // Sequence for 1
int complement_sequence[N] = {0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1};  // Sequence for 0 

void correlate(int *spread_data, int data_length, int *data_sequence, int *complement_sequence, int *recovered_data) {
    for (int i = 0; i < data_length; i++) {
        int corr1 = 0, corr0 = 0;
        for (int j = 0; j < N; j++) {
            if (spread_data[i * N + j] == data_sequence[j]) {
                corr1++;
            }
            if (spread_data[i * N + j] == complement_sequence[j]) {
                corr0++;
            }
        }
        if (corr1 > corr0) {
            recovered_data[i] = 1;
        } else {
            recovered_data[i] = 0;
        }
    }
}

int main() {
    int data_length;
    printf("Enter the length of the data: ");
    scanf("%d", &data_length);

    int data[data_length];
    printf("Enter the data (0s and 1s): ");
    for (int i = 0; i < data_length; i++) {
        scanf("%d", &data[i]);
    }

    // Spread the data using appropriate sequence
    int spread_data[data_length * N];
    for (int i = 0; i < data_length; i++) {
        if (data[i] == 1) {
            // Use data_sequence for 1
            for (int j = 0; j < N; j++) {
                spread_data[i * N + j] = data_sequence[j];
            }
        } else {
            // Use complement_sequence for 0
            for (int j = 0; j < N; j++) {
                spread_data[i * N + j] = complement_sequence[j];
            }
        }
    }

    // Print the Original data
    printf("Original data: ");
    for (int i = 0; i < data_length; i++) {
        printf("%d", data[i]);
    }
    printf("\n");

    // Print the spreading code
    printf("Spreading code: ");
    for (int i = 0; i < N; i++) {
        printf("%d", data_sequence[i]);
    }
    printf("\n");    

    // Print the spread data
    printf("Spread data: ");
    for (int i = 0; i < data_length * N; i++) {
        printf("%d", spread_data[i]);
    }
    printf("\n");

    // Despread the data
    int recovered_data[data_length];
    correlate(spread_data, data_length, data_sequence, complement_sequence, recovered_data);

    // Print the recovered data
    printf("Recovered data: ");
    for (int i = 0; i < data_length; i++) {
        printf("%d", recovered_data[i]);
    }
    printf("\n");

    return 0;
}
