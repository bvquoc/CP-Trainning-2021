#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,k;
string s;
int main()
{
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
    cin >>n>>m>>k;
    cin >>s;
    if (m==0)
    {
        if (k==0)
        {
            int tmp=0,res=0,last=0;;
            for (int i=0; i<s.size(); i++)
            {
                if (s[i]=='1')
                    tmp++;
                else
                    tmp=0;
                if (res<tmp)
                {
                    res=tmp;
                    last=i;
                }
            }
            cout <<last+2-res<<" "<<last+1;
        }
        else
        {
            int tmp=0,res=0,last=0;
            for (int i=0; i<s.size(); i++)
            {
                if (s[i]=='1')
                    tmp++;
                else
                    tmp=0;
                if (res<tmp)
                {
                    res=tmp;
                    last=i;
                }
            }
            int l=last+1-res;
            int r=last;
            while (k>0)
            {
                while (k>0)
                {
                    l--;
                    if (l<0)
                        break;
                    if (s[l]=='0')
                    {
                        s[l]='1';
                        k--;
                    }
                }
                while (k>0)
                {
                    r++;
                    if (r==s.size())
                        break;
                    if (s[r]=='0')
                    {
                        s[r]='1';
                        k--;
                    }
                }
            }
             tmp=0,res=0,last=0;
            for (int i=0; i<s.size(); i++)
            {
                if (s[i]=='1')
                    tmp++;
                else
                    tmp=0;
                if (res<tmp)
                {
                    res=tmp;
                    last=i;
                }
            }
            cout <<last+2-res<<" "<<last+1;
        }
    }
	else cout <<"-1";
    /*for (int i=1; i<=m; i++)
        cin >>a[i].first>>a[i].second;*/
    return 0;
}
