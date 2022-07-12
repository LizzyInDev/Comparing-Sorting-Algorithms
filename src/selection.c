/* 
  Reference: Selection Sort
             from edureka!
             https://www.edureka.co/blog/selection-sort-in-c/#:~:text=with%20it%20then%2C-,Selection%20Sort%20in%20C,smaller%20than%20the%20first%20element.
*/

void selectionSort(int array[], int n) {
	int i, j, position, swap;

	for(i = 0; i < (n - 1); i++) {
		position=i;
		for(j = i + 1; j < n; j++) {
			if(array[position]>array[j])
			position=j;
		}
		if (position != i) {
			swap=array[i];
			array[i]=array[position];
			array[position]=swap;
		}
	}
}
