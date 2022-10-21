
    public:
    
    int solve(int range, int size, int arr[])
    {
        bool t[size+1][range+1];
        
        for(int i=0 ; i<=size ; i++)
        {
            for(int j=0 ; j<=range ; j++)
            {
                if(i == 0) t[0][j] = 0;
                if(j == 0) t[i][0] = 1;
            }
        }
        
        for(int i=1 ; i<=size ; i++)
        {
            for(int j=1 ; j<=range ; j++)
            {
                 if(arr[i-1] <= j) t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                else if(arr[i-1] > j) t[i][j] = t[i-1][j];
            }
        }
        
    //     int mini = INT_MAX;
    //     for (int j = range / 2; j >= 0; j--)
    //     {
    //     // Find the
    //     if (t[size][j] == true) 
    //     {
    //         mini = range - 2 * j;
    //         break;
    //     }
    // }
       // matrix is filled now
        vector <int> v;
        for(int index = 0 ; index<=(range/2) ; index++)
        {
            if(t[size][index] == 1) v.push_back(index);
        }
        
        //now we'll check min difference
        int mini = INT_MAX;
        
        for(int i=0 ; i<v.size() ; i++)
        {
            mini = min (mini, range - (2*v[i]));
        }
        
        return mini;
        
    }
    
	int minDifference(int arr[], int n)  
	{ 
	    int sum = 0 ; //total array sum
	    
	    for(int i=0 ; i<n ; i++)
	    {
	        sum += arr[i];
	    }
	    
	    int final = solve(sum, n, arr);
	    
	    return final;
	} 
};
