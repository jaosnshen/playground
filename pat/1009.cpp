#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int N = 3000;
struct poly{
  int exp;
  double coeff;
};
poly P2[N], P1[N];
double P[N+1];
int main()
{ 
  int k, k1,i,l,sum;
  while (scanf("%d", &k) == 1){
    sum = 0;
    memset(P, 0, sizeof(P));
    for (i = 0; i < k; i++)
      cin >> P1[i].exp>> P1[i].coeff;
    scanf("%d", &k1);
    for (i = 0; i < k1; i++)
      cin >> P2[i].exp >> P2[i].coeff;
    for (i = 0; i < k; i++)
        for (l = 0;l<k1;l++)
      P[P1[i].exp + P2[l].exp]+= P1[i].coeff*P2[l].coeff;
      i = 0;
      while (i < N+1){
        if (fabs(P[i])> 1e-6)
          sum++;
            i++;
      }
      cout << sum;
      for (l = N;l>=0;l--)
      if (fabs(P[l])>1e-6)
        printf(" %d %.1lf", l, P[l]);
      cout << endl;
  }
  return 0;
}
