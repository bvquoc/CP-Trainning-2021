#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
const int maxN = 1e5 + 5;


long long n, m, k;
long long par[maxN], s[maxN];
string a;
ii b[maxN];
void sub1()
{
    int cnt = 0, res = 0, r = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == '0')
            cnt = 0;
        else{
            cnt++;
            if(cnt > res){
                r = i; res = cnt;
            }
        }
    }
    if(res == 0) cout <<-1;
    else cout << r - res + 1 << " " << r;
}

void sub2()
{
    deque<int> dq;
    int l = 0, res = 0, cnt1 = 0, cnt0 = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == '1')
        {
            cnt1++;
            dq.push_back(i);
            if(dq.size() > res){
                res= dq.size();
                l = dq.front();
            }
        }
        else{
            dq.push_back(i);
            cnt0++;
            while(cnt0 > k){
                if(a[dq.front()] == '1') cnt1--;
                else cnt0--;
                dq.pop_front();
            }
            if(dq.size() > res){
                res= dq.size();
                l = dq.front();
            }
        }
    }
    if(res == 0) cout<<"-1";
    else cout<<l<<" " << l + res - 1;
}

int root (int v)
{
    return par[v] < 0 ? v : (par[v] = root(v));
}

void merga(int x, int y)
{
    if((x = root(x)) == (y = root(y))) return;
    if(par[y] < par[x]){
        swap(x, y);
    }
    par[x] += par[y];
    par[y] = x;
}

void sub4()
{
    deque<int> dq;
    int l = 0, res = 0, cnt1 = 0, cnt0 = 0;
    for(int i = 1; i <= n; i++){
        dq.push_back(i);
        s[root(i)]--;
        if(s[root(i)] < 0){
            s[root(i)]++;
            k--;
            while(k <0){
                if(s[root(dq.front())] == 0){
                    k++;
                    dq.pop_front();
                }
                else{
                    s[root(dq.front())]++;
                    dq.pop_back();
                }
            }
            if(dq.size()> res){
                res = dq.size();
                l = dq.front();
            }
        }
    }
    if(res == 0) cout<<"-1";
    else cout<<l<<" " << l + res - 1;
}
int main()
{
    ios_base::sync_with_stdio(); cin.tie(); cout.tie();
    freopen("DECOR.inp", "r", stdin);
    freopen("DECOR.out", "w", stdout);

    cin >> n >> m >> k;
    cin >> a;
    a = ' ' + a;
    for(int i = 1; i <= n; i++)
        s[i] = a[i] -'0';
    memset(par, 255, sizeof(par));
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x>> y;
        int k = s[x];
        if(root(x) != root(y) && par[x] > par[y]){
            s[x] += s[y];
        }
        merga(x, y);
    }
    if(m == 0 && k == 0) sub1();
    else sub2();

}
