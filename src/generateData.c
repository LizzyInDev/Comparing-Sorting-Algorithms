// Generate Data
// A - array	n - array size

void GenerateData(int A[], int n) {
	
	int i;
	time_t Random;
	srand((unsigned)time(&Random));

	for(i = 0; i < n; i++)
		A[i] = rand();
		
}
