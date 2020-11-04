#include <bits/stdc++.h>
using namespace std;
string extract(int rpt, string st)
{
    string res;
    while (rpt--)
    {
        res+=st;
    }
    return res;
}
string make_even_palindrome_string(string st)
{
    string temp=st;
    reverse(st.begin(), st.end());
    return temp+st;
}
string make_odd_palindrome_string(string st)
{
    string temp=st;
    reverse(st.begin(), st.end());
    for(int i=1; i<st.size(); i++)
        temp+=st[i];
    return temp;
}
int dem=0;
int convert(string s)
{
    int res=0;
    for(int i=0; i<s.size(); i++)
        res=res*10+((int)(s[i]-'0'));
    return res;
}
string biendoi(string st)
{
    string res="",temp="",stnum="";
    int cir=0, squ=0;
    for(int i=0; i<st.size(); i++)
    {
        if (st[i]>='a' && st[i]<='z') res+=st[i];
        if (st[i]>='0' && st[i]<='9') stnum+=st[i];
        if (st[i]=='(')
        {
            dem++;
            int so=convert(stnum);
            stnum="";
            int j=i+1;
            cir++;
            while (true)
            {
                if (st[j]=='(') cir++;
                if (st[j]==')') cir--;
                if (cir==0) break;
                temp+=st[j];
                j++;
            }
            res+=extract(so,biendoi(temp));
            if (j+1<=st.size()-1) res=res+biendoi(st.substr(j+1,st.size()-j));
            return res;
        }
        if(st[i]=='[')
        {
            squ=1;
            dem++;
            if (st[i+1]=='*')
            {
                int j=i+2;
                string temp="";
                while (true)
                {
                    if (st[j]=='[') squ++;
                    if (st[j]==']') squ--;
                    if (squ==0) break;
                    temp+=st[j];
                    j++;
                }
                res+=make_even_palindrome_string(biendoi(temp));
                if (j+1<=st.size()-1) res+=biendoi(st.substr(j+1,st.size()-j));
                return res;
            }
            else
            {
                int j=i+1;
                string temp="",pre;
                while (true)
                {
                    if (st[j]=='[') squ++;
                    if (st[j]==']') squ--;
                    if (squ==0) break;
                    pre=temp;
                    temp+=st[j];
                    j++;
                }
                temp=pre;
                res+=make_odd_palindrome_string(biendoi(temp));
                if (j+1<st.size()) res+=biendoi(st.substr(j+1,st.size()-j));
                return res;
            }
        }
    }
    return st;
}

int main()
{
    string st;
    cin>>st;
    string ans=biendoi(st);
    cout<<dem<<"\n"<<ans;
}

