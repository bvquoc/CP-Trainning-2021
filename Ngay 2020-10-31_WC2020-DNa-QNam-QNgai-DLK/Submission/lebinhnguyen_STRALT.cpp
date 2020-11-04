#include <bits/stdc++.h>
using namespace std;
string s;
int vt[200005];
void build()
{
    vector<int> st;
    int dem=0;
    for(int i=0;i<s.size();i++)
        if(s[i]=='(' || s[i]=='[')
           st.push_back(i),dem++;
        else
            if(s[i]==')' || s[i]==']')
            vt[st.back()]=i,st.pop_back();
    cout<<dem<<endl;
}
string dx(string s)
{
    string y=s;
    for(int i=s.size()-1;i>=0;i--)
        y=y+s[i];
    return y;
}
string dxx(string s)
{
    string y=s;
    for(int i=s.size()-2;i>=0;i--)
        y=y+s[i];
    return y;
}
string lt(string s, int mu)
{
    if(mu==0) return "";
    if(mu==1) return s;
    string ans=lt(s,mu>>1);
    ans=ans+ans;
    if(mu%2==1) ans=ans+s;
    return ans;
}
string pcach(int l, int r)
{
    string cmp;
    while(l<=r)
    {
        if(s[l]>=97 &&s[l]<=122) cmp=cmp+s[l];
        if(s[l]=='['|| s[l]=='(')
            {
            string cc=pcach(l+1,vt[l]-1);
            //ơcout<<cc<<endl;
            if(s[l]=='(')
            {
                int tam=0,tmp=1;
                int j=l-1;
                while(j>=0 &&s[j]>=48 && s[j]<=57) tam=tam+(s[j]-'0')*tmp,tmp*=10,j--;
                cmp=cmp+lt(cc,tam);
            }
            else
            {
                //cout<<s[st.back()]<endl;
                if(s[l+1]== '*')
                    cmp=cmp+dx(cc);
                else cmp=cmp+dxx(cc);
            }
            l=vt[l];
            }
        l++;
    }
    return cmp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    build();
    cout<<pcach(0,s.size()-1);
}
