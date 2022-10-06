#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;



bool isPossible(int arr[], int no_of_stalls, int no_of_cows, int mid)
{
    
    int count_of_cows = 1;
    int cow = arr[0];
    
    
    
    for(int i = 1; i < no_of_stalls; i++)
    {
        if((arr[i] - cow) >= mid)
        {
            
            count_of_cows++;
            cow = arr[i];
            
        }
        
        
    }
    
    if(count_of_cows < no_of_cows)
    {
        return false;
    }
    
    else
    {
        return true;
    }

    
}



int maximiseTheMinDistance(int arr[], int no_of_stalls, int no_of_cows)
{
    
    int start = 1;
    int end = arr[no_of_stalls-1] - arr[0];
    

    int myans = INT_MIN;
    
    while(start <= end)
    {
        
        int mid = (start + end)/2;
        
        
        if(isPossible(arr,no_of_stalls,no_of_cows,mid))
        {
            
            myans = max(myans,mid);
            
            
            start = mid + 1;
            
        }
        
        else
        {
            end = mid-1;
        }
        
    }
    
    
    return myans;
    
}


int main()
{
    int no_of_stalls;
    int no_of_cows;
    
    
    cin >> no_of_stalls;
    cin >> no_of_cows;

    int arr[no_of_stalls];
    
    for(int i = 0; i < no_of_stalls; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+no_of_stalls);
    
    cout << maximiseTheMinDistance(arr,no_of_stalls,no_of_cows) << endl;

    return 0;
}
