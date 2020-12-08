#include <bits/stdc++.h>

using namespace std;
int n;
int a[1000001];
vector<int> pos[30];
char prechar[300];
struct queries
{
    int qq;
    char x;
    char y;
};
void mt()
{
    freopen("PAINT.inp","w",stdout);
    srand(time(NULL));
    int n=rand()%11+1;
    cout<<n<<'\n';
    for(int i=1;i<=n;i++)
    {
        int pp=rand()%2+1;
        cout<<pp<<' ';
        if(pp==1)
        {
            cout<<char(rand()%26+97)<<'\n';
        }
        else
        {
            cout<<char(rand()%26+97)<<' ';
            cout<<char(rand()%26+97)<<'\n';
        }
    }
}
queries q[1000001];
int main()
{
    //mt();
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    cin>>n;
    for(int i=int('a');i<=int('z');i++)
        prechar[i]=char(i);
    //cout<<char(25+97)<<'\n';
    for(int i=1;i<=n;i++)
    {
        cin>>q[i].qq;
        if(q[i].qq==1)
        {
            cin>>q[i].x;
        }
        else
        {
            cin>>q[i].x>>q[i].y;
        }
    }
    int start=0;
    for(int i=n;i>=1;i--)
    {
        if(q[i].qq==2)
        {
            prechar[q[i].x]=prechar[q[i].y];
        }
        else
        {
            q[i].x=prechar[q[i].x];
        }
    }
    for(int i=1;i<=n;i++)
        if(q[i].qq==1) cout<<q[i].x;
    return 0;
}
