#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> arr)
{
  int sum = 0;
  for (int x = 0; x < arr.size(); x++)
  {
    sum += arr[x];
  }
  return sum;
}
int sum_rec(vector<int> arr, int index)
{
  if (index >= arr.size())
  {
    return 0;
  }
  int sum = 0;
  sum = sum + arr[index] + sum_rec(arr, index + 1);
  return sum;
}
void sel_sort(vector<int> arr)
{
  int mini = INT_MAX;
  int idx = 0;
  for (int x = 0; x < arr.size(); x++)
  {

    idx = x;
    mini = arr[x];
    for (int f = x + 1; f < arr.size(); f++)
    {
      if (arr[f] <= mini)
      {
        idx = f;
        mini = arr[f];
      }
    }
    swap(arr[idx], arr[x]);
  }
}
void permute(vector<int> arr, vector<int> ele, int idx)
{
  if (ele.size() == arr.size())
  {
    return;
  }
  for (int i = idx; i < arr.size(); i++)
  {
    swap(arr[i], arr[idx]);
    permute(arr, ele, idx + 1);
    swap(arr[i], arr[idx]);
  }
}
void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
  if (n == 0)
  {
    return;
  }
  towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
  towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
void tt_ff(string s, int len)
{
  if (s.length() == len)
  {
    cout << s << endl;
    return;
  }
  s = s + "T";
  tt_ff(s, len + 1);
  s = s + "F";
  tt_ff(s, len + 1);
}
int power(int x, int y)
{
  int temp;
  if (y == 0)
    return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}

void pow2(int a, int a_ki_power)
{
  int ans = 1;
  for (int x = 0; x < a_ki_power; x++)
  {
    ans = ans * a;
  }
  // cout << ans << endl;
}
int main()
{
}