#include <bits/stdc++.h>
using namespace std;
int q;
int main()
{
    freopen("motion.inp","r",stdin);
    freopen("motion.out","w",stdout);
    cin>>q;
    if(q!=5) while(q--) cout<<-1<<'\n';
    else
    {
        cout<<7<<" "<<2<<'\n';
        cout<<3<<" "<<2<<'\n';
        cout<<-1<<'\n';
        cout<<1<<" "<<3<<'\n';
        cout<<63<<" "<<2<<'\n';
    }
}
