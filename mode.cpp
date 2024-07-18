#include <stdio.h>
#include<conio.h>

// Function to find and print modes in an array of integers
void findModes(int arr[], int n) {
    int frequency[n];
    int maxCount = 0, i, j;

    // Initialize frequency array to 0
    for (i = 0; i < n; ++i) {
        frequency[i] = 0;
    }

    // Calculate frequency of each element
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (arr[j] == arr[i])
                ++frequency[i];
        }

        // Track the maximum frequency
        if (frequency[i] > maxCount) {
            maxCount = frequency[i];
        }
    }

    printf("Modes: ");
    int modes[n], modeCount = 0;
    for (i = 0; i < n; ++i) {
        // Collect elements that have the highest frequency
        if (frequency[i] == maxCount) {
            // Check if the mode is already in the list of modes
            int isNewMode = 1;
            for (j = 0; j < modeCount; ++j) {
                if (modes[j] == arr[i]) {
                    isNewMode = 0;
                    break;
                }
            }
            if (isNewMode) {
                modes[modeCount++] = arr[i];
            }
        }
    }

    // Print the collected modes
    for (i = 0; i < modeCount; ++i) {
        printf("%d ", modes[i]);
    }
    printf("\n");
}

// Structure to represent a class interval with its frequency
struct ClassInterval {
    float lower;
    float upper;
    int frequency;
};

// Function to calculate the mode of a frequency distribution using class intervals
float calculateMode(struct ClassInterval intervals[], int n) {
    int modalClassIndex = 0;
    int maxFrequency = intervals[0].frequency;

    // Find the modal class (the class with the highest frequency)
    for (int i = 1; i < n; ++i) {
        if (intervals[i].frequency > maxFrequency) {
            maxFrequency = intervals[i].frequency;
            modalClassIndex = i;
        }
    }

    // Extract frequencies of the modal class and its neighbors
    int f1 = intervals[modalClassIndex].frequency;
    int f0 = (modalClassIndex > 0) ? intervals[modalClassIndex - 1].frequency : 0;
    int f2 = (modalClassIndex < n - 1) ? intervals[modalClassIndex + 1].frequency : 0;

    // Calculate class width
    float h = intervals[modalClassIndex].upper - intervals[modalClassIndex].lower;
    printf("Class Width = %f\n", h);

    // Calculate the mode using the formula
    float L = intervals[modalClassIndex].lower;
    float d = (f1 - f0);
    float e = (2 * f1 - f0 - f2);
    printf("Frequency Rise = %f\nFrequency Spread = %f\n", d, e);

    float cp = (d / e) * h;
    printf("Modal Adjustment Factor = %f\n", cp);

    float mode = L + cp;
    return mode;
}

int main() {
    char ch;
    printf("Is it a class interval or not (y/n): ");
    scanf(" %c", &ch); // Added a space before %c to ignore leading whitespace

    if (ch == 'n') {
        int n, i;

        printf("Enter the number of elements: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter the elements: \n");
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        findModes(arr, n);
    } else if (ch == 'y') {
        int n;

        printf("Enter the number of class intervals: ");
        scanf("%d", &n);

        struct ClassInterval intervals[n];

        printf("Enter the lower limit, upper limit, and frequency of each class interval:\n");
        for (int i = 0; i < n; ++i) {
            printf("Class interval %d:\n", i + 1);
            printf("Lower limit: ");
            scanf("%f", &intervals[i].lower);
            printf("Upper limit: ");
            scanf("%f", &intervals[i].upper);
            printf("Frequency: ");
            scanf("%d", &intervals[i].frequency);
        }

        float mode = calculateMode(intervals, n);

        printf("The mode of the given class intervals is: %.2f\n", mode);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}

