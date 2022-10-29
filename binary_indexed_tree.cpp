//We have an array arr[0 . . . n-1]. We would like to 
//1 Compute the sum of the first i elements. 
//2 Modify the value of a specified element of the array arr[i] = x where 0 <= i <= n-1.

//Using the binary indexed tree we store the sum of element in bitree array using the bits
//bitree[i]=sum of elements from i to j
//where j =i-(least bit set of i)

// Every node of the BITree stores the sum of n elements where n is a power of 2
// The number of set bits in the binary representation of a number n is O(Logn). Therefore, we traverse 
//at-most O(Logn) nodes in both getSum() and update() operations. The time complexity of the construction 
//is O(nLogn) as it calls update() for all n elements.


//Example 1:
//5                no of elements(n)
//[1,2,3,4,5]      original array(a)
//output:
//[1,3,3,10,5]     bitree
//15               sum of first five element
//1 2 4 4 5        updated index at 3(modified array)
//[1,3,4,11,5]     updated bitree

#include<bits/stdc++.h>  
using namespace std;
#define ll long long
#define ld long double
const int MOD = 1000000007;
void updateB(vector<ll> &bitree,vector<ll> &a,ll i,ll sum){         // 1 based indexing i=1 (first element)
    ll N=bitree.size();  //(n+1)
    a[i-1]=a[i-1]+sum;
    for(int k=i;k<N;k+=(k&(-k))){
        bitree[k]+=sum;
    }
}
ll sumB(vector<ll> &bitree,ll i){        //(5)arr[0...4] -> first five element
    ll ans=0;
    for(int k=i;k>0;k-=k&(-k)){
        ans+=bitree[k];
    }
    return ans;
}
void consB(vector<ll> &bitree,vector<ll> a){
    ll N=bitree.size();
    for(int i=1;i<N;i++){
        updateB(bitree,a,i,a[i-1]);
    }
}
int main(){
   
       ll n;
       cin>>n;
       vector<ll> a(n);
       for(int i=0;i<n;i++){
           cin>>a[i];               //input of array
       }
       vector<ll> bitree(n+1,0);
       consB(bitree,a);
       for(int i=1;i<=n;i++){
           cout<<bitree[i]<<" ";
       }cout<<endl;
       cout<<sumB(bitree,5)<<endl;;
       updateB(bitree,a,3,1);     //updated index at 3 by 1
        for(int i=0;i<n;i++){
           cout<<a[i]<<" ";
       }cout<<endl;
        for(int i=1;i<=n;i++){
           cout<<bitree[i]<<" ";  //display of bitree
       }cout<<endl;
       
    return 0;
}
