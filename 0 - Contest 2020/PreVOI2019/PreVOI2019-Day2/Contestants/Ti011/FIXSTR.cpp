#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <set>

#define task "FIXSTR"
#define reset(a) memset(a, 0, sizeof(a))

using namespace std;

ifstream fi(task".inp");
ofstream fo(task".out");

typedef long long int lli;
typedef pair<int, int> II;

const int maxn = 1e6+1;
const int maxnsub1 = 1e3+1;
struct com
{
    char ch;
    int n1, n2;
};

int n, m;
string st;
int a[maxn];
int aa[maxnsub1][maxnsub1];
com b[maxn];
vector<II> bc;

//Checksub:
bool checksub1 = false, checksub2 = true;

set<int> open, close;
set<int>::iterator it, pos;

int main()
{
    fi >> st;
    n = st.size();
    for (int i = 0; i < n; i++)
        a[i+1] = (st[i] == '(') ? 1 : -1;
    fi >> m;
    checksub1 = (m <= 1000 && n <= 1000);
    for (int i = 1; i <= m; i++)
    {
        fi >> b[i].ch >> b[i].n1;
        if (b[i].ch == 'Q')
            fi >> b[i].n2;
        if (b[i].ch == 'C')
            bc.push_back(II(b[i].n1, i));
        if (checksub2 && b[i].ch == 'U')
            checksub2 = false;
    }
    //Sub 1:
    if (checksub1)
    {
        for (int i = 1; i <= n; i++)
            aa[i][0] = a[i];
        int index, res, sum;
        for (int i = 1; i <= m; i++)
        {
            if (b[i].ch == 'C')
            {
                index = b[i].n1;
                a[index] = (a[index] == 1) ? -1 : 1;
            }
            else
                if (b[i].ch == 'Q')
                {
                    res = 0;
                    sum = 0;
                    for (index = b[i].n1; index <= b[i].n2; index++)
                    {
                        if (a[index] == -1 && sum == 0)
                            res++;
                        else
                            sum += a[index];
                    }
                    if (sum > 0)
                        res += sum;
                    fo << res << "\n";
                }
                else
                {
                    sum = b[i].n1 - 1;
                    if (sum < 0) sum = 0;
                    for (index = 1; index <= n; index++)
                        a[index] = aa[index][sum];
                }
            for (index = 1; index <= n; index++)
                aa[index][i] = a[index];
        }
    }
    else
        //Sub 2:
        if (checksub2)
        {
            for (int i = 1; i <= n; i++)
                if (a[i] == 1)
                    open.insert(i);
                else
                    close.insert(i);
            int cnt, res, index;
            for (int i = 1; i <= m; i++)
            {
                if (b[i].ch == 'C')
                {
                    index = b[i].n1;
                    if (a[index] == 1)
                    {
                        open.erase(index);
                        close.insert(index);
                    }
                    else
                    {
                        close.erase(index);
                        open.insert(index);
                    }
                    a[index] = (a[index] == 1) ? -1 : 1;
                }
                else
                {
                    cnt = 0;
                    res = b[i].n2 - b[i].n1 + 1;
                    int maxindex = 0;
                    for (it = open.lower_bound(b[i].n1); (*it) <= b[i].n2 && it != open.end(); it++)
                    {
                        maxindex = max(maxindex, (*it) + 1);
                        if (maxindex > b[i].n2)
                            break;
                        pos = close.lower_bound(maxindex);
                        if ((*pos) <= b[i].n2)
                        {
                            maxindex = (*pos) + 1;
                            cnt++;
                        }
                        else
                            break;
                    }
                    res -= cnt*2;
                    fo << res << "\n";
                }
            }
        }
}
