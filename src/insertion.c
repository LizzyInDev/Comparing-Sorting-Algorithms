/* 
  Reference: Insertion Sort
             from Programmiz
             https://www.programiz.com/dsa/insertion-sort
*/

void insertionSort(int array[], int size) {
	int step, key, j;
	
	for (step = 1; step < size; step++) {
    	key = array[step];
    	j = step - 1;

    	// Compare key with each element on the left of it until an element smaller than it is found.
    	// For descending order, change key<array[j] to key>array[j].
    	while (key < array[j] && j >= 0) {
    		array[j + 1] = array[j];
      		--j;
    	}
    	array[j + 1] = key;
 	}
}

