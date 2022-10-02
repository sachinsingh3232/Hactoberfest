void merge(long long arr1[], long long arr2[], int n, int m)
{
    // code here
    int j = 0, i = 0, k = n - 1;
    while (i <= k && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[k], arr2[j]);
            j++;
            k--;
        }
        else
        {
            i++;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}