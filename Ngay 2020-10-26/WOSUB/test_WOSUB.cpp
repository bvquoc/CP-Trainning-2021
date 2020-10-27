#include <bits/stdc++.h>
using namespace std;
const string NAME = "WOSUB";
const int NTEST = 100;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        // Code phần sinh test ở đây
        int n = Rand(5, 100), psum[n+1]; psum[0] = 0;
        inp << n << endl;
        int a[n+1];
        for (int i=1; i<=n; i++) {
            a[i] = abs(Rand(1,800));
            inp << a[i] << ' ';
            psum[i] = psum[i-1] + a[i];
        } inp << endl;
        int S, cnt = 0; map <int,int> mp;
        for (int l=1; l<=n; l++) for (int r=l; r<=n; r++) {
            int s = psum[r]-psum[l-1];
            mp[s]++;
        }
        for (pair <int,int> x: mp) if (x.second > cnt) {
            cnt = x.second;
            S = x.first;
        }
        inp << S;
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff

        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}