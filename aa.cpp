#include <iostream>
using namespace std;
 
// Returns true if there exists a subsequence of `arr[0…n)` with the given sum
bool subsetSum(int arr[], int n, int sum)
{
    // `T[i][j]` stores true if subset with sum `j` can be attained
    // using items up to first `i` items
    bool T[sum + 1][n + 1];
 
    // if 0 items in the list and the sum is non-zero
    for (int j = 1; j <= sum; j++) {
        T[0][j] = false;
    }
 
    // if the sum is zero
    for (int i = 0; i <= n; i++) {
        T[i][0] = true;
    }
 
    // do for i'th item
    for (int i = 1; i <= n; i++)
    {
        // consider all sum from 1 to sum
        for (int j = 1; j <= sum; j++)
        {
            // don't include the i'th element if `j-arr[i-1]` is negative
            if (arr[i - 1] > j) {
                T[i][j] = T[i - 1][j];
            }
            else {
                // find the subset with sum `j` by excluding or including the i'th item
                T[i][j] = T[i - 1][j] || T[i - 1][j - arr[i - 1]];
            }
        }
    }
 
    // return maximum value
    return T[n][sum];
}
 
// Subset Sum Problem
int main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // Input: a set of items and a sum
    int arr[] = { 2, 3, 6, 7, 8, 10 };
    int sum = 9;
 
    // total number of items
    int n = sizeof(arr) / sizeof(arr[0]);
 
    if (subsetSum(arr, n, sum)) {
        cout << "Subsequence with the given sum exists";
    }
    else {
        cout << "Subsequence with the given sum does not exist";
    }
 
    return 0;
}