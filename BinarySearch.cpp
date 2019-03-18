//Stuart Spiegel
//Date: 2/20/2019

#include <iostream>
using namespace std;

//recursive implemenation of binary search
//returns the location of x in the given array [1...r]
//if its present, otherwise its returns the sentinel value -1
//l: split the array into the left half
//r: split the array into the right half
int binarySearch(int arr[], int l, int r, int x)
{
  if (r >= 1){
    int mid = l + (r - 1) / 2; //get middle element

    //case0: the element is present at the middle
    if(arr[mid] == x){
      return mid;
    }
      //case1: left sub array
        // If element is smaller than mid, then
       // it can only be present in left subarray
       if (arr[mid] > x)
           return binarySearch(arr, l, mid - 1, x);

        //case2: right sub array
       //only possibility left is the element is in right subarray
       return binarySearch(arr, mid + 1, r, x);

  }

  //if the element is not present in the array 
  return -1;
}

//main driver function
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}
