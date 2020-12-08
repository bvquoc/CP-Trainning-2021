#include <bits/stdc++.h>

using namespace std;

string t[1001];

int n,m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);

    string s;
    cin>>s;
    t[0]=s;
    int n; cin>>n;
    if (n<=1000 && s.length()<=1000)
    {
        for (int z=1; z<=n; ++z)
        {
            char c;
            cin>>c;
            if (c=='C')
            {
                int i; cin>>i;
                --i;
                if (s[i]=='(')
                {
                    s[i]=')';
                }
                else
                {
                    s[i]='(';
                }
            }
            if (c=='Q')
            {
                int i,j; cin>>i>>j;
                --i; --j;
                int mxcl=0,cl=0;
                for (int z=i; z<=j; ++z)
                {
                    if (s[z]==')')
                    {
                        --cl;
                        mxcl=min(mxcl,cl);
                    }
                    else
                        ++cl;
                }
                int mxop=0,op=0;
                for (int z=j; z>=i; --z)
                {
                    if (s[z]=='(')
                    {
                        ++op;
                        mxop=max(mxop,op);
                    }
                    else
                        --op;
                }
                cout<<-mxcl+mxop<<'\n';
            }
            if (c=='U')
            {
                int i; cin>>i;
                s=t[i-1];
            }
            t[z]=s;
        }
        return 0;
    }

        for (int z=1; z<=n; ++z)
        {
            char c;
            cin>>c;
            if (c=='C')
            {
                int i; cin>>i;
                --i;
                if (s[i]=='(')
                {
                    s[i]=')';
                }
                else
                {
                    s[i]='(';
                }
            }
            if (c=='Q')
            {
                int i,j; cin>>i>>j;
                --i; --j;
                int mxcl=0,cl=0;
                for (int z=i; z<=j; ++z)
                {
                    if (s[z]==')')
                    {
                        --cl;
                        mxcl=min(mxcl,cl);
                    }
                    else
                        ++cl;
                }
                int mxop=0,op=0;
                for (int z=j; z>=i; --z)
                {
                    if (s[z]=='(')
                    {
                        ++op;
                        mxop=max(mxop,op);
                    }
                    else
                        --op;
                }
                cout<<-mxcl+mxop<<'\n';
            }
            if (c=='U')
            {
                cout<<"U oi U cuu con U oi"<<'\n';
            }
        }
    return 0;
}
