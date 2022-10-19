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
  int rows1, cols1, rows2, cols2, n1, n2;

  cout << "Enter no of rows in matrix 1: ";
  cin >> rows1;
  cout << "Enter no of cols in matrix 1: ";
  cin >> cols1;
  cout << "Enter no of rows in matrix 2: ";
  cin >> rows2;
  cout << "Enter no of cols in matrix 2: ";
  cin >> cols2;
  cout << "Enter no of non-zero values in matrix 1: ";
  cin >> n1;
  cout << "Enter no of non-zero values in matrix 2: ";
  cin >> n2;

  if(rows2 == cols1){
    int sparse1[n1+1][3], sparse2[n2+1][3];
    sparse1[0][0] = rows1;
    sparse2[0][0] = rows2;
    sparse1[0][1] = cols1;
    sparse2[0][1] = cols2;
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
    
    //transpose of matrix 2
    for (int i = 1; i < n2 + 1; i++) swap(sparse2[i][0], sparse2[i][1]);
    sort(sparse2, n2+1);

    
    //prod
    int counter=0, prod[n1+n2][3], *one, *two, k=1;

    one = &sparse1[1][0];
    two = &sparse2[1][0];

    for(int i=1; i<=n1; i++){
      for(int j=1; j<=n2; j++){

        if(*(one+1) == *(two+1)){
          prod[k][0] = *one;
          prod[k][1] = *two;
          prod[k][2] = *(one+2)*(*(two+2));
          counter++;
          k++;
        }
        two+=3;
      }
      one+=3;
      two = &sparse2[1][0];
    }

    sort(prod, counter+1);

    for(int k=1; k<counter; k++){
      if(prod[k][0] == prod[k+1][0] && prod[k][1] == prod[k+1][1])
        prod[k][2] += prod[k+1][2];
    }

    prod[0][0] = rows1;
    prod[0][1] = cols2;
    prod[0][2] = counter;


    //display
    cout << "\nResultant:" << endl;

    for (int i = 0; i < rows1; i++)
    {
      for (int j = 0; j < cols2; j++)
      {
        if (i == prod[1][0] && j == prod[1][1])
        {
          cout << prod[1][2] << '\t';
          del(prod, counter+1);
        }
        else
          cout << 0 << '\t';
      }
      cout << endl;
    }
  }

  else cout << "Dimensions don't match!" << endl;
}

