nclude<iostream>
#include<vector>
using namespace std;
vector<int> v;
int size;
void exchang_to_basic(int N,int D){
  int t;
  while(N){
     t=N%D;
     v.push_back(t);
     N/=D;
  }
}
bool is_Palindromic(vector<int> &v){
  size=v.size();
  int it,i;
  for(it=0,i=size-1;it<size-1;it++,i--){
     if(v[it]!=v[i])
       return false;
  }
  return true;
}
int main(){
  int N,D,it;
  cin>>N>>D;
  if(N==0){
  printf("Yes\n0\n");
  }else{
  exchang_to_basic(N,D);
  if(is_Palindromic(v)){
     cout<<"Yes\n";
  }else{
     cout<<"No\n";
  }
  for(it=size-1;it>=0;it--){
     if(it==0)
       cout<<v[it]<<endl;
     else
       cout<<v[it]<<" ";
  }
  }
return 0;
}
