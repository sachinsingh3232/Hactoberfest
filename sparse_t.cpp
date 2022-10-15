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
  int rows, cols, n;

  cout << "Enter no of rows: ";
  cin >> rows;
  cout << "Enter no of cols: ";
  cin >> cols;
  cout << "Enter no of non-zero values: ";
  cin >> n;

  int sparse[n + 1][3];
  sparse[0][0] = rows;
  sparse[0][1] = cols;
  sparse[0][2] = n;

  string arr[3] = {"row", "col", "value"};

  // input
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << "Enter " << arr[j] << ": ";
      cin >> sparse[i][j];
    }
  }

  // col swap
  for (int i = 1; i < n + 1; i++)
    swap(sparse[i][0], sparse[i][1]);

  // col sort
  sort(sparse, n + 1);

  // display
  cout << "\nTranspose:" << endl;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (i == sparse[1][0] && j == sparse[1][1])
      {
        cout << sparse[1][2] << '\t';
        del(sparse, n + 1);
      }
      else
        cout << 0 << '\t';
    }
    cout << endl;
  }
}
