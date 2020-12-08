#include <bits/stdc++.h>
#define name "paint"
#define Debug(x) cout<< #x << " = " << x << '\n'
using namespace std;
const int N=1e6+6;
int n,dem;
vector <int> a;
int mau[30];
int q[30][N];
int main()
{
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=0;i<26;i++){
        mau[i]=i;
    }
    int Type;
    char c, m;
    for (int i=1;i<=n;i++){
        cin>>Type;
        cin>>c;
        if (Type == 1){
            int z= c-'a';
            a.push_back(z);
            q[z][0]++;
            q[z][q[z][0]]=a.size()-1;
        }
        if (Type == 2){
            cin>>m;
            int the= c-'a';
            int t=m-'a';
            for (int j=1;j<=q[the][0];j++){
                    a[q[the][j]] = t;
                    q[j][0]++;
                    q[j][q[j][0]]=q[the][j];
            }
            q[the][0]=0;
        }
    }
    for (int i=0;i<a.size();i++){
        cout<<(char)(a[i]+'a');
    }
    return 0;
}
