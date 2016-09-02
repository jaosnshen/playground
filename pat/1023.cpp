nclude<iostream>
#include<string>
#include<algorithm>
#define MAXN 25
using namespace std;
int fnum[MAXN],snum[MAXN],ans[MAXN];
void str2num(string s,int len){
	int i;
	for(i=0;i<len;i++){
	  fnum[len-i-1]=s[i]-'0';
	}
}
void copy(int *num,int len){
	int i;
	for(i=0;i<len;i++){
	   ans[i]=num[i];
	}
}
bool judge(int len){
	int i=0;
	for(i=0;i<len;i++){
	    if(fnum[i]!=snum[i])
	       return false;
	}
	return true;
}
void solve(int len){
	int temp,i=0,l=0;
	while(i<len){
	     temp=fnum[i]*2;
		 snum[l+1]=temp/10;
	     snum[l++]+=temp%10;
		 i++;
	}
	if(temp>10){
	  snum[l++]=temp/10;
	}
	copy(snum,l);
	if(l==i){
	sort(snum,snum+l);
	sort(fnum,fnum+len);
	if(judge(len)){
	    cout<<"Yes"<<endl;
	}
	else{
	    cout<<"No"<<endl;
	}
	}else{
	    cout<<"No"<<endl;
	}
	for(i=l-1;i>=0;i--){
	    cout<<ans[i];
	}
	cout<<endl;
}
int main(){
	string num;
	int len;
	cin>>num;
	len=num.size();
	str2num(num,len);//to int
	solve(len);
	//system("pause");
return 0;
}
