#include <iostream>
#include <fstream>
using namespace std;

int n, m, lmin=INT_MAX, kq=0;
bool ok=false;
struct PhamVi
{
    int L;
    int R;
};
PhamVi a[100000];
int kiem(int Left, int Right)
{
    int mid=(Left+Right)/2;
    if (Left==Right && !(a[mid].L<=lmin && a[mid].R>=lmin)) return -1;
    if (a[mid].L<lmin && a[mid].R<lmin) return kiem(mid+1, Right);
    if (a[mid].L>lmin && a[mid].R>lmin) return kiem(Left, mid);
    return mid;
}
int Process()
{
    for (int i=1; i<=m-1; i++)
     for (int j=i+1; j<=m; j++)
    if (a[i].L>a[j].L) swap(a[i], a[j]);

    int t, chot=-1;
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> t;
        lmin=min(lmin, t);
    }
    if (lmin!=1e5)
    {
        int i=kiem(1, m);
        int Max=INT_MIN;
        int tam=i, chot=-1;
        while (a[tam].L<=lmin && a[tam].R>=lmin && tam<=m)
        {
            if (a[tam].R>Max)
            {
                Max=a[tam].R;
                chot=tam;
            }
            tam++;
        }
        tam=i-1;
        while (a[tam].L<=lmin && a[tam].R>=lmin && tam>=1)
        {
            if (a[tam].R>Max)
            {
                Max=a[tam].R;
                chot=tam;
            }
            tam--;
        }
        if (chot!=-1)
        {
            lmin=a[chot].R;
            kq++;
        }
    }
    while (lmin!=1e5)
    {
        int Max=INT_MIN, chott=-1;
        for (int i=chot+1; i<=m; i++)
        {
            if (a[i].L<=lmin && a[i].R>=lmin)
            if (a[i].R>Max)
            {
                Max=a[i].R;
                chott=i;
            }
        }
        if (chott!=-1)
        {
            chot=chott;
            lmin=a[chot].R;
            kq++;
        }
        else return -1;
    }
    return kq;
}
int main()
{
    freopen("coolmac.inp", "r", stdin);
    freopen("coolmac.out", "w", stdout);
    cin >> m;

    for (int i=1; i<=m; i++)
    {
        cin >> a[i].L >> a[i].R;
        if (a[i].R==1e5) ok=true;
    }
    if (ok) cout << Process();
    else cout << "-1";
    return 0;
}
