#include<stdio.h>
#include<conio.h> // Note: conio.h is not standard and may not be available on all compilers

int main() {
    int number, N = 0, i;
    char ch;
    float a, b, e, d, mid, c, sum = 0, mean;
    // Initialize an array with a fixed size; this should be dynamic based on input
    int z[100]; // Assume a maximum of 100 elements for simplicity, adjust as needed
    
    printf("Is it a class interval or not (y/n): ");
    scanf(" %c", &ch); // Added a space before %c to ignore leading whitespace
    
    if (ch == 'n') {
        printf("How many numbers: ");
        scanf("%d", &number);
        
        for (i = 0; i < number; i++) {
            printf("Enter the number: ");
            scanf("%f", &a);
            printf("Enter the frequency: ");
            scanf("%f", &b);
            c = a * b;
            z[i] = c;
            N += b;
        }
    } else if (ch == 'y') {
        printf("How many intervals: ");
        scanf("%d", &number);
        
        for (i = 0; i < number; i++) {
            printf("Enter the lower class: ");
            scanf("%f", &e);
            printf("Enter the upper class: ");
            scanf("%f", &d);
            mid = (e + d) / 2;
            printf("Enter the frequency: ");
            scanf("%f", &b);
            c = mid * b;
            z[i] = c;
            N += b;
        }
    } else {
        printf("Invalid input.\n");
        return 1; // Exit the program with an error code
    }
    
    // Calculate the sum of all values in the array z
    for (i = 0; i < number; i++) {
        sum += z[i];
    }
    
    // Calculate the mean
    mean = sum / N;
    
    // Output the sum of all values and the mean
    printf("Sum of all: %f\n", sum);
    printf("Mean: %f\n", mean);
    
    return 0;
}

