///EmperorD: @npd.28
#include <bits/stdc++.h>
#define EmperorD "PAINT"
#define ll long long
#define ull unsigned long long
#define el '\n'
#define fi first
#define se second
#define pll pair<long long, long long>
#define pii pair<int,int>
#define piii pair<int,pii>
#define mp make_pair
#define pb push_back
#define forinc(i,a,b) for(int i=a;i<=b;i++)
#define fordec(i,a,b) for(int i=a;i>=b;i--)
#define forv(a,b) for(auto &a:b)
#define reset(f,x) memset(f,x,sizeof(f))
#define mod 10000007
using namespace std;
const int oo=1e9+7;

int get()
{
    int tmp = 0;
    char x = getchar();
    bool Neg = false;
    while(x == ' ' || x == '\n')
        x = getchar();
    if(x == '-')
        Neg = true, x = getchar();
    while('0' <= x && x <= '9')
        tmp = tmp * 10 + (x - '0'), x = getchar();
    if(Neg)
        return -tmp;
    return tmp;
}
int n;
int N;
vector <int> m[10000];
vector <int> room;
void input()
{
    cin >>n;
	int type;
	char x,y;
	N=1000000;
    for(int i=N;i>=1;i--) room.pb(i);
	for (int i=1;i<=n;i++)
    {
        cin >>type;
//        type=get();
        if (type==1)
        {
            cin >>x;
            int temp=(int)(x);
            int t=room.back();
            m[temp].pb(t);
            room.pop_back();
        }
        else
        {
            cin >>x>>y;
            if (x==y) continue;
            int temp1,temp2;
            temp1=(int)(x);
            temp2=(int)(y);
            for(int i=0;i<m[temp1].size();i++)
            {
                m[temp2].push_back(m[temp1][i]);
            }
            m[temp1].clear();
        }
    }
    vector < pii > ans;
    int t=(int)('a');
    int s=(int)('z');
    for (char i=t; i<=s;i++)
    {
//        x=(char)(i);
        for (int j=0;j<m[i].size();j++) ans.pb(mp(m[i][j],i));
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) cout <<(char)ans[i].second;
}
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen (EmperorD".inp","r",stdin);
    freopen (EmperorD".out","w",stdout);
	input();
    return 0;
}
