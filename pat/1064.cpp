#include <iostream>
#include <algorithm>
#define MAXN 10000
using namespace std;
int sum[MAXN];
int ans[MAXN];
int n;
int i=1;
void Tree(int index){
    if(index>n){
        return;
    }
    Tree(index*2);
    ans[index]=sum[i++];
    Tree(index*2+1);
    
    
}
int main(int argc, const char * argv[]) {
    //int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",sum+i);
    }
    sort(sum+1, sum+n+1);
    Tree(1);
    printf("%d",ans[1]);
    for(int i=2;i<=n;++i){
        printf(" %d",ans[i]);
    }
    printf("\n");
    return 0;
}
