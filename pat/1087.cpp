#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<climits>
using namespace std;
string TarCity;
struct node {
  string TargetCity;
  int dis;
  node(string T,int d):TargetCity(T),dis(d){}
};
map<string, int> HappyOfCity;
map<string, vector<node>> Graph;
map<string, bool> vis;
vector<string> Path;
int MaxHappy;
int SamePath;
int MinCost;
int AvHappness;
int AnsHappy;
double AvAnsHappness;
vector<string> AnsPath;
void dfs(string StartCity, int dis)
{
  if (StartCity == "ROM")
  {
    int len = Path.size();
    //cout << AnsHappy << endl;
    if (dis < MinCost)
    {
      SamePath = 1;
      MinCost = dis;
      AnsPath = Path;
      AnsHappy = MaxHappy;
      AvAnsHappness = MaxHappy / (double)(len - 1);
    }
    else if(dis==MinCost)
    {
      SamePath++;
      if (AnsHappy==MaxHappy)
      {
        double tempHappy= MaxHappy / ((len - 1)*1.0);
        if (tempHappy>AvAnsHappness)
        {
          AvAnsHappness = tempHappy;
          AnsPath = Path;
        }
      }
      else if (AnsHappy<MaxHappy)
      {
        AnsHappy = MaxHappy;
        AnsPath = Path;
        AvAnsHappness = MaxHappy / ((len - 1)*1.0);
      }
    }
    return;
  }

  auto it = Graph[StartCity].begin();
  for (;it!= Graph[StartCity].end();++it)
  {
    if (!vis[it->TargetCity])
    {
      MaxHappy+= HappyOfCity[it->TargetCity];
      vis[it->TargetCity] = true;
      Path.push_back(it->TargetCity);
      dfs(it->TargetCity,dis+(it->dis));
      Path.pop_back();
      vis[it->TargetCity] = false;
      MaxHappy -= HappyOfCity[it->TargetCity];
    }
  }
}
int main()
{
  int i,NumOfCity, NumOfRoutes,Happy;
  int len;
  string start,end;
  cin >> NumOfCity >> NumOfRoutes >> TarCity;
  for (i = 0;i<NumOfCity-1;i++)
  {
    cin >> start>> Happy;
    HappyOfCity[start] = Happy;
    vis[start] = false;
  }
  for (i = 0;i<NumOfRoutes;++i)
  {
    cin >> start >> end >> Happy;
    Graph[start].push_back(node(end, Happy));
    Graph[end].push_back(node(start, Happy));
  }
  Path.push_back(TarCity);
  MaxHappy = 0;
  MinCost = INT_MAX;
  AvAnsHappness = INT_MIN;
  AvHappness = 0;
  //AnsHappy = ;
  SamePath = 0;
  AnsHappy = -1;
  vis[TarCity] = true;
  dfs(TarCity,0);
  len = AnsPath.size();
  printf("%d %d %d %d\n", SamePath, MinCost,AnsHappy, int(AvAnsHappness));
  cout << TarCity;
  for (i = 1;i<len;++i)
  {
    cout << "->" << AnsPath[i];
  }
  cout << endl;
//system("pause");
  return 0;
}
