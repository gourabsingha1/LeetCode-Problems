//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int nums[], int low, int mid, int high)
    {
        int left = low, right = mid + 1;
        vector<int> temp;
        while (left <= mid && right <= high) {
            if (nums[left] < nums[right]){
                temp.push_back(nums[left++]);
            }
            else {
                temp.push_back(nums[right++]);
            }
        }
        while (left <= mid) {
            temp.push_back(nums[left++]);
        }
        while(right <= high) {
            temp.push_back(nums[right++]);
        }
        for (int i = 0; i < temp.size(); i++)
        {
            nums[low + i] = temp[i];
        }
    }
    public:
    void mergeSort(int nums[], int low, int high)
    {
        if(low >= high) {
            return;
        }
        // divide
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        // merge
        merge(nums, low, mid, high);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends