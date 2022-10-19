#include <iostream>
using namespace std;

void sort(int arr[][3], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 1; j < size - i - 1; j++)
    {
      if (arr[j][0] > arr[j + 1][0])
      {
        swap(arr[j][0], arr[j + 1][0]);
        swap(arr[j][1], arr[j + 1][1]);
        swap(arr[j][2], arr[j + 1][2]);
      }

      else if (arr[j][0]==arr[j+1][0] && arr[j][1]>arr[j+1][1])
      {
        swap(arr[j][0], arr[j + 1][0]);
        swap(arr[j][1], arr[j + 1][1]);
        swap(arr[j][2], arr[j + 1][2]);
      }
    }
  }
}

void del(int arr[][3], int size)
{
  for (int i = 1; i < size - 1; i++)
  {
    arr[i][0] = arr[i + 1][0];
    arr[i][1] = arr[i + 1][1];
    arr[i][2] = arr[i + 1][2];
  }
  size--;
}

int main()
{
  int rows, cols, n1, n2;

  cout << "Enter no of rows for both matrices: ";
  cin >> rows;
  cout << "Enter no of cols for both matrices: ";
  cin >> cols;
  cout << "Enter no of non-zero values in matrix 1: ";
  cin >> n1;
  cout << "Enter no of non-zero values in matrix 2: ";
  cin >> n2;

  int sparse1[n1+1][3], sparse2[n2+1][3];
  sparse1[0][0] = sparse2[0][0] = rows;
  sparse1[0][1] = sparse2[0][1] = cols;
  sparse1[0][2] = n1;
  sparse2[0][2] = n2;

  string arr[3] = {"row", "col", "value"};

  // input
  cout << "\nFor matrix 1:" << endl;
  for (int i = 1; i < n1 + 1; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << "Enter " << arr[j] << ": ";
      cin >> sparse1[i][j];
    }
  }
  
  cout << "\nFor matrix 2:" << endl;
  for (int i = 1; i < n2 + 1; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << "Enter " << arr[j] << ": ";
      cin >> sparse2[i][j];
    }
  }

  sort(sparse1, n1+1);
  sort(sparse2, n2+1);

  //add
  int counter=0, add[n1+n2+1][3], i=1, j=1, k=1;

  while(i<=n1+1 && j<=n2+1){
    if(sparse1[i][0]<sparse2[j][0]){
      add[k][0] = sparse1[i][0];
      add[k][1] = sparse1[i][1];
      add[k][2] = sparse1[i][2];
      k++;
      i++;
      counter++;
    }
    
    else if(sparse1[i][0]>sparse2[j][0]){
      add[k][0] = sparse2[j][0];
      add[k][1] = sparse2[j][1];
      add[k][2] = sparse2[j][2];
      k++;
      j++;
      counter++;
    }
    
    else if(sparse1[i][1]<sparse2[j][1]){
      add[k][0] = sparse1[i][0];
      add[k][1] = sparse1[i][1];
      add[k][2] = sparse1[i][2];
      k++;
      i++;
      counter++;
    }
    
    else if(sparse1[i][1]>sparse2[j][1]){
      add[k][0] = sparse2[j][0];
      add[k][1] = sparse2[j][1];
      add[k][2] = sparse2[j][2];
      k++;
      j++;
      counter++;
    }

    else{
      add[k][0] = sparse1[i][0];
      add[k][1] = sparse1[i][1];
      add[k][2] = sparse1[i][2]+sparse2[j][2];
      k++;
      i++;
      j++;
      counter++;
    }
  }

  add[0][0] = rows;
  add[0][1] = cols;
  add[0][2] = counter;

  //display
  cout << "\nResultant:" << endl;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (i == add[1][0] && j == add[1][1])
      {
        cout << add[1][2] << '\t';
        del(add, counter+1);
      }
      else
        cout << 0 << '\t';
    }
    cout << endl;
  }
}
