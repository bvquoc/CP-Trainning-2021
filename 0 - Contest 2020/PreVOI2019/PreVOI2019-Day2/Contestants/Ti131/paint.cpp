#include<bits/stdc++.h>
using namespace std;
#define fi   first
#define se   second
#define pb push_back
#define pu push
#define pii pair<int,int>
#define TASKNAME "paint"
int n,loai;
string s;
char kt,kt_;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen(TASKNAME".inp", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
    #endif
    cin>>n;
    //if (n<=10000)
    {
        while (n--)
        {
            cin>>loai;
            if (loai==1)
            {
                cin>>kt; s+=kt;
            }
            else
            {
                cin>>kt>>kt_;
                for (int i=0;i<s.size();i++) if (s[i]==kt) s[i]=kt_;
            }
        }
        cout<<s;
    }
    //else
    //{
        /*while (n--)
        {
            cin>>loai;
            if (loai==1) {cin>>kt;s+=kt;}
            else {   cin>>kt>>kt_;if (kt!=kt_)  {s.insert(kt);vt[kt-'a'].pb({s.size(),kt_-'a',n});}   }
        }
        for (int i=0;i<s.size();i++)
        {
            while (s.find(s[i])!=s.end())
            {
                for (auto z:vt[s[i]-'a']) if (dd[z.tt]!=i && )
                {

                }
            }
        }*/
    //}
    return 0;
}
