#include<bits/stdc++.h>
using namespace std;
const long N=1e6+5,AS=300;
long n,l[N],sl[AS][AS];
char kt[N],bd[N];
char ke[AS];
char lab[AS];
int main()
{
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(char i='a';i<='z';i++)
        lab[i]=i;
    cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>l[i]>>kt[i];
        if(l[i]==2)
        {
            cin>>bd[i];

            lab[kt[i]]=bd[i];
            for(char j='a';j<='z';j++)
            if (lab[j]==kt[i]) lab[j]=bd[i];

            ke[kt[i]]=bd[i];
            sl[kt[i]][bd[i]]++;
        }
    }
    for(long i=1;i<=n;i++)
    if(l[i]==1)
       cout<<lab[kt[i]];
    else{
        sl[kt[i]][bd[i]]--;
        if(bd[i]==ke[kt[i]] && sl[kt[i]][bd[i]]==0)
           lab[kt[i]]=kt[i];
    }
    return 0;
}
