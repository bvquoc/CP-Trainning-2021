#include <bits/stdc++.h>

using namespace std;
int t,m,n,a[100001],b1[100001];
long long tree[400004];
void b(int d,int c,int k)
{
    if(d>c) return;
    if(d==c)
    {
        tree[k]=a[d]-a[d-1];
        return;
    }
    int g=(d+c)/2;
    b(d,g,k*2);
    b(g+1,c,k*2+1);
    if(tree[k*2]>=0) tree[k]+=tree[k*2];
    if(tree[k*2+1]>=0) tree[k]+=tree[k*2+1];
}
void up(int d,int c,int k,int l,int val)
{
    if(d>c || l<d || l>c) return;
    if(d==c && d==l)
    {
        tree[k]+=val;
        return;
    }
    int g=(d+c)/2;
    up(d,g,k*2,l,val);
    up(g+1,c,k*2+1,l,val);
    tree[k]=0;
    if(tree[k*2]>=0) tree[k]+=tree[k*2];
    if(tree[k*2+1]>=0) tree[k]+=tree[k*2+1];
}
long long get(int d,int c,int k,int l,int r)
{
    if(d>c || r<d || l>c) return 0;
    if(l<=d && c<=r)
    {
        if(tree[k]>=0) return tree[k];
            else return 0;
    }
    int g=(d+c)/2;
    return get(d,g,k*2,l,r)+get(g+1,c,k*2+1,l,r);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Construct.inp","r",stdin);
    freopen("Construct.out","w",stdout);
    cin >> t;
    while(t-->0)
    {
        cin >> n >> m;
        for(int i=1;i<=n;i++) cin >> a[i];
        b(1,n,1);
        for(int i=1;i<=m;i++)
        {
            int x,y,z,k;
            cin >> x >> y >> z;
            if(x==1)
            {
                cin >> k;
                if(n<=1000 && m<=1000) for(int j=y;j<=z;j++) a[j]+=k;
                    else
                    {
                        b1[y]+=k;
                        b1[z]-=k;
                        up(1,n,1,y,k);
                        up(1,n,1,z+1,-k);
                    }
            }
            else
            {
                long long s;
                if(n<=1000 && m<=1000)
                {
                    s=a[y];
                    for(int j=y+1;j<=z;j++)
                        if(a[j]>a[j-1]) s+=a[j]-a[j-1];
                }
                else
                {
                    long long s1=a[y];
                    for(int i=1;i<=y;i++) s1+=b1[i];
                    s=max(s1+get(1,n,1,y+1,z),get(1,n,1,y,z));
                }
                cout << s <<endl;
            }
        }
    }
    return 0;
}
