#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#include<string.h>
using namespace std;
const int N = 1000 + 5;
int main()
{
  int k,k1,i;
  double P[N];
  int exo;
  double cop;
  int n;
  while (scanf("%d", &k) != EOF){
    n = 0;
    int sum = 0;
    memset(P, 0, sizeof(P));
    for (i = 0; i < k; i++)
    {
      cin >> exo >> cop;
      P[exo] += cop;
    }
    scanf("%d", &k1);
    for (i = 0; i < k1; i++)
    {
      cin >> exo >> cop;
      P[exo] += cop;
    }
    while (n < 1005)
    {
      if (P[n] != 0)
        sum++;
      n++;
    }
    cout << sum;
    int l = 0;
    for (i = N - 1; i >= 0; i--){

      if (P[i] != 0 && l <= sum - 1)
      {
      //  cout << fixed << setprecision(1);
        l++;
        if (l <= sum - 1)
          printf(" %d %.1lf", i, P[i]);
        else
          printf(" %d %.1lf\n", i, P[i]);
      }
    /*  if (!flag)
        */

    }
  }
  return 0;
}
}