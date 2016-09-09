#include <cstdio>

long long gcd(long long a, long long b)
{
  if (a == 0 || b == 0) return a > b ? a : b;
  for (long long t; t = a % b; a = b, b = t);
  return b;
}

void simplify(long long &a, long long &b)
{
  long long x = gcd(a<0 ? -a : a, b);
  a /= x, b /= x; 
}

void f(long long a, long long b)
{
  if (b == 0) { printf("Inf"); return; }

  if (b < 0) a = -a, b = -b;
  simplify(a, b);
  bool flag = 0;
  if (a < 0) a = -a, flag = 1;

  if (flag) printf("(-");
  if (a % b == 0) printf("%lld", a / b);
  else if (a < b) printf("%lld/%lld", a, b);
  else printf("%lld %lld/%lld", a / b, a % b, b);
  if (flag) printf(")");
}

int main()
{
  long long a1, b1, a2, b2; scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
  f(a1, b1); printf(" + "); f(a2, b2); printf(" = "); f(a1*b2+a2*b1, b1*b2); printf("\n");
  f(a1, b1); printf(" - "); f(a2, b2); printf(" = "); f(a1*b2-a2*b1, b1*b2); printf("\n");
  f(a1, b1); printf(" * "); f(a2, b2); printf(" = "); f(a1*a2, b1*b2); printf("\n");
  f(a1, b1); printf(" / "); f(a2, b2); printf(" = "); f(a1*b2, a2*b1); printf("\n");
  return 0;
}
