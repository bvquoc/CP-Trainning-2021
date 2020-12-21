#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ins insert
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define unmap unordered_map
#define pq priority_queue
#define minEle min_element
#define maxEle max_element
#define lb lower_bound //first pos >= val
#define ub upper_bound // first pos > val
#define cnt_bit __builtin_popcount
//#pragma GCC optimize("Ofast")  
//#pragma GCC target("avx,avx2,fma")
using namespace std;

int d4x[4] = {1, 0, -1, 0}; int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1}; 

const long long oo = 1e18;
const long long maxN = 1e6;

/* Author : Le Ngoc Bao Anh, 10A5, LQD High School for Gifted Student */

pair<int, int> shop[maxN];
pair<int, int> last[maxN];
int nxt[maxN];
int m, n, tempo = maxN;

void solvesub2()
{   
    int curr, startX, maxX, cnt;
    for(int i = 1; i <= m; i++) {
        curr = shop[i].se;
        for(int j = 1; j <= m; j++) {
            if(shop[j].fi <= shop[i].se && shop[j].se > curr) {
                curr = shop[j].se;
                nxt[i] = j;
            }
        }
    }

    startX = -1; maxX = tempo;
    for(int i = 1; i <= m; i++) {
        if(shop[i].fi <= tempo && maxX < shop[i].se) {
            maxX = shop[i].se;
            startX = i;
        }
    }    

    if(startX == -1) {
        cout << startX;
        return;
    }

    cnt = 1;
    while(nxt[startX] != 0) startX = nxt[startX], cnt++;

    if(shop[startX].se < 100000) 
        cout << -1;
    else {
        cout << cnt;
    }
}

void solvesub3()
{
    int l,r,mid,pos,maxX,startX,cnt;
    sort(shop + 1, shop + 1 + m);
    last[1].fi = shop[1].se; last[1].se = 1;
    for(int i = 2; i <= m; i++) {
        if(last[i - 1].fi < shop[i].se) {
            last[i].fi = shop[i].se;
            last[i].se = i;
        } else last[i] = last[i - 1];
    }


    for(int i = 1; i <= m; i++) {
        l = 1; r = m; pos = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(shop[mid].fi <= shop[i].se) {
                pos = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

//         cout << i << " " << pos << " " << last[pos].se << endl;
        nxt[i] = last[pos].se;   
    }

//    cout << m << endl;
//    for(int i = 1; i <= m; i++) cout << nxt[i] << " ";
    startX = -1; maxX = tempo;
    for(int i = 1; i <= m; i++) {
        if(shop[i].fi <= tempo && maxX < shop[i].se) {
            maxX = shop[i].se;
            startX = i;
        }
//        cout << i << endl;
    }


    if(startX == -1) {
        cout << startX;
        return;
    }

    cnt = 1;
    while(nxt[startX] != startX) startX = nxt[startX], cnt++;

    if(shop[startX].se < 100000) 
        cout << -1;
    else {
        cout << cnt;
    }
}

void Solve()
{
    int x;
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> shop[i].fi >> shop[i].se;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        tempo = min(tempo, x);
    }    

    if(m <= 3000) solvesub2();
    else  solvesub3();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   freopen("COOLMAC.inp", "r", stdin);
   freopen("COOLMAC.out", "w", stdout);

    // long long TestCase;
    // cin >> TestCase;
    // while(TestCase--)
    Solve();
}
