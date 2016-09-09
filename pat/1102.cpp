#include <iostream>
#include <vector>
#include<queue>
#define MAXN 15
using namespace std;
struct tree{
    int right;
    int left;
    tree(){
        right=left=0;
    }
};
tree t[MAXN];
char _left,_right;
vector<int> invOrder;
vector<int> leverOrder;
int index_node;
void inOrder(int n){
    if(n>=0){
        index_node++;
        inOrder(t[n].left);
        //printf("%d ",n);
        inOrder(t[n].right);
    }
    return;
}
void levelOrder(int n){
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int node=q.front();
        //printf("%d",node);
        leverOrder.push_back(node);
        q.pop();
        if (node!=-1) {
            if (t[node].right!=-1) {
                q.push(t[node].right);
            }
            if (t[node].left!=-1) {
                q.push(t[node].left);
            }
        }
    }
}
void invertOrderTree(int n){
    //int temp;
    if (n>=0) {
        swap(t[n].right,t[n].left);
        invertOrderTree(t[n].left);
        invOrder.push_back(n);
        invertOrderTree(t[n].right);
    }
}
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    int index;
    getchar();
    for(int i=0;i<n;++i){
        scanf("%c %c",&_left,&_right);
        getchar();
       // printf("%c %c\n",_left,_right);
        if (_left<='9'&&_left>='0') {
            t[i].left=_left-'0';
        }else{
            t[i].left=-1;
        }
        if (_right<='9'&&_right>='0') {
            t[i].right=_right-'0';
        }else{
            t[i].right=-1;
        }
       
    }
    for(int i=0;i<n;++i){
        index_node=0;
        inOrder(i);
        if(index_node==n){
            index=i;
            break;
        }
        
    }
   //  inOrder(3);
    //cout<<index<<endl;
    levelOrder(index);
    for(int i=0;i<n;++i){
        if(i!=n-1){
            printf("%d ",leverOrder[i]);
        }else{
            printf("%d\n",leverOrder[i]);
        }
        
    }
    invertOrderTree(index);
    for(int i=0;i<n;++i){
        if(i!=n-1){
            printf("%d ",invOrder[i]);
        }else{
            printf("%d\n",invOrder[i]);
        }
        
    }
    return 0;
}
