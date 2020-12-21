#include <bits/stdc++.h>

using namespace std;
int n,m,k; string s;
struct node
{
    int a,b;
}f[5000];
void sub_task_1()
{
    int maxi=0,cnt=0;
    for(int i=0; i<s.length(); i++)
        if(s[i]=='1') cnt++; else { maxi=max(maxi,cnt); cnt=0; }
    cout<<maxi<<endl;
    return;
}

void sub_task_2()
{
    int cnt=0,pos_max=0,cnt_zero=0;
    map<int,int> get,zero; map<int,int>::iterator it,L,R;
    get[0]=0; get[n]=0; s+='0';
    for(int i=0; i<s.length(); i++)
        if(s[i]=='1') cnt++; else
        {
          cnt_zero++; zero[i]=cnt_zero;
        if(cnt!=0)
        { get[i-1]=cnt;  cnt=0; }
        }
return;
}
int main()
{
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    cin>>n>>m>>k>>s;
    for(int i=1; i<=m; i++) cin>>f[i].a>>f[i].b;
    if(m==0&&k==0) sub_task_1(); else
    if(m==0) sub_task_2();
    return 0;
}
