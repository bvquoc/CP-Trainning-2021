#include <bits/stdc++.h>
using namespace std;

const string NAME = "FM";

long long Rand(long long l, long long r) {
    return l + (long long)rand() * (long long)rand() % (r - l + 1);
}

int main() {
    srand(time(NULL));

    system(("g++ " + NAME + ".cpp -o " + NAME).c_str());
    system(("g++ " + NAME + "_trau.cpp -o " + NAME + "_trau").c_str());

    for (int iTest = 1; iTest <= 1000; iTest++) {
        ofstream inp((NAME + ".INP").c_str());
        int n = Rand(1, 10), m = Rand(1, 15);
        inp << n << ' ' << m << '\n';
        for (int i = 1; i <= n; i++) {
            int x = Rand(1, 5);
            inp << x << ' ';
        }
        inp.close();

        system(("./" + NAME + " && ./" + NAME + "_trau").c_str());
        if (system(("diff ./" + NAME + ".ANS " + "./" + NAME + ".OUT").c_str()) != 0) {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        else
            cout << "TEST " << iTest << ": CORRECT!\n";
    }

    return 0;
}