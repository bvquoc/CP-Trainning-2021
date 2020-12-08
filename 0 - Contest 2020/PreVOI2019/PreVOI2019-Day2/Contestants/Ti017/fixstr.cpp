#include<bits/stdc++.h>
using namespace std;
const int mn=1e6+6;
string s;
int n,q;
string tr[mn];
stack<int>st;
void lam()
{
    for(int hhh=1; hhh<=q; hhh++)
    {
        char tv;
        cin>>tv;
        tr[hhh]=s;
        if(tv=='C')
        {
            int i;
            cin>>i;
            if(s[i]==')')
                s[i]='(';
            else
                s[i]=')';
            continue;
        }
        if(tv=='U')
        {
            int k;
            cin>>k;
            s=tr[k];
            continue;
        }
        if(tv=='Q')
        {
            int l,r;
            cin>>l>>r;
            int res=0;
            for(int i=l; i<=r; i++)
            {
                if(s[i]=='(')
                    st.push(1);
                else
                {
                    if(st.empty())
                        res++;
                    else
                        st.pop();
                }
            }
            res+=st.size();
            while(!st.empty())st.pop();
            cout<<res<<'\n';
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    cin>>s;
    n=s.size();
    s='+'+s;
    cin>>q;
    lam();
    return 0;
}
