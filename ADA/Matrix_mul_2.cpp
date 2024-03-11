#include <iostream>
using namespace std;

void multiply(int mat1[10][10], int mat2[10][10], int res[10][10], int r1, int c1, int r2, int c2, int i, int j, int k)
{
  if (i < r1 && j < r2 && k < c1)
  {
    res[i][j] += mat1[i][k] * mat2[k][j];
    multiply(mat1, mat2, res, r1, c1, r2, c2, i, j, k + 1);
  }
}

void multiplyMatrix(int mat1[10][10], int mat2[10][10], int res[10][10], int r1, int c1, int r2, int c2)
{
  for (int i = 0; i < r1; i++)
  {
    for (int j = 0; j < c2; j++)
    {
      res[i][j] = 0;
      multiply(mat1, mat2, res, r1, c1, r2, c2, i, j, 0);
    }
  }
}

int main()
{
  int mat1[10][10], mat2[10][10], res[10][10];
  int r1, c1, r2, c2;

  cout << "Enter the dimensions of the first matrix: ";
  cin >> r1 >> c1;

  cout << "Enter the elements of the first matrix: ";
  for (int i = 0; i < r1; i++)
  {
    for (int j = 0; j < c1; j++)
    {
      cin >> mat1[i][j];
    }
  }

  cout << "Enter the dimensions of the second matrix: ";
  cin >> r2 >> c2;

  if (c1 != r2)
  {
    cout << "Matrix multiplication not possible.";
    return 0;
  }

  cout << "Enter the elements of the second matrix: ";
  for (int i = 0; i < r2; i++)
  {
    for (int j = 0; j < c2; j++)
    {
      cin >> mat2[i][j];
    }
  }

  multiplyMatrix(mat1, mat2, res, r1, c1, r2, c2);

  cout << "The product of the two matrices is: " << endl;
  for (int i = 0; i < r1; i++)
  {
    for (int j = 0; j < c2; j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}