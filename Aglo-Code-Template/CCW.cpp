// https://www.spoj.com/PTIT/problems/P141SUMA/
#include <bits/stdc++.h>
using namespace std;
struct Point {int64_t x,y;};
Point A, B, C;

int CCW(Point a, Point b, Point c) {
    int64_t k = int64_t(b.x-a.x)*int64_t(c.y-b.y)-int64_t(b.y-a.y)*int64_t(c.x-b.x);
    if (k>0) return 1;
    if (k<0) return -1;
    return 0;
}

int32_t main(void) {
    freopen("input.txt","r",stdin);
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    int D = CCW(A,B,C);
    if (D<0) cout << "RIGHT";
    else if (D>0) cout << "LEFT";
    else cout << "TOWARDS";
    return 0;
}