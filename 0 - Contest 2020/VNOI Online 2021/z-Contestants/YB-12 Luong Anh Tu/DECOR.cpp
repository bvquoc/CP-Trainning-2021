#include<bits/stdc++.h>
#define file "DECOR"
using namespace std;
int n,m,k;
int a[1000003];
int b[1000003];
void solve1()
{
pair<int,int> ans;
    int maxx=0;
    for (int i=1; i<=n; i++)
    {
        if (a[i]!=0) a[i]+=a[i-1];
        if (a[i]>maxx)
        {
            maxx=a[i];
            ans={i-a[i]+1,i};
        }
    }
    cout<<ans.first<<" "<<ans.second;
}

void solve2()
{
    pair<int,int> ans;
    for (int i=1; i<=n; i++)
    {
        b[i]=b[i-1]+1;
        if (a[i]==1) b[i]--;
    }
    for (int i=1; i<=n; i++)
    {
        int pos;
        if (a[i]==0) pos=lower_bound(b+1, b+n+1, b[i]+k-1)-b; else
        if (a[i]==1) pos=lower_bound(b+1, b+n+1, b[i]+k)-b;
        while (a[pos+1]==1) pos++;
        pos=min(pos,n);
        if (pos-i>ans.second-ans.first)
        ans={i,pos};
    }
   cout<<ans.first<<" "<<ans.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);

    cin>>n>>m>>k;
    char tmp;
    for (int i=1; i<=n; i++)
    {
        cin>>tmp;
        a[i]=int(tmp-48);
    }

    if (m==0 && k==0) solve1(); else
    if (m==0) solve2();
    return 0;

}
