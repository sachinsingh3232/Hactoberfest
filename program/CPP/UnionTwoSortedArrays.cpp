//T.C O(n+m)
// This code is contributed by Abdul Rahman
#include <bits/stdc++.h>

using namespace std;

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0; // pointers for traversing the arrays
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2 
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // if any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // if any element left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}

int main()

{
  int n = 6, m = 10;
  int arr1[] = {1,2,2,3,3,4};
  int arr2[] = {1,2,4,4,6,6,6,7,8,10}; 
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of Arrays arr1 and arr2 : " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}