nclude<iostream>
#include<cmath>
#define MAXN 10001
using namespace std;
int _hash[MAXN];
//void init(int n){
//  int i;
//  for(i=0;i<n;++i){
//    _hash[i]=0;
//  }
//}
void input(int &size,int &n){
  //int i;
  cin>>size>>n;
}
bool is_prime(int num){
  int i;
  if(num==1) return false;
  if(num==2||num==3) return true;
  for(i=2;i<sqrt(double(num))+0.5;i++){
    if(num%i==0) return false;
  }
  return true;
}
void solve(int size,int n){
  int pos,l,x;
  while(!is_prime(size))
    size++;
  while(n--){
    cin>>x;
    for(l=0;l<size;l++){
      if(_hash[(x+l*l)%size]==0){
        _hash[(x+l*l)%size]=1;
           cout <<(x+l*l)%size <<(n ? " " : "\n");  
        break;
      }
    }
      if (l == size)  
             cout << "-" << (n ?" " : "\n");  
    }    
}
int main(){
  int size,n;
  input(size,n);
  //init(n);
  solve(size,n);
  //system("pause");
  return 0;
}
