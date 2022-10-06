void merge(long long arr1[], long long arr2[], int n, int m)
{
	// code here
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr1[i] > arr2[start])
		{
			swap(arr1[i], arr2[start])
		}
	}
	sort(arr2, arr2 + m);
}