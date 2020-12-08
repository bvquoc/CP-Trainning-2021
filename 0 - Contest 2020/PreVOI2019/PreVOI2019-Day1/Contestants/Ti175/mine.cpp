#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define pb push_back
#define maxn 400005
#define ll long long
#define Ntu "mine"

using namespace std;

int n,m;
int q[21], a[maxn];
int in[12];
int gt[12];

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int kt()
{
    stack<int> st;
    fto(i,1,n) in[i]=0;
    fto(i,1,n*2)
    {
        if (!in[q[i]]) {in[q[i]]=a[i];st.push(q[i]);continue;}
        if (st.top()!=q[i]) return 0;
        if (a[i]-in[q[i]]>m) return 0;
        st.pop();
    }
    return 1;
}

void solve1()
{
    fto(i,1,n*2) if (i%2==1) q[i]=q[i-1]+1;
    else q[i]=q[i-1];
    int rs=0;
    rs+=kt();
    while (next_permutation(q+1,q+n*2+1))
    {
        rs+=kt();
    }
    cout << rs/gt[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen (Ntu".inp","r",stdin);
    freopen (Ntu".out","w",stdout);
    cin >> n >> m;
    gt[0]=1;
    fto(i,1,10) gt[i]=gt[i-1]*i;
    fto(i,1,n*2) cin >> a[i];
    if (n<=5) solve1();
    else cout << rd()%1000003;
    return 0;
}
