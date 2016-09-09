#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100000;
int NumofCoin[maxn];
bool f;
int BinarySearch(int r,int l,int key)
{
  while (r < l)
  {
    int mid = r + (l - r) / 2;
    if (NumofCoin[mid] == key)
      return mid;
    if (NumofCoin[mid] < key)
    {
      r = mid+1;
    }
    else
    {
      l = mid-1;
    }
  }
  return -1;

}
int main()
{
  int N, M,i,ans;
  int r, l;
  int temp;
  cin >> N >> M;
  for (i = 0;i<N;++i)
  {
    cin >> NumofCoin[i];
  }
  sort(NumofCoin, NumofCoin+N);
  f = false;
  for (int i = 0;i<N;++i)
  {
    ans = M - NumofCoin[i];
    temp= BinarySearch(0, N, ans);
    if (temp != -1 && temp != i)
    {
      f = true;
      r = NumofCoin[i];
      l = NumofCoin[temp];
      break;
    }
  }
  if (f)
    printf("%d %d\n", r, l);
  else
    printf("No Solution\n");
  /*for (i = 0;i<N;++i)
  {
    for (l = 0; i < N; ++l)
    {
      if (l != i)
      {
        ans = NumofCoin[i] + NumofCoin[l];
        if (ans == M)
        {
          if (NumofCoin[i] < NumofCoin[l])
            r = NumofCoin[i];
          else
            ll = NumofCoin[l];
          break;
        }
      }
    }
  }*/
  //printf("%d %d\n", r, ll);
  system("pause");
  return 0;
}
