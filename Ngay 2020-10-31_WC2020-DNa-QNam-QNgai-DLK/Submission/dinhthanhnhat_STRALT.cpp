#include<bits/stdc++.h>
using namespace std;
string s,S,m;
stack <string> bs;
int main()
{
    
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
	cin>>s;
	long long res = 0 ; 
	for (long long i=0;i<s.size();i++)
		if (s[i]==')')
		{
		    res++;
            m="";
            while (bs.top() != "(")
            {
                m=bs.top()+m;
        bs.pop();
            }
            bs.pop();
            long long t1=1,t0=0;
            while (!bs.empty() &&bs.top().size()==1&&bs.top()[0]>='0'&&bs.top()[0]<='9')
            {
                t0+=t1*((long long )( bs.top()[0] - '0'));
                t1=t1*10;  bs.pop();
            } 
            S=""; 
            while (t0--) S+=m;   
            bs.push(S);
		} 
        else
		 if (s[i] ==']'&&s[i-1]=='*')
        {
            res++; m="";
            while (bs.top()!="[")
            {
                m=bs.top()+m;
        bs.pop();
            }
            bs.pop();
            m.erase(m.size() - 1, 1);
            S=m; reverse(S.begin(),S.end()); S.erase(0, 1); m+=S; bs.push(m);
        }
        else 
         if (s[i]==']')
        {
            res++; m="";
            while (bs.top()!="[")
            {
                m=bs.top()+m;
        bs.pop();
            }
            bs.pop();
            m.erase(0, 1); S=m; reverse(S.begin(),S.end()); m+=S;bs.push(m); 
        }
        else 
        {
                m=""; m+=s[i]; bs.push(m);
		}
	m="";
    while (!bs.empty())
    { 
        m=bs.top()+m;
        bs.pop();
    }
    cout<<res<<endl<<m;
}
