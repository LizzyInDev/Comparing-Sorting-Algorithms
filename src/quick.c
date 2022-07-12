/* 
  Reference: Quick Sort
             from codingbot
             https://www.codingbot.net/2013/01/quick-sort-algorithm-and-c-code.html
*/

void quickSort(int arr[20],int low,int high){
  int pivot,j,temp,i;
  if(low<high){
  pivot = low;
  i = low;
  j = high;
  
  while(i<j){
    while((arr[i]<=arr[pivot])&&(i<high)){
    i++;
    }
  
    while(arr[j]>arr[pivot]){
    j--;
    }
    
    if(i<j){ 
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    }
  }
  
  temp=arr[pivot];
  arr[pivot]=arr[j];
  arr[j]=temp;
  quickSort(arr,low,j-1);
  quickSort(arr,j+1,high);
  }
}
