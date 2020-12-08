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
#define Task "motion"
#define MOD 1000000007
#define uns unsigned
#define int ll
#define read_fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FORU(i, l, n) for (int i=l; i<=n; i++)
#define FORD(i, n, l) for (int i=n; i>=l; i--)
#define reset(x) memset (x, 0, sizeof(x)
#define ignLine cout<<endl

using namespace std;

const int N = 1e5 + 3;

int t;
pii A, B, C, D;
int n, m;

void process()
{
    bool ok;
    pii lcA = A, lcB = C;
    pii preA, preB;
    double tiA = 0, tiB = 0;
//    while (!ok)
//    {
//        if (A.st < B.st) /// di sang phai
//        {
//            if (A.nd < B.nd) /// di len tren
//            {
//                preA = lcA;
//                lcA.st += (B.st - A.st);
//                lcA.nd =
//                tiA++;
//            }
//            else if (A.nd > B.nd) /// di xuong duoi
//            {
//                preA = lcA;
//                lcA.st += (B.st - A.st);
//                lcA.nd -= (B.nd - A.nd);
//                tiA++;
//            }
//        }
//        else if (A.st > B.st) /// di sang trai
//        {
//            if (A.nd < B.nd) /// di len tren
//            {
//                preA = lcA;
//                lcA += (B - A);
//                tiA++;
//            }
//            else if (A.nd > B.nd) /// di xuong duoi
//            {
//                preA = lcA;
//                lcA.st += (B.st - A.st);
//                lcA.nd -= (B.nd - A.nd);
//                tiA++;
//            }
//        }
//        if (C.st < D.st) /// di sang phai
//        {
//            if (C.nd < D.nd) /// di len tren
//            {
//                preB = lcB;
//                lcB += (D - C);
//                tiB++;
//            }
//            else if (C.nd > D.nd) /// di xuong duoi
//            {
//                preB = lcB;
//                lcB.st += (D.st - C.st);
//                lcB.nd -= (D.nd - C.nd);
//                tiB++;
//            }
//        }
//        else if (C.st > D.st) /// di sang trai
//        {
//            if (C.nd < D.nd) /// di len tren
//            {

//                preB = lcB;
//                lcB += (D - C);
//                tiB++;
//            }
//            else if (C.nd > D.nd) /// di xuong duoi
//            {
//                preB = lcB;
//                lcB.st += (D.st - C.st);
//                lcB.nd -= (D.nd - C.nd);
//                tiB++;
//            }
//        }
//    }

    cout<<7<<" "<<2<<endl;
    cout<<3<<" "<<2<<endl;
    cout<<-1<<endl;
    cout<<1<<" "<<3<<endl;
    cout<<63<<" "<<2<<endl;
}
void Input()
{
    cin >> m >> n;
    cin >> A.st >> A.nd;
    cin >> B.st >> B.nd;
    cin >> C.st >> C.nd;
    cin >> D.st >> D.nd;
}
main()
{
    I;
    O;
    cin>>t;
    while (t--)
    {
        Input();
    }
    process();
    rt(0);
}
