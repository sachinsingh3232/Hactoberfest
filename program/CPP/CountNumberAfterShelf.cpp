class Solution {
public:
    void mergefunc(vector<pair<int,int>>& v,vector<int>& count,int l,int mid,int h)
    {    int i=l;
        int j=mid+1;
        int k=0;
        vector<pair<int,int>> n(h-l+1);
     while(i<=mid && j<=h)
     {
         if(v[i].first <= v[j].first)
         {
             n[k++]=v[j++];
         }
         else
         {
               count[v[i].second]+= h-j+1;
               n[k++]=v[i++];
         }
     }
       while(i<=mid)
       {
           n[k++]=v[i++];
       }
       while(j<=h)
       {
           n[k++]=v[j++];
       }
         
        for(int i=l;i<=h;i++)
        {
            v[i]=n[i-l];
        }   
     return;
    }
    void mergesorting(vector<pair<int,int>>& v,vector<int>& count,int l,int h)
    {
        if(l>=h)
        {
            return;
        }
        int mid=(l+h)/2;
            mergesorting(v,count,l,mid);
            mergesorting(v,count,mid+1,h);
            mergefunc(v,count,l,mid,h);
    
    }   
      vector<int> countSmaller(vector<int>& nums) {      
       int n = nums.size();
          cout<<"a";
        vector<pair<int,int>> v(n);                                  
        for(int i=0;i<n;i++)
        { 
            v[i] = {nums[i],i};
        }
          
        vector<int> count(n,0);  
          cout<<"b";
        mergesorting(v,count,0,n-1);                               
      
        return count;
    }
};
