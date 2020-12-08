/** Hien Jeony **/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define getbit(n,i) ((n>>(i-1))&1)
#define offbit(n,i) (n^(1<<(i-1)))
#define onbit(n,i) (n|(1<<(i-1)))
#define cntone(x) (__builtin_popcount(x))
const int mod=1e9+7;
using namespace std;
string xx,c;
int n,ans=0,m;
stack<bool> st;
string s,k[1001];
template <typename T> inline void read(T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-')
    {
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
    {
        x=x*10+c-48;
    }
    if(nega) x=-x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    cin>>s;
    cin>>m;
    for(int i=1;i<=m;i++){

        string c;
        int x,a,b;
        cin>>c;
        if(c=="C"){
            string xet="";
            k[i]=s;
            cin>>x;
            for(int i=0;i<s.size();i++){
                if(i==x-1){
                    if(s[i]==')')
                        xet+='(';
                    else
                        xet+=')';
                }
                else
                    xet+=s[i];
            }
            s=xet;
        }
        else{
             if(c=="Q"){
                int ans=0;
                cin>>a>>b;
                while(st.size()) st.pop();
                for(int x=a-1;x<b;x++){
                    if(s[x]==')'){
                        if(!st.size()){
                            st.push(1);
                            ans++;
                        }
                        st.pop();
                    }
                    else{
                        st.push(1);
                    }
                }
                ans+=st.size();
                cout<<ans<<'\n';
             }
             else{
                cin>>x;
                s=k[x];
             }
        }
    }
}

