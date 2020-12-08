#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

string S=" ",dd[maxn];
int m,lenh=0;

void xulyC()
{
    dd[++lenh]=S;
    int vt; cin>>vt;
    if (S[vt]=='(') S.erase(vt,1), S.insert(vt,")");
    else if (S[vt]==')') S.erase(vt,1), S.insert(vt,"(");
    //cerr<<lenh<<" "<<S<<"\n";
}

void xulyU()
{
    int TT; cin>>TT;
    dd[++lenh]=S; S=dd[TT];
}

void xulyQ()
{
    dd[++lenh]=S;
    string X=""; int dau,cuoi; cin>>dau>>cuoi;
    for (int i=dau; i<=cuoi; i++) X=X+S[i];
    if (X[1]!=' ') X=" "+X;
    //cerr<<lenh<<" "<<X<<"\n";
    int vt=X.find("()");
    while (vt>0 && X.length()>0) X.erase(vt,2), vt=X.find("()"); //cerr<<"\n";
    vt=X.find("{}");
    while (vt>0 && X.length()>0) X.erase(vt,2), vt=X.find("{}");
    cout<<X.length()-1<<"\n";
}

int main()
{
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    cin>>S; cin>>m; S=" "+S;
    for (int i=1; i<=m; i++)
    {
        char key; cin>>key;
        if (key=='C') xulyC();
        else if (key=='Q') xulyQ();
             else if (key=='U') xulyU();
    }
}
/*
using namespace std;
int main ()
{
    string str="ConCho chay qua rao";
    cout << str.find("chay") << endl; // 7
    cout << (int)str.find("Chay") << endl; // -1
    getchar();
    return 0;
}*/
