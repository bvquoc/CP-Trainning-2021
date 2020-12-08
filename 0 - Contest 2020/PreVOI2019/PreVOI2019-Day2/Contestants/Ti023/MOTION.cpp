#include <bits/stdc++.h>
using namespace std;

#define float long double
struct point
{
    float x, y;
};

const float EPSILON = 2e-3, MIN = 1e-3, INF = 1e9+9, EPSILON_SMOL = 1e-3;
int t;
int m, n;
point p1_s, p1_t, p2_s, p2_t;

float dist(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

bool is_int(float x)
{
    int tmp = floor(x), tmp1 = floor(x+1);
    if (abs(x-tmp) < EPSILON_SMOL || abs(x-tmp1) < EPSILON_SMOL) return 1;
    else return 0;
}

int main()
{
    freopen("MOTION.INP","r",stdin);
    freopen("MOTION.OUT","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        cin >> p1_s.x >> p1_s.y >> p1_t.x >> p1_t.y >> p2_s.x >> p2_s.y >> p2_t.x >> p2_t.y;
        point curr1 = p1_s, curr2 = p2_s;
        float dir1_x = p1_t.x - p1_s.x, dir1_y = p1_t.y - p1_s.y, dir2_x = p2_t.x - p2_s.x, dir2_y = p2_t.y - p2_s.y;
        //cout << dir1_x << ' ' << dir1_y << ' ' << dir2_x << ' ' << dir2_y << '\n';
        float min_dist = INF, ans_time;
        for (float i = 1; i <= 1000000; i++)
        {
            curr1.x += MIN * dir1_x;
            curr1.y += MIN * dir1_y;
            if (curr1.x >= m)
            {
                dir1_x = -dir1_x;
                curr1.x = m - (curr1.x-m);
            }
            if (curr1.y >= n)
            {
                dir1_y = -dir1_y;
                curr1.y = n - (curr1.y-n);
            }
            if (curr1.x < 0)
            {
                dir1_x = -dir1_x;
                curr1.x = -curr1.x;
            }
            if (curr1.y < 0)
            {
                dir1_y = -dir1_y;
                curr1.y = -curr1.y;
            }

            curr2.x += MIN * dir2_x;
            curr2.y += MIN * dir2_y;
            if (curr2.x >= m)
            {
                dir2_x = -dir2_x;
                curr2.x = m - (curr2.x-m);
            }
            if (curr2.y >= n)
            {
                dir2_y = -dir2_y;
                curr2.y = n - (curr2.y-n);
            }
            if (curr2.x < 0)
            {
                dir2_x = -dir2_x;
                curr2.x = -curr2.x;
            }
            if (curr2.y < 0)
            {
                dir2_y = -dir2_y;
                curr2.y = -curr2.y;
            }

            float ans = (float)i * MIN;
            //cout << curr1.x << ' ' << curr1.y << ' ' << curr2.x << ' ' << curr2.y << '\n';
            if (dist(curr1,curr2) < min_dist)
            {
                min_dist = dist(curr1,curr2);
                ans_time = ans;
                if (min_dist <= EPSILON) break;
            }
        }
        if (min_dist > EPSILON) cout << -1 << '\n';
        else
        {
            for (int i = 1; i <= 1e6; i++)
            {
                float x = (float)i*ans_time;
                if (is_int(x))
                {
                    int tmp = floor(x), tmp1 = floor(x+1);
                    if (abs(x-tmp) < abs(x-tmp1))
                    cout << tmp << ' ' << i << '\n';
                    else cout << tmp1 << ' ' << i << '\n';
                    break;
                }
            }
        }
    }
}
/*
1
4 4 1 0 4 4 3 0 0 4
/*
5
7 2 0 0 1 2 7 2 6 0
3 3 0 0 3 3 3 0 2 1
4 4 0 2 2 4 3 2 2 2
4 4 1 0 4 4 3 0 0 4
9 7 0 0 1 1 9 0 8 7
*/
