#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define N 9

int check_void(int puz[N][N],int *row, int *col)
{
    int a = 0;
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            //cell is unassigned
            if(puz[i][j] == 0)
            {
                //changing the values of row and col
                *row = i;
                *col = j;
                a = 1;
                return a;
            }
        }
    }
    return a;
}

//safety of new value function
int check_safe(int puz[N][N],int n, int r, int c)
{
    int i,j;
    // row
    for(i=0;i<9;i++)
    {
        //there is a cell with same value
        if(puz[r][i] == n)
            return 0;
    }
    // column
    for(i=0;i<9;i++)
    {
        //there is a cell with the value equal to i
        if(puz[i][c] == n)
            return 0;
    }
    // sub matrix
    int row_conv = (r/3)*3;
    int col_conv = (c/3)*3;
    for(i=row_conv;i<row_conv+3;i++)
    {
        for(j=col_conv;j<col_conv+3;j++)
        {
            if(puz[i][j]==n)
                return 0;
        }
    }
    return 1;
}

//function to solve sudoku
int solve(int puz[N][N])
{
    int row;
    int col;
    if(check_void(puz,&row, &col) == 0)
        return 1;
    int n,i;
   
    for(i=1;i<=9;i++)
    {
      
        if(check_safe(puz,i, row, col))
        {
            puz[row][col] = i;
            //using backtracking now
            if(solve(puz))
                return 1;
            //reassign the cell for no solution,and further continuation.
            puz[row][col]=0;
        }
    }
    return 0;
}

// BELOW FUNCTION IS USED TO PRINT 9 x 9 GRID

void print_grid(int grid[N][N])
{
	printf("\n	    1   2   3   4   5   6   7   8   9\n");
	printf("	  |---:---:---|---:---:---|---:---:---|\n");
	for(int i=0;i<9;i++)
	{
		printf("	%d ",i+1);
		for(int j=0;j<9;j++)
		{
			if(grid[i][j]==0)
			{
				if(j%3==0)
					printf("|   ");
				else
					printf(":   ");
			}
			else
			{
				if(j%3==0)
					printf("| %d ",grid[i][j]);
				else
					printf(": %d ",grid[i][j]);
			}
			if(j==8)
			{
				printf("|");
			}
		}
		if(i%3==2)
			printf("\n	  |---:---:---|---:---:---|---:---:---|");
		else
			printf("\n	  | - : - : - | - : - : - | - : - : - |");
		printf("\n");
	}	
}

// BELOW FUNCTION IS USED TO GENERATE THE SUDOKU PUZZEL GRID

void generate(int arr[N][N],int solved[N][N],int check[81][2],int z)
{
	srand(time(0));
	arr[0][1]=(rand()%9)+1;
	arr[1][3]=(rand()%9)+1;
	arr[2][6]=(rand()%9)+1;
	arr[4][8]=(rand()%9)+1;
	arr[7][7]=(rand()%9)+1;
	arr[6][4]=(rand()%9)+1;
	arr[3][5]=(rand()%9)+1;
	arr[5][0]=(rand()%9)+1;
	arr[8][2]=(rand()%9)+1;

	solve(arr);
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			solved[i][j]=arr[i][j];
		}
	}

	for(int i=0;i<z;i++)
	{
		arr[rand()%9][rand()%9]=0;
	}
	
	int q=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j]!=0)
			{
				check[q][0]=i+1;
				check[q][1]=j+1;
				q++;
			}
		}
	}

}

// THIS FUNCTION IS USED TO CHECK THE VALUE CAN BE MODIFIED OR NOT

void delete(int a,int b,int c,int arr[N][N],int check[81][2])
{
	int k=0;
	for(int i=0;i<81;i++)
	{
		if(check[i][0]==(a) && check[i][1]==(b))
		{
			k++;
		}
	}
	if(k==1)
	{
		printf("\n		You cannot change the value in given sudoku! Please try again.\n");
		sleep(3);
	}
	else
	{
		arr[a-1][b-1]=c;
	}
}

// THIS FUNCTION IS USED TO CHECK NO OF BLANK SPACES IN THE SUDOKU GRID

int count(int arr[N][N])

{
	int a=0;
	for(int i =0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j]==0)			
			{			
				a+=1;		
			}
		}
	}
	return a;
}

// THIS FUNCTION IS USED TO TAKE INPUT FROM THE USER

void input(int arr[N][N],int solved[N][N],int check[81][2],int n)
{
	int a,b,c,d;
	printf("\n	FOR ENTERING/DELETING/MODYFING VALUES PRESS 1\n");
	printf("	FOR VIEWING THE SOLUTION PRESS 2\n");
	printf("	Enter the number: ");scanf("%d",&d);
	system("clear");
	printf("\n			PUZZEL		\n");
	print_grid(arr);
	if(d==1)
	{
		for(int i=0;i<n;i++)
		{
			printf("\n	Enter the value you want to enter OR press 0 for Main Menu: ");scanf("%d",&c);
			if(c==0)
			{
				break;
			}
			if(c==1 || c==2 || c==3 || c==4 || c==5 || c==6 || c==7 || c==8 || c==9)
			{	
				printf("\n	Enter the position (as in coordinate system): ");scanf("%d %d",&a,&b);
				delete(a,b,c,arr,check);
				system("clear");
				printf("\n			PUZZEL		\n");
				print_grid(arr);
			}
			else
				n+=1;
		}
		n=count(arr);
		if(n==0)
		{
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					if(arr[i][j]!=solved[i][j])
					{
						printf("\n\n	Your solution is not correct. Better luck next time.");
						sleep(2);
						printf("\n\n	Here is the correct solution.\n");
						print_grid(solved);
						exit(1);
					}
				}
			}
			printf("\n\n	WoW! Your solution is correct.\n");
			exit(1);
		}
		system("clear");
		printf("\n			PUZZEL		\n");
		print_grid(arr);
		input(arr,solved,check,n);
	}

	if(d==2)
	{
		printf("\n\n");
		printf("\n			SOLUTION		\n");
		print_grid(solved);
		printf("\n\n");
		exit(1);
	}
	else
	{
		printf("\n\n	Please Input a valid Integer");
		sleep(2);
		system("clear");
		print_grid(arr);
		input(arr,solved,check,n);
	}
	
}

int main(void)
{
	int z;
	int a0;
	system("clear");
	printf("Welcome to this SUDOKU game\n\n");
	printf(" 1.Easy\n 2.Medium\n 3.Hard\n\n	Select your difficulty level: ");
	scanf("%d",&a0);
	
	switch(a0)
	{
	case 1:
	printf("Easy\n");
	  z=50;
	  break;
	  case 2:
	  printf("Medium\n");
	  z=70;
	  break;
	  case 3:
	  printf("Hard\n");
	  z=90;
	  break;
	  default:
	  printf("Error recheck your choice\n");
	}	
	int arr[N][N]={0};
	int solved[N][N];
	int check[81][2]={0};
	generate(arr,solved,check,z);
	
	system("clear");
	printf("\n			PUZZEL		\n");	
	print_grid(arr);

	int a;
	a=count(arr);
	input(arr,solved,check,a);

	return 0;
}
