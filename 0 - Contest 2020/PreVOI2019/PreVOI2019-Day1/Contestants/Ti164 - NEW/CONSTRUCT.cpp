#include <bits/stdc++.h>

using namespace std;
int test;
int m,n;
int a[100001];
int h[100001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("CONSTRUCT.inp","r",stdin);
    freopen("CONSTRUCT.out","w",stdout);
    cin>>test;
    for(int tt=1;tt<=test;tt++)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=m;i++)
        {
            int num;
            cin>>num;
            if(num==1)
            {
                int l,r,k;
                cin>>l>>r>>k;
                for(int j=l;j<=r;j++)
                    a[j]+=k;
            }
            else
            {
                int l,r;
                cin>>l>>r;
                for(int j=l;j<=r;j++)
                    h[j]=a[j];
                long long res=0;
                while(true)
                {
                    int Min=1e9;
                    int cnt=0;
                    int pos1,pos2;
                    for(int j=l;j<=r;j++)
                    {
                        if(cnt==1&&h[j]==0)
                        {
                            break;
                        }
                        if(h[j]!=0&&cnt==0)
                        {
                            cnt=1;
                            pos1=j;
                            pos2=j;
                            Min=min(Min,h[j]);
                            //if(h[j+1]==0) break;
                            continue;
                        }
                        if(cnt==1&&h[j]>0)
                        {
                            Min=min(Min,h[j]);
                            pos2=j;
                            continue;
                        }

                    }
                    if(Min==1e9) break;
                    res+=Min;
                    for(int j=pos1;j<=pos2;j++)
                        h[j]-=Min;
                }
                cout<<res<<'\n';

            }
        }
    }
    return 0;
}
