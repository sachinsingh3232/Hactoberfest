#include<bits/stdc++.h>

int main()
{
    int n,a[100];
    printf("enter the size of the array\n");
    scanf("%d",&n);
    printf("enter the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(a[j]>a[j+1]&&j>=0)
        {
            int k=a[j];
            a[j]=a[j+1];
            a[j+1]=k;
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d",a[i]);
    }
    
    return 0;
}