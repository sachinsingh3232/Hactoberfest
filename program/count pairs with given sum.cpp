// Count pairs with given sum
// Easy Accuracy: 41.59% Submissions: 87324 Points: 2
// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

// Example 1:

// Input:
// N = 4, K = 6
// arr[] = {1, 5, 7, 1}
// Output: 2
// Explanation:
// arr[0] + arr[1] = 1 + 5 = 6
// and arr[1] + arr[3] = 5 + 1 = 6.

// Example 2:

// Input:
// N = 4, X = 2
// arr[] = {1, 1, 1, 1}
// Output: 6
// Explanation:
// Each 1 will produce sum 2 with any 1.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function getPairsCount() which takes arr[], n and k as input parameters and returns the number of pairs that have sum K.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 105
// 1 <= K <= 108
// 1 <= Arr[i] <= 106

// // { Driver Code Starts
// //Initial template for C++

// #include <bits/stdc++.h>
// using namespace std;

//  // } Driver Code Ends
// //User function template for C++

// class Solution{
// public:
//     int getPairsCount(int arr[], int n, int k) {
//         // code here
//         unordered_map<int,int>m;
//        long long cnt=0;
//        for(int i=0;i<n;i++){
//            if(m.find(k-arr[i])!=m.end()){
//                cnt+=m[k-arr[i]];
//            }
//            m[arr[i]]++;
//        }
//        return cnt;
//     }
// };

// // { Driver Code Starts.

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, k;
//         cin >> n >> k;
//         int arr[n];
//         for (int i = 0; i < n; i++) {
//             cin >> arr[i];
//         }
//         Solution ob;
//         auto ans = ob.getPairsCount(arr, n, k);
//         cout << ans << "\n";
//     }

//     return 0;
// }  // } Driver Code Ends

// another approach
//  1.first approach
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
// tc : O N(2)
// sc : O(1)
int getPairsCount1(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                count++;
            }
        }
    }
    return count;
};
// tc : o(n)
// sc : o(n)
int getPairsCount2(int arr[], int n, int k)
{
    unordered_set<int> st;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    int i = 0;
    for (auto &pr : st)
    {
        if (abs(pr - arr[i]) == k)
        {
            count++;
        }
        i++;
    }
    return count;
};

// { Driver Code Starts.

int main()
{

    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << getPairsCount2(arr, n, k);

    return 0;
}
