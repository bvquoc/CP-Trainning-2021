#include<bits/stdc++.h>
#define ll long long
#define db double
#define maxx 1112
#define fi first
#define se second
#define pp pair<ll,ll>
#define pb push_back
#define mp make_pair
using namespace std;

struct qq{
    char c;
    int x,y;
};
const int oo=1e9;
string s;
int n,m;
int f[maxx][maxx];
qq q[maxx*100];
map<int,string > mym;


void build(int l){
    for(int i=l;i>=1;i--){
        for(int j=i;j<=n;j++){
            f[i][j]=oo;
            if(i==j)f[i][j]=1;
            else{
                if(s[i]=='('&&s[j]==')')
                    f[i][j]=min(f[i][j],f[i+1][j-1]);
                else{
                    f[i][j]=min(f[i+1][j]+1,f[i][j-1]+1);
                }
            }
            for(int t=i+1;t<j;t++){
                f[i][j]=min(f[i][j],f[i][t]+f[t+1][j]);
            }
        }
    }
}

void kaisa(){
    freopen("FIXSTR.INP","r",stdin);
    freopen("FIXSTR.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>s;
    n=s.size();s=" "+s;
    cin>>m;
    build(n);
    for(int i=1;i<=m;i++){
        cin>>q[i].c;
        if(q[i].c=='C'){
            cin>>q[i].x;
            if(s[q[i].x]=='(')s[q[i].x]=')';
            else s[q[i].x]='(';
            mym[i]=s;
            build(q[i].x);
        }
        else{
            if(q[i].c=='U'){
                cin>>q[i].x;
                s=mym[q[i].x-1];
                build(n);
            }
            else{
                cin>>q[i].x>>q[i].y;
                mym[i]=s;
                cout<<f[q[i].x][q[i].y]<<"\n";
            }
        }
//        cout<<s<<"\n";
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=n;j++){
//                cout<<f[i][j]<<" ";
//            }
//            cout<<"\n";
//        }
    }
//    for(int i=1;i<=m;i++){
//        cout<<q[i].c<<" "<<q[i].x<<" "<<q[i].y<<"\n";
//    }
}

int main()
{
    kaisa();

    return 0;
}
