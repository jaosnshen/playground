#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
using namespace std;

int main(){
  long long N,i,l,sum,len=0,max=-INT_MAX,s;
  cin>>N;
  vector<int> v,ans(1,N);
  for(i=2;i<sqrt(double(N))+0.5;i++){
    sum=N;
    l=i;
    while(sum%l==0){
      v.push_back(l);
      sum/=l;
      l++;
    }
    len=v.size();
    if(len>ans.size())
      ans=v;
    else if(len==ans.size()&&v[0]<ans[0]){
        ans=v;
    }
    v.clear();
  }
  len=ans.size();
  cout<<len<<endl;
  for(i=0;i<len-1;i++){
    cout<<ans[i]<<"*";
  }
  cout<<ans[i]<<endl;
  system("pause");
  return 0;
}
