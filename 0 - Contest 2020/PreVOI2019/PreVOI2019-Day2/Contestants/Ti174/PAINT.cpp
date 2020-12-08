#include<bits/stdc++.h>
#define ll long long
#define db double
#define maxx 200112
#define fi first
#define se second
#define pp pair<ll,ll>
#define pb push_back
#define mp make_pair
using namespace std;

struct qq{
    char c;
    int r;
};

int n;
string s="";
map<char,qq> m;
unordered_map<char,int> spon;

void sub1(){
    while(n--){
        int type;
        char x,y;
        cin>>type;
        if(type==1){
            cin>>x;
            s=s+x;
        }
        else{
            cin>>x>>y;
            for(int i=0;i<s.size();i++){
                if(s[i]==x)s[i]=y;
            }
        }
    }
    cout<<s;
}

void sub2(){
    while(n--){
        int type;
        char x,y;
        cin>>type;
        if(type==1){
            cin>>x;
            spon[x]++;
            s=s+x;
        }
        else{
            cin>>x>>y;
            if(x==y)continue;
            if(spon[x]==0)continue;
            for(auto temp:m){
                if(temp.se.c==x)
                    m[temp.fi]={y,temp.se.r};
            }
            if(m[x].r==0)
                m[x]={y,int(s.size())-1};
        }
    }
//    cout<<s<<"\n";
//    for(auto temp:m){
//        cout<<temp.fi<<" "<<temp.se.c<<" "<<temp.se.r<<"\n";
//    }
//    for(int i=0;i<s.size();i++){
//        while((m[s[i]].r!=0&&m[s[i]].l<=i&&i<=m[s[i]].r){
//            s[i]=m[s[i]].x;
//        }
//    }
//    cout<<s;
//    cout<<"\n";
    for(int i=0;i<s.size();i++){
        if(m[s[i]].r==0)continue;
        if(m[s[i]].r>=i)
            s[i]=m[s[i]].c;
    }
    cout<<s;
}

void kaisa(){
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    if(n<=1000){
        sub1();
    }
    else{
        sub2();
    }
}

int main()
{
    kaisa();

    return 0;
}
