#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s,st,st2;
	int k,nn,kq,i;
	stack<string> ss;
	cin>>s;
    kq=0;
	for (i=0;i<s.size();i++)
        if (s[i]==')')
		{
            kq++;
            st = "";
            while (ss.top() != "(")
            {
                st=ss.top()+st;
                ss.pop();
            }
            ss.pop();
            k=1; nn=0;
            while (!ss.empty() && ss.top().size()==1 && ss.top()[0]>='0' && ss.top()[0]<='9')
            {
                nn+=k*(int(ss.top()[0]) - 48);
                k=k*10;
                ss.pop();
            }
            st2="";
            while (nn--) st2+=st;
            ss.push(st2);
		}
		else
            if (s[i] ==']'&&s[i-1]=='*')
            {
                kq++; st="";
                while (ss.top()!="[")
                {
                    st=ss.top()+st;
                    ss.pop();
                }
                ss.pop();
                st.erase(st.size() - 1, 1);
                st2=st; reverse(st2.begin(),st2.end()); st2.erase(0, 1); st+=st2; ss.push(st);
            }
            else
                if (s[i]==']')
                {
                    kq++; st="";
                    while (ss.top()!="[")
                    {
                        st= ss.top()+st;  ss.pop();
                    }
                    ss.pop();
                    st.erase(0, 1); st2=st; reverse(st2.begin(),st2.end()); st+=st2;ss.push(st);
                }
                else
                {
                    st=""; st+=s[i]; ss.push(st);
                }
    st="";
    while (!ss.empty())
    {
        st=ss.top()+st;
        ss.pop();
    }
    cout<<kq<<endl<<st;
}
