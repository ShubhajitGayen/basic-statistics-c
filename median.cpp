#include<stdio.h>
#include<conio.h> // Note: conio.h is not standard and may not be available on all compilers

// Function to calculate the median for class intervals
double calculateMedian(int n, int intervals[][2], int frequencies[], int numIntervals) {
    int totalFrequency = 0;
    for (int i = 0; i < numIntervals; i++) {
        totalFrequency += frequencies[i];
    }
    
    int medianClassIndex = 0;
    int cumulativeFrequency = 0;
    for (int i = 0; i < numIntervals; i++) {
        cumulativeFrequency += frequencies[i];
        if (cumulativeFrequency >= totalFrequency / 2) {
            medianClassIndex = i;
            break;
        }
    }
    
    int lowerBoundary = intervals[medianClassIndex][0];
    int cumulativeFrequencyBeforeMedian = cumulativeFrequency - frequencies[medianClassIndex];
    int medianFrequency = frequencies[medianClassIndex];
    int classWidth = intervals[medianClassIndex][1] - intervals[medianClassIndex][0];
    
    double median = lowerBoundary + ((double)(totalFrequency / 2 - cumulativeFrequencyBeforeMedian) / medianFrequency) * classWidth;
    
    return median;
}

// Function to perform bubble sort on an array in increasing order
void bubbleSort(int arr[], int number) {
    int i, j, temp;
    for (i = 0; i < number-1; i++) {
        for (j = 0; j < number-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    char ch;
    printf("Is it a class interval or not (y/n): ");
    scanf(" %c", &ch); // Added a space before %c to ignore leading whitespace

    if (ch == 'n') {
        int number, i, p,q; // Moved i and p declaration to after input for number
        printf("How many numbers: ");
        scanf("%d", &number);
        
        int arr[number]; // Variable-length array declaration
        
        // Input data into array
        for (i = 0; i < number; i++) {
            printf("Enter your data: ");
            scanf("%d", &arr[i]);
        }

        // Sort the array in increasing order
        bubbleSort(arr, number);

        // Print sorted array
        printf("Data in increasing order: ");
        for (i = 0; i < number; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Finding the median
     if (number % 2 == 0) {
     float r;
             p = (number / 2) - 1;
             q=number/2;
          r=(arr[p]+arr[q])/2;
            printf("Median: %f\n",r);
        }
            else {
            	
            p = ((number+1) / 2) - 1; // Corrected calculation for even number of elements
             
            printf("Median: %f\n", arr[p]);
        } 
    }
	 else if (ch == 'y')
	  {
     int numIntervals;
    printf("Enter the number of class intervals: ");
    scanf("%d", &numIntervals);

    int intervals[numIntervals][2];
    int frequencies[numIntervals];

    printf("Enter the class intervals and their frequencies:\n");
    for (int i = 0; i < numIntervals; i++) {
        printf("Lower Class Interval %d: ", i + 1);
        scanf("%d", &intervals[i][0]);
         printf("Upper ClassInterval %d: ", i + 1);
        scanf("%d",  &intervals[i][1]);
        printf("Frequency %d: ", i + 1);
        scanf("%d", &frequencies[i]);
    }

    double median = calculateMedian(numIntervals, intervals, frequencies, numIntervals);

    printf("The median for the class intervals is: %.2f\n", median);
    } 
	else {
        printf("Invalid input\n");
    }

    return 0;
}

