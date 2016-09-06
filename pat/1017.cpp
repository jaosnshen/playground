#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=10000;
struct Queue{
   int ArrTime;
   int EndTime;
   int Process;
   int NumOfWindows;
   Queue()
   {
    EndTime=ArrTime=Process=NumOfWindows=0;
   }
   Queue(int A,int P,int N,int E):ArrTime(A),Process(P),NumOfWindows(N),EndTime(E){}
   bool operator<(const Queue &a) const
   {
     return EndTime>a.EndTime;
   }
};
bool cmp(const Queue &a,const Queue &b)
{
  return a.ArrTime<b.ArrTime;
}
Queue ListCos[maxn];
int ExchangeTime(int HH,int MM,int SS)
{
  return HH*3600+MM*60+SS;
}
int ArrTime[maxn];
int WaitTime[maxn];
const int START=8*3600;
const int END=17*3600;
priority_queue<Queue> p;
int main()
{
  int ans=0;
  int m,n;
  int cur=0;
  int HH,MM,SS,time;
  scanf("%d%d",&m,&n);
  for(int i=0;i<m;i++)
  {
   scanf("%d:%d:%d %d",&HH,&MM,&SS,&time);
   ListCos[i].ArrTime=ExchangeTime(HH,MM,SS);
   ListCos[i].Process=time*60;
   //ListCos[i].EndTime=ListCos[i].ArrTime+
  }
  sort(ListCos,ListCos+m,cmp);
  for(int i=0;i<n&&i<m;++i)
  {
    if(ListCos[i].ArrTime<START)
    {
      p.push(Queue(START,ListCos[i].Process,i,START+ListCos[i].Process));
      WaitTime[i]=START-ListCos[i].ArrTime;
    }
    else
    {
      p.push(Queue(ListCos[i].ArrTime,ListCos[i].Process,i,ListCos[i].ArrTime+ListCos[i].Process));
            WaitTime[i]=0;
    } 
    cur++;
     //进入时间
  }
  while(!p.empty())
  {
    int EnterTime=0;
    if(cur==m)
    {
       break;
    }
    Queue q=p.top();
    p.pop();
    if(q.EndTime<=ListCos[cur].ArrTime&&ListCos[cur].ArrTime<=END)
    {
      EnterTime=ListCos[cur].ArrTime;
      WaitTime[cur]=0;
    }
    else if(q.EndTime>ListCos[cur].ArrTime&&ListCos[cur].ArrTime<=END)
    {
       EnterTime=q.EndTime;
       WaitTime[cur]=EnterTime-ListCos[cur].ArrTime;
    }
      if(cur<m)
    {
      p.push(Queue(EnterTime,ListCos[cur].Process,q.NumOfWindows,EnterTime+ListCos[cur].Process));
        cur++;
    }
  }
  for(int i=0;i<m;++i)
  {
    if(ListCos[i].ArrTime>END)
    {
      m=i;
      break;
    }//if(ListCos[i].ArrTime<=END)
        ans+=WaitTime[i];
  }
  double ansM=ans*1.0/(m*1.0)/60.0;
  printf("%.1lf\n",ansM);
  system("pause");
  return 0;
}
