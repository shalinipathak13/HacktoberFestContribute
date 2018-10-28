#include <iostream>
#include <algorithm>
using namespace std;

// a function to search an elements using binary search method

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;

        // If the element is present at the middle
        if (arr[mid] == x)  return mid;

        // If element is smaller than mid, then it can only be present in left sub-array
        if (arr[mid] > x)
          return binarySearch(arr, l, mid-1, x);

        // If element is greater than mid, then it can only be present in right sub-array
        return binarySearch(arr, mid+1, r, x);
    }

    // We reach here when element is not present in array
    return -1;
}

// Prints intersection of two arrays
void printIntersection(int arr1[], int arr2[], int m, int n)
{
    // Before finding intersection, make sure arr1[0..m-1]
    // is smaller
    if (m > n)
    {
        int *tempp = arr1;
        arr1 = arr2;
        arr2 = tempp;

        int temp = m;
        m = n;
        n = temp;
    }

    // Now arr1[] is smaller

    // Sort smaller array arr1[0..m-1]
    sort(arr1, arr1 + m);

    // Search every element of bigger array in smaller
    // array and print the element if found
    for (int i=0; i<n; i++)
        if (binarySearch(arr1, 0, m-1, arr2[i]) != -1)
            cout << arr2[i] << " ";
}

//Main function
int main()
{
    int arr1[] = {6, 3, 2, 1, 5, 8};
    int arr2[] = {3, 8, 32, 15, 7};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);

    cout << "\nIntersection of two arrays is: \n";
    printIntersection(arr1, arr2, m, n);
    return 0;
}
