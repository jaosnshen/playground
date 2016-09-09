#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#define MAXN 26*26*26+1
using namespace std;
struct Cost
{
	int y;
	int time;
	Cost(int y,int time):y(y),time(time){}
};
vector<Cost> Map[MAXN];
vector<int> Member[MAXN];
vector<int> start;
int dis[MAXN];
bool vis[MAXN];
int cnt;
int TotalTime[MAXN];
int Hash(char *name)
{
	return (name[0]-'A')*26*26+(name[1]-'A')*26+name[2]-'A';
}
struct Ans{
   int Id;
   int CountMember;
   Ans(int Id,int CountMember):Id(Id),CountMember(CountMember){}
   bool operator<(const Ans &a) const
   {
	   return Id<a.Id;
   }
};
void Dfs(int v)
{
	if(vis[v])
		return ;
	vis[v]=true;
	int i,len=Map[v].size();
	for(i=0;i<len;++i)
	{
		
		//{
			
			//dis[cnt]+=TotalTime[Map[v][i].y];
			Dfs(Map[v][i].y);
		//}
	}
	Member[cnt].push_back(v);
}
/*
10 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
CCC BBB 10
CCC AAA 10

*/
void ReHash(int x)
{
     char name[4];
	 name[2]=x%26+'A';
	 x/=26;
	 name[1]=x%26+'A';
	 x/=26;
	 name[0]=x%26+'A';
	 name[3]='\0';
	 printf("%s ",name);
}
int main()
{
	//int cnt;
	//bool check;
	int N,K,i;
	int time;
	int l;
	//int k;
	int len;
	vector<Ans> ans;
	char name1[4],name2[4];
	scanf("%d%d",&N,&K);
	for(i=0;i<N;++i)
	{
	   scanf("%s%s%d",name1,name2,&time);
	   int x=Hash(name1);
	   int y=Hash(name2);

	   if(!vis[x])
	   {
		 start.push_back(x);
	     vis[x]=true;
	   }
	   TotalTime[x]+=time;
	   TotalTime[y]+=time;
	   Map[x].push_back(Cost(y,time));
	}
	len=start.size();
	memset(vis,false,sizeof(vis));
    for(i=0;i<len;++i)
	{
	    if(!vis[start[i]])
		{
			Dfs(start[i]);
			vis[start[i]]=true;
		    cnt++;
		}
	}        
	//check=false;

	for(i=0;i<cnt;++i)
	{
		if(Member[i].size()<3)
			continue;
		else
		{
		  //check=true;
		  int MIN=INT_MIN;
		  int id;
		 // int len1=Member[i].size();
		  for(l=0;l<Member[i].size();++l)
	      {
			dis[i]+=TotalTime[Member[i][l]];
			if(MIN<TotalTime[Member[i][l]])
			{
			   MIN=TotalTime[Member[i][l]];
			   id=Member[i][l];
			}
	      }
		  if(dis[i]/2<=K)
			  continue;
		  ans.push_back(Ans(id,Member[i].size()));
		}
	}
    len=ans.size();
	if(len!=0)
	{
	sort(ans.begin(),ans.end());
	printf("%d\n",len);
	for(i=0;i<ans.size();++i)
	{
		ReHash(ans[i].Id);
		printf("%d\n",ans[i].CountMember);
	}
	}
	else
	{
	  printf("0\n");
	}
	//system("pause");
   return 0;
}
