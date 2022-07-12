#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bubble.c"
#include "quick.c"
#include "insertion.c"
#include "selection.c"
#include "heap.c"
#include "merge.c"
#include "generateData.c"

#define	 CPU_TIME (1)

void bubbleSort(int array[], int size);
void quickSort(int arr[],int low,int high);
void countingSort(int array[], int size);
void insertionSort(int array[], int size);
void selectionSort(int array[], int size);
void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int l, int r);
void generateData (int A[], int n);

int main() {
	
	int i, j, a; 	// iterations
	long n;		// size for array
	long N[10] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};	// different sizes for array assigned to n
	int r;		// iteration for run
	// variables for cpu time and met
	double avgMet[6], sumMet[6], met[6];
    struct timespec begin, end; 
    long seconds;
    long nanoseconds;
	
	// for each value of N
	for(i = 0; i < 10; i++) {
		n = N[i];				// set array size 
		int A[n];				// assign size to A array
		int temp[n];		
		GenerateData(A,n);		// Call GenerateData(A, n)
		
		// for each sorting algorithm
		for (a = 0; a < 6; a++) { 		// a < 6 because there are 6 different sorting algorithms
		
			sumMet[a] = 0;
		
			// for r = 1 at least r = 10 number of runs	
			for (r = 1; r <= 10; r++) {
				
				// assigns generated array data to temp array
				for (j=0; j<n; j++)
					temp[j] = A[j];

				// get start cpu time
				if(CPU_TIME)
				    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);    // get start CPU time
			    else
			        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
				
				// call sort funtion 
				switch (a) {
					case 0:
						bubbleSort(temp, n);
						if(r==1)
							printf("Bubble Sort\t\tsize %ld: \n", n);
						break;
	
					case 1:
						insertionSort(temp, n);
						if(r==1)
							printf("Insertion Sort\t\tsize %ld: \n", n);
						break;
	
					case 2:
						selectionSort(temp, n);
						if(r==1)
							printf("Selection Sort\t\tsize %ld: \n", n);
						break;
	
					case 3:
						mergeSort(temp, 0, n-1);
						if(r==1)
							printf("Merge Sort\t\tsize %ld: \n", n);
						break;
	
					case 4:
						quickSort(temp, 0, n-1);;
						if(r==1)
							printf("Quick Sort\t\tsize %ld: \n", n);
						break;
	
					case 5:
						heapSort(temp, n);
						if(r==1)
							printf("Heap Sort\t\tsize %ld: \n", n);
						break;
				}
				
				// get end cpu time	
			    if CPU_TIME 
			        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);  // get end CPU time
			    else
			        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
			        
			    
				// int sorted;
				// printf("Sorted Algo: ");
				// for (sorted=0; sorted<10; sorted++){
				// 	printf("%d ", temp[sorted]);
				// }
				// printf("\n");
				
				
				// compute MET = end cpu time - start cpu time
			    seconds = end.tv_sec - begin.tv_sec;
			    nanoseconds = end.tv_nsec - begin.tv_nsec;
			    met[a] = seconds + nanoseconds*1e-9;	//seconds
			    
			    // print all separate met
//			    printf("MET: %f\n", met[a]);
				
				// record met
				sumMet[a] += met[a];

				// compute and record the avg met
				if (r == 10){
					avgMet[a] = sumMet[a] / 10;
					printf("Average Machine Execution Time(seconds): %f\n", avgMet[a]);
					printf("Average Machine Execution Time(milliseconds): %f\n\n", avgMet[a]*1000);
				}
			}
		}
	}
	return 0;
}
