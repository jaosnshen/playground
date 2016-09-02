nclude<iostream>
#include<math.h>
#include<string>
using namespace std;
bool is_prime(long long n){
  int i;
  if(n==1)
    return false;
  for(i=2;i<sqrt(double(n))+0.5;i++){//开平方要四舍五入
    if(n%i==0){
      return false;
    }
  }
  return true;
}
long long getdecimal(string s,int D){
  int i,t=1;
  long long sum;
  int len=s.size();
  sum=s[len-1]-'0';
  for(i=len-2;i>=0;i--){
      t*=D;
    sum+=t*(s[i]-'0');
  }
  return sum;
}
void get_num(string s,int D,long long sum){
  int i,len;
  char temp;
  string next;
  len=s.size();
  while(sum){
    temp=sum%D+'0';
    next.push_back(temp);
    sum/=D;
  }
  sum=getdecimal(next,D);
  if(is_prime(sum)){
  cout<<"Yes"<<endl;
  }else{
  cout<<"No"<<endl;
  }
}
int main(){
  long long D,sum;
  string N;
  while(cin>>N&&N[0]!='-'){
       cin>>D;
     sum=atoi(N.c_str());
     if(is_prime(sum)){
      // reverse(N.begin(),N.end());
          get_num(N,D,sum);
     }
     else{
     cout<<"No\n";
     }
  }
  return 0;
}
