#include<bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;
pii p[10];
int m, n;
pii vec(pii a, pii b)
{
    return {b.f - a.f, b.s - a.s};
}
bool cat(pii a, pii b)
{
    if(a.f < b.f)swap(a,b);
    if(a.s < b.s)return 0;
    if(b.s == 0 && a.s != 0)return 0;
    if(a.s == 0 && b.s != 0)return 0;
    if(b.s == 0 && a.s == 0)return 1;
    int k_f = a.f / b.f;
    int k_s = a.s / b.s;
    if(k_f != k_s)return 0;
    if(k_f * b.f == a.f && k_s * b.s == a.s)return 1;
    return 0;
}
void nhap()
{
    cin >> m >> n;
    for(int i = 1; i <= 4; i++)cin >> p[i].f >> p[i].s;
    pii vec_ab, vec_cd;
    vec_ab = vec(p[1],p[2]);
    vec_cd = vec(p[3],p[4]);
cout << -1 << '\n';
}
int T;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("MOTION.inp","r",stdin);
    freopen("MOTION.out","w",stdout);
    cin >> T;
    while(T--)
    {
        nhap();
    }
}
