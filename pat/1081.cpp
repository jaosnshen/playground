#include<iostream>
#define ll long long 
using namespace std;
ll gcd(ll a,ll b)
{
  if(b==0) return a;
  return gcd(b,a%b);
}
int main()
{
  int n;
  int count=0;
  ll a1=0,a2=1,b1,b2;
  ll ans1,ans2;
  ll temp;
  cin>>n;
  while(count<n)
  {
     scanf("%lld/%lld",&b1,&b2);
   //  ans1=a1*
      ans1=a1*b2+b1*a2;
    ans2=b2*a2;
      temp=gcd(ans1,ans2);
    a1=ans1/temp;
    a2=ans2/temp;
    count++;
  }
  if(a1%a2==0)
  {
       printf("%lld\n",a1/a2);
  }else if(a1>a2){
    printf("%lld %lld/%lld\n",a1/a2,a1%a2,a2);
  }else{
    printf("%lld/%lld\n",a1,a2);
  }
  //system("pause");
  return 0;
}
