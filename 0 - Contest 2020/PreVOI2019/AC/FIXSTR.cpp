#define taskname "FIXSTR"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int maxN = 1e6 + 1;
const int maxSegmentTree = 1 << 21;
const int maxM = 1e6 + 1;

int n, m, nq;
string s;

inline int ReadInt()
{
    char c;
    while (c = getchar(), c < '0' || c > '9');
    int x = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')
        x = x * 10 + c - '0';
    return x;
}

inline void ReadStr(string& s)
{
    char c;
    while (c = getchar(), c != '(' && c != ')');
    s.clear();
    s.push_back(c);
    while (c = getchar(), c == '(' || c == ')')
        s.push_back(c);
}

inline char ReadCmd()
{
    char c;
    while (c = getchar(), c < 'A' || c > 'Z');
    return c;
}

void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

struct TQueryCmd
{
    int L, R, ans;
} QueryList[maxM];


using PNode = struct TNode*;
struct TNode
{
    int ChangePos;
    vector<PNode> Children;
    vector<TQueryCmd*> QuerySet;
};
PNode node[maxM];

struct TSegmentTree
{
    int leafbase;
    int Min[maxSegmentTree], Sum[maxSegmentTree];
    void Build(int n, const string s)
    {
        leafbase = 1;
        while (leafbase < n) leafbase *= 2;
        fill(Sum + leafbase, Sum + 2 * leafbase, 0);
        fill(Min + leafbase, Min + 2 * leafbase, 0);
        for (int i = 0; i < n; ++i)
            Min[leafbase + i] = Sum[leafbase + i] = s[i] == '(' ? +1 : -1;
        for (int i = leafbase - 1; i > 0; --i)
        {
            Min[i] = min(Min[i * 2], Sum[i * 2] + Min[i * 2 + 1]);
            Sum[i] = Sum[i * 2] + Sum[i * 2 + 1];
        }
    }
    void Change(int i)
    {
        int x = i + leafbase - 1;
        Min[x] = Sum[x] = -Sum[x];
        int Delta = Sum[x] * 2;
        for (x /= 2; x > 0; x /= 2)
        {
            Min[x] = min(Min[x * 2], Sum[x * 2] + Min[x * 2 + 1]);
            Sum[x] += Delta;
        }
    }
    int Query(int L, int R)
    {
        int aSum = 0, aMin = 0;
        vector<int> Wait;
        int i = L + leafbase - 1, j = R + leafbase - 1;
        for (; i <= j; i /= 2, j /= 2)
        {
            if (i % 2 != 0)
            {
                aMin = min(aMin, aSum + Min[i]);
                aSum += Sum[i];
                ++i;
            }
            if (j % 2 == 0)
            {
                Wait.push_back(j);
                --j;
            }
        }
        while (!Wait.empty())
        {
            j = Wait.back();
            Wait.pop_back();
            aMin = min(aMin, aSum + Min[j]);
            aSum += Sum[j];
        }
        return aSum - 2 * min(aMin, 0);
    }
} SegmentTree;

inline void Link(PNode parent, PNode child)
{
    parent->Children.push_back(child);
}

void BuildOperationTree()
{
    ReadStr(s);
    n = s.length();
    m = ReadInt();
    node[0] = new TNode;
    node[0]->ChangePos = 0;
    nq = 0;
    for (int i = 1; i <= m; ++i)
    {
        char cmd = ReadCmd();
        switch (cmd)
        {
        case 'C':
            node[i] = new TNode;
            node[i]->ChangePos = ReadInt();
            Link(node[i - 1], node[i]);
            break;
        case 'Q':
            node[i] = node[i - 1];
            QueryList[nq].L = ReadInt();
            QueryList[nq].R = ReadInt();
            node[i]->QuerySet.push_back(&QueryList[nq]);
            ++nq;
            break;
        case 'U':
            int u = ReadInt();
            node[i] = node[u - 1];
            break;
        }
    }
}

void DFS(PNode u)
{
    if (u->ChangePos != 0)
        SegmentTree.Change(u->ChangePos);
    for (TQueryCmd* ptr: u->QuerySet)
        ptr->ans = SegmentTree.Query(ptr->L, ptr->R);
    for (PNode v: u->Children)
        DFS(v);
    if (u->ChangePos != 0)
        SegmentTree.Change(u->ChangePos);
}

void Print()
{
    for (int i = 0; i < nq; ++i)
    {
        WriteInt(QueryList[i].ans);
        putchar('\n');
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    BuildOperationTree();
    SegmentTree.Build(n, s);
    DFS(node[0]);
    Print();
}

