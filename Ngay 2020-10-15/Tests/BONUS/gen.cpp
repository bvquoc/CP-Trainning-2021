#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

double randf() {
    double base = 0.1;
    double res = 0;
    for (int i = 0; i < 20; i++) {
        res += base * (rand() % 10);
        base /= 10;
    }
    return res;
}

int randi(int V) {
    return (int)floor(V * randf());
}

void gen(string name, int m, int n, int maxV = 10000) {
    system(("mkdir " + name).c_str());
    ofstream f((name + "/bonus.inp").c_str());

    if (m * n > 1000000) {
        cout << name << " error" << endl;
    }

    f << m << " " << n << " " << m * n << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            f << (j == 0 ? "" : " ") << randi(maxV) + 1;
        }
        f << endl;
    }
    for (int i = 0; i < m * n; i++) {
        int u1 = randi(m) + 1;
        int u2 = randi(m) + 1;
        if (u1 > u2) swap(u1, u2);

        int v1 = randi(n) + 1;
        int v2 = randi(n) + 1;
        if (v1 > v2) swap(v1, v2);

        f << u1 << " " << v1 << " " << u2 << " " << v2 << endl;
    }
    f << endl;
    f.close();

    cout << name << ": done" << endl;

    system(("time ./bonus <" + name + "/bonus.inp >" + name + "/bonus.out").c_str());

}

int main() {
    ios_base::sync_with_stdio(false);

    gen("test01", 3, 15, 10);
    gen("test02", 50, 35, 100);
    gen("test03", 50, 50, 100);

    gen("test04", 1, 5678, 1000);
    gen("test05", 1, 100000);
    gen("test06", 1, 1000000);

    gen("test07", 300, 200);
    gen("test08", 400, 400, 1000);
    gen("test09", 1000, 1000, 1000);

    gen("test10", 1000, 1000, 1000);


}
