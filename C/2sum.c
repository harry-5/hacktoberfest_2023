#include <stdio.h>

// Function to find a pair of numbers with the given sum using loops
void solutionUsingLoop(int arrayOfNumbers[], int length, int sumOfNumbers) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (sumOfNumbers == arrayOfNumbers[i] + arrayOfNumbers[j]) {
                printf("%d %d\n", arrayOfNumbers[i], arrayOfNumbers[j]);
            }
        }
    }
}

// Function to find a pair of numbers with the given sum using two pointers
void solutionUsingTwoPointer(int arrayOfNumbers[], int length, int sumOfNumbers) {
    // Sort the array
    int l = 0;
    int r = length - 1;

    while (l < r) {
        if (arrayOfNumbers[l] + arrayOfNumbers[r] == sumOfNumbers) {
            printf("%d %d\n", arrayOfNumbers[l], arrayOfNumbers[r]);
            break;
        } else if (arrayOfNumbers[l] + arrayOfNumbers[r] < sumOfNumbers) {
            l++;
        } else {
            r--;
        }
    }
}

// Function to find a pair of numbers with the given sum using hashing
void solutionUsingHashing(int arrayOfNumbers[], int length, int sumOfNumbers) {
    int dataSet[10000] = {0}; // Assuming a reasonable upper bound for array values

    for (int i = 0; i < length; i++) {
        int temp = sumOfNumbers - arrayOfNumbers[i];
        if (temp >= 0 && dataSet[temp] == 1) {
            printf("%d %d\n", arrayOfNumbers[i], temp);
        }
        dataSet[arrayOfNumbers[i]] = 1;
    }
}

int main() {
    int arrayOfNumbers[] = {42, 5, 11, 7, 2, 4};
    int length = sizeof(arrayOfNumbers) / sizeof(arrayOfNumbers[0]);
    int sumOfNumbers = 16;

    // Simple solution using loops
    solutionUsingLoop(arrayOfNumbers, length, sumOfNumbers);

    // Two pointer solution
    solutionUsingTwoPointer(arrayOfNumbers, length, sumOfNumbers);

    // Hashing method
    solutionUsingHashing(arrayOfNumbers, length, sumOfNumbers);

    return 0;
}

