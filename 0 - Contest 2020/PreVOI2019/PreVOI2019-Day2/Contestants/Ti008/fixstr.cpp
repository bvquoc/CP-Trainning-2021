/*
 ──────────────────────────────────────
 ─▄▄▄───────────▄▄▄▄▄▄▄────────────────
 █▀░▀█──────▄▀▀▀░░░░░░░▀▀▄▄────────────
 █░░░░█───▄▀░░░░░░░░░░░░░░░▀▄───────▄▄▄
 █▄░░░▀▄▄▀░░██░░░░░░░░░░░░░░▀█────█▀▀░█
 ─█░░░░█▀░░░▀░░░░░░░░██░░░░░░▀█─▄█░░░░█
 ─▀█░░▄█░░░░░░░▄▄▄░░░░▀░░░░░░░███░░░░█▀
 ──█▄░█░░░░░▄███████▄░░░░░░░░░█▀░░░░▄▀─
 ──▀█░█░░░░▄██████████░░░░░░░▄█░░░░▄▀──
 ───███░░░░███████████░░░░░░▄█░░░░█▀───
 ────█░░░░░██████████▀░░░░░░█░░░░█▀────
 ────█░░░░░░▀███████▀░░░░░░░█▄▄▄▀──────
 ────█░░░░░░░░▀▀▀▀░░░░░░░░░░░▀█────────
 ────█░░░░░░░░░░░░░░░░░░░░░░░░█────────
 ────█░░░░░░░░░░░░░░░░░░░░░░░░█────────
 ────█░░░░░░░░░░░░░░░░░░░░░░░░█────────
 ──────────────────────────────────────
 */
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
string a[maxn],s;
int m;
 bool kt[maxn];
int tinh(string qat)
{
    int
    n=qat.size(),yqat=0;
    qat=" "+qat;

    for (int i=0;i<=n;i++) kt[i]=false;
    for (int i=1;i<n;i++)
    {
        int j=0;
        if (qat[i]=='(' && qat[i+1]==')')
        while (qat[i-j]=='(' && qat[i+1+j]==')' && i+j+1<=n)
        {
            kt[i-j]=kt[i+j+1]=true;
            j++;
        }
    }
    for (int i=1;i<=n;i++) if (!kt[i]) yqat++;
    return yqat;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    cin>>s;
    s=" "+s;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        char x;
        int y,z;
        a[i]=s;
        cin>>x;
        if (x=='C')
        {
            cin>>y;
            if (s[y]=='(') s[y]=')';
            else s[y]='(';
        }
        else
        if (x=='U')
        {
            cin>>y;
            s=a[y];
        }
        else
        {
            string ss;
            cin>>y>>z;
            for (int j=y;j<=z;j++) ss+=s[j];
            cout<<tinh(ss)<<endl;
        }
    }
}
