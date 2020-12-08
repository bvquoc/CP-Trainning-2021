#include <bits/stdc++.h>

using namespace std;
int n,m,a[400001],sl=0;
int y[400001];
int x[10];
void up()
{
    stack <int> s;
    int dem=1;
    bool kq=true;
    for(int i=1;i<=2*n;i++)
        if(x[i]==1)
        {
            y[dem]=a[i]+m;
            s.push(dem);
            dem++;
        }
        else
        {
            int u;
            if(!s.empty())
            {
                u=s.top();
                s.pop();
            }
            if(y[u]<a[i])
            {
                kq=false;
                break;
            }
        }
    if(kq==true && dem==n) sl=(sl+1)%1000003;
}
void dq(int u)
{
    for(int i=0;i<=1;i++)
    {
        x[u]=i;
        if(u==2*n) up();
            else dq(u+1);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Mine.inp","r",stdin);
    freopen("Mine.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=2*n;i++) cin >> a[i];
    x[1]=1;
    dq(2);
    cout << sl << endl;
    return 0;
}
