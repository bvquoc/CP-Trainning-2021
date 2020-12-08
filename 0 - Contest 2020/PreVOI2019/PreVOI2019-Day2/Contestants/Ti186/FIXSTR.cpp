#include <bits/stdc++.h>

using namespace std;
const int nmax=1e6+5;
string s,mem[nmax];
int n,dem;
stack<int> st;
void cal(){
    if(!st.empty()) st.pop();
    else dem++;
}

void xuli(int l,int r){
    while(!st.empty()) st.pop();
    dem=0;
    for(int i=l;i<=r;i++){
        if(s[i]=='(') st.push(1);
        else cal();
    }
    cout<<dem+st.size()<<endl;
}

void sub1(){
    for(int i=1;i<=n;i++){
        mem[i]=s;
        char id;
        cin>>id;
        if(id=='U') {
            int j;
            cin>>j;
            s=mem[j];
        }
        if(id=='C'){
            int j;
            cin>>j;
            char tmp=s[j];
            s.erase(j,1);
            if(tmp==')') s.insert(j,"("); else s.insert(j,")");
        }
        if(id=='Q'){
            int l,r;
            cin>>l>>r;
            xuli(l,r);
        }
    }
}

void sub2(){
    for(int i=1;i<=n;i++){
        mem[i]=s;
        char id;
        cin>>id;
        if(id=='U') {
            int j;
            cin>>j;
            s=mem[j];
        }
        if(id=='C'){
            int j;
            cin>>j;
            char tmp=s[j];
            s.erase(j,1);
            if(tmp==')') s.insert(j,"("); else s.insert(j,")");
        }
        if(id=='Q'){
            int l,r;
            cin>>l>>r;
            xuli(l,r);
        }
    }
}

int main()
{
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    cin>>s;
    s=" "+s;
    cin>>n;
    if(n<=1000 && s.length()<=1001 ) sub1();
    else sub2();

}
