///Thu Thaoo

#include <bits/stdc++.h>

#define ll long long
#define I freopen(Task".inp", "r", stdin)
#define O freopen(Task".out", "w", stdout)
#define vt vector <int>
#define rt(O) return O
#define pii pair <int, int>
#define st first
#define nd second
#define rd third
#define th fourth
#define pusf push_front
#define popf pop_front
#define popb pop_back
#define pusb push_back
#define Task "mine"
#define MOD 1000003
#define uns unsigned
#define int ll
#define read_fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FORU(i, l, n) for (int i=l; i<=n; i++)
#define FORD(i, n, l) for (int i=n; i>=l; i--)
#define reset(x) memset (x, 0, sizeof(x))
#define ignLine cout<<endl

using namespace std;

const int N = 4e5 + 3;

int n, m, a[N];
int x[22];
int res = 0;
int F[N];

void sub1()
{
    reset(F);
    int kount = 0;
    FORU(i, 1, 2*n-1)
    {
        if (x[i] == 1) {
            kount++;
            F[i] = true;
        }
    }
    int kount2 = 0;
    if (kount == n)
    {
        FORU(i, 1, 2*n-1)
        {
            FORD(j, 2*n, i+1)
            {
                if (i != j)
                {
                    if (F[i] == true && F[j] == false && a[i] + m <= a[j])
                    {
                        F[j] = true;
                        break;
                    }
                }
            }
        }
        FORU(i, 1, 2*n)
        {
            if (F[i] == true) kount2++;
        }
        if (kount2 == 2*n) res++;
    }
}
void btr(int i)
{
    FORU(j, 0, 1)
    {
        x[i] = j;
        if (i == 2*n-1) sub1();
        else btr(i+1);
    }
}
main()
{
    read_fast
    I;
    O;
    cin>>n>>m;
    FORU(i, 1, 2*n)
    {
        cin>>a[i];
    }
    if (m == 1e6)
    {
        int res = 1;
        FORU(i, 1, n-1)
        {
            res *= 2;
            res = res % MOD;
        }
    }
    else {x[1] = 1; btr(2);}
    cout<<res;
    rt(0);
}
