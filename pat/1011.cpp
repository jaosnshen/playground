#include <iostream>
#include <algorithm>
using namespace std;
struct odds{
    char number;
    float single_odd;
};
odds odd[3][3];
bool cmp(const odds a,const odds b){
    if (a.single_odd<=b.single_odd){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    int i,j;
    float ans=1.0;
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            if (j==0){
                odd[i][j].number='W';
            }
            else if (j==1){
                odd[i][j].number='T';
            }
            else{
                odd[i][j].number='L';
            }
            cin>>odd[i][j].single_odd;
        }
        sort(odd[i],odd[i]+3,cmp);
        //ans*=min(odd[i][0]->single_odd,min(n[i][1].single_odd,n[i][2].single_odd));
        ans*=odd[i][2].single_odd;
    }
    
    for (i=0;i<3;i++)
    {
        cout<<odd[i][2].number<<" ";
    }
    ans=(ans*0.65-1.0)*2.0;
    printf("%.2f\n",ans);
    system("pause");
    return 0;
}