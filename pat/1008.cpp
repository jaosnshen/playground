nclude<iostream>
#define MAXN 10000
using namespace std;
int sum[MAXN];
int elevator[MAXN];
int main(){
  int N,i,ans;
  cin>>N;
  ans=N*5;
  sum[0]=0;
  for(i=1;i<=N;i++){
     cin>>sum[i];
     elevator[i-1]=sum[i]-sum[i-1];
  }
  for(i=0;i<N;i++){
    if(elevator[i]<0){
       ans+=4*-elevator[i];
    }else if(elevator[i]>0){
       ans+=6*elevator[i];
    }
  }
  cout<<ans<<endl;
  //system("pause");
return 0;
}
