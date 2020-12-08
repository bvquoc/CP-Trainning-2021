#include<bits/stdc++.h>
using namespace std;
#define ft first
#define se second
#define iP pair<int,int>
#define iiP pair<int,pair<int,int> >
#define ll long long
#define lP pair<ll,int>
#define db long double
#define fu(i, a, b) for (int i = a; i <= b; ++i)
const int N=1e6+5;
template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c))
    {
        x=x*10+c-48;
        c=getchar();
    }
}
string s;
int n;
string s1[N];
vector<int> qu[N];
char c[N];
stack<char> s2;
void sub1()
{
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        if(c=='C'){
            int k;
            cin>>k;
            if(s[k-1]==')') s[k-1]='(';
            else s[k-1]=')';
            //cout<<s<<endl;
            s1[i]=s;
        }
        if(c=='Q'){
            int l,r;
            while(!s2.empty()) s2.pop();
            cin>>l>>r;
            for(int j=l;j<=r;j++){
                if(!s2.empty() && s2.top()=='(' && s[j-1]==')' ) {s2.pop();continue;}
                s2.push(s[j-1]);
            }
            cout<<s2.size()<<endl;
            s1[i]=s1[i-1];
        }
        if(c=='U')
        {
            int k;
            cin>>k;
            s=s1[k-1];
            //cout<<s<<endl;
            s1[i]=s;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FIXSTR.INP","r",stdin);
    freopen("FIXSTR.OUT","w",stdout);
    cin>>s;
    cin>>n;
    int d=0;
    //if(s.length()<=1000 && n<=1000){
        sub1();return 0;
    //}
}
