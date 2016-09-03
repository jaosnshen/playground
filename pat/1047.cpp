#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<cstdio>
#define MAXN 2505
#include<algorithm>
using namespace std;
vector<string> m[MAXN];
vector<string> ::iterator it;
void input(int &N,int &K){
	cin>>N>>K;
	string name;
	int i,c,l,cornum;
	for(i=0;i<N;i++){
	   cin>>name>>c;
	   for(l=0;l<c;l++){
	      scanf("%d",&cornum);
		  m[cornum].push_back(name);
	   }
	   //sort(m[cornum].begin(),m[cornum].end());
	}
}
void solve(int N,int K){
	int i,l;
	int len;
	for(i=1;i<=K;i++){
		len=m[i].size();
		printf("%d %d\n",i,len);
		sort(m[i].begin(),m[i].end());
		for(l=0;l<len;l++)
          //  cout<<m[i][l]<<endl;	
		  printf("%s\n",m[i][l].c_str());
	}
}
int main(){
	int N,K;
	input(N,K);
	solve(N,K);
	//system("pause");
return 0;
}
