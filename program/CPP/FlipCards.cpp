//Flip the cards
/* Simple solution to flip the cards Code Chef problem
https://www.codechef.com/submit/FLIPCARDS
*/
#include <iostream>
using namespace std;

int main() {
	
	int t,n,x;
	cin>>t;
	if(t>=1 && t<=5000)
	{  for(int i=0;i<t;i++)
	    {
	        cin>>n>>x;
	       if(n>=2 && n<=100 && x>=0 && x<=n)
	       {
	        if(x==0 || x==n)
	          cout<<0<<endl;
	         else if(x<=n/2)
	           cout<<x<<endl;
	         else
	           cout<<n-x<<endl;
	        }
	    }
	    
	}
	return 0;
}
