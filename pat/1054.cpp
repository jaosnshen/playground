#include<iostream>
#include<map>
#define MAXN 801
using namespace std;
//int color[MAXN];
map<int,int> color;
int main(){
  int M,N,ans,i,l,num,max=-1;
  map<int,int> ::iterator it;
  scanf("%d%d",&M,&N);
  for(i=0;i<M;++i){
    for(l=0;l<N;++l){
      scanf("%d",&num);
      color[num]++;
    }
  }
  it=color.begin();
  for(;it!=color.end();++it){
    if(max<it->second){
      max=it->second;
      ans=it->first;
    }
  }
  cout<<ans<<endl;
  system("pause");
return 0;
}
