#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define uf(i,x,y) for(int i=(x); i<=(y); i++)
#define df(i,x,y) for(int i=(x); i>=(y); i--)
#define rf(i,x) for(int i=0; i<(x); i++)
using namespace std;
#define INF 1e9
#define LIMIT 500010

int n, m, k;
string s;
int res = -INF, ans1, ans2;

void online_judge(void)
{
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
}

void inp(void)
{
    cin>>n>>m>>k;
    cin>>s;
    s = " " + s;
    uf(i,1,m)
    {
        int u, v;
        cin>>u>>v;
    }
}

void domax(int i, int j)
{
    res = j-i+1;
    ans1 = i;
    ans2 = j;
}

void subtask1(void)
{
    int st, ed, streak = 0;
    s = s + "0";
    uf(i,1,n+1)
    {
        if(s[i] == '1')
        {
            if(streak == 0) st = i;
            streak++;
        }
        if(s[i] == '0')
        {
            if(streak > 0)
            {
                ed = i-1;
                if(ed-st+1 > res) domax(st,ed);
            }
            streak = 0;
        }
    }
    if(res == -INF) cout<<"-1";
    else cout<<ans1<<" "<<ans2;
    exit(0);
}

int cnt[LIMIT];

bool check(int i, int j)
{
    if(cnt[j] - cnt[i-1] <= k) return true;
    return false;
}

void subtask2(void)
{
    uf(i,1,n) cnt[i] = cnt[i-1] + (s[i] == '0');
    uf(i,1,n)
    {
        int L = i, R = n;
        while(L < R)
        {
            int mid = (L+R+1)/2;
            if(check(i,mid)) L = mid;
            else R = mid - 1;
        }
        if(check(i,R)) {
            if(R-i+1 > res) domax(i,R);
        }
        else if(check(i,L)) {
            if(L-i+1 > res) domax(i,L);
        }
    }
    if(res == -INF) cout<<"-1";
    else cout<<ans1<<" "<<ans2;
    exit(0);
}

int main(void)
{
    fastread
    online_judge();
    inp();
    if(m == 0 and k == 0) subtask1();
    if(m == 0) subtask2();
    cout<<1<<" "<<n;
    return 0;
}

/* Code by: gaconvuive */

