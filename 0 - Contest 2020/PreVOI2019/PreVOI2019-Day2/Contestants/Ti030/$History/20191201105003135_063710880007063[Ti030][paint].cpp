#include <bits/stdc++.h>

using namespace std;
long long q,type,ans,vt=1;
char x,y;
char s[1000006];
queue <long long > a[200];
int main()
{
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>q;
    for (int k=1;k<=q;k++)
    {
        cin>>type>>x;
        if(type==1)
        {
            s[vt]=x;
            a[(x-0)].push(vt);
            vt++;
        }
        if(type==2)
        {
            cin>>y;
            long long tmp=x-0,tmp2=y-0;
            while(!a[tmp].empty())
            {
                long long v=a[tmp].front();
                a[tmp].pop();
                s[v]=y;
                a[tmp2].push(v);
            }
            //for (int i=1;i<=vt;i++)
              //  cout<<s[i];
            //cout<<endl;
        }
    }
    for (int i=1;i<=vt;i++)
        cout<<s[i];

    return 0;
}
