#include <bits/stdc++.h>

using namespace std;
struct it
{
    int minn,sum,lz;
};
it st[4000005];
int i,n,q,l,r,k,pos;
string s,R[20005];
char c;
void update(int u, int v, int l, int r, int id, int val)
{
    if (l > v || r < u) return;
    if (l >= u && r <= v)
    {
        st[id].lz+=val;
        return;
    }
    int mid = (l + r) >> 1;
    st[id*2].lz += st[id].lz;
    st[id*2 + 1].lz += st[id].lz;
    st[id].lz = 0;
    update(u,v,l,mid,id*2,val);
    update(u,v,mid+1,r,id*2+1,val);
    st[id].minn = min(st[id * 2].minn + st[id*2].lz , st[id * 2 + 1].minn + st[id * 2 + 1].lz);
    st[id].sum = st[id*2 + 1].sum + st[id * 2 + 1].lz;
}
it get(int u, int v, int l, int r, int id)
{
    if (l > v || r < u) return {(int) 1e9, 0,0};
    if (l >= u && r <= v) return st[id];
    int mid = (l + r) >> 1;
    st[id*2].lz += st[id].lz;
    st[id*2 + 1].lz += st[id].lz;
    st[id].lz = 0;
    it ans;
    it a = get(u,v,l,mid,id*2);
    it b = get(u,v,mid + 1, r, id * 2 + 1);
    st[id].sum = b.sum + b.lz;
    st[id].minn = min(a.minn + a.lz , b.minn + b.lz);
    ans.sum = b.sum + b.lz + a.sum + a.lz;
    ans.minn = min(a.minn + a.lz , b.minn + b.lz);
    ans.lz = 0;
    return ans;
}
void query()
{
    it x,y;
    scanf("%d%d",&l,&r);
    l--;
    r--;
    x = get(l,r,0,n,1);
    if (l > 0) y = get(0,l-1,0,n,1);
    else y = {0,0,0};
    x.sum+=x.lz;
    x.minn+=x.lz;
    x.sum -= y.sum + y.lz;
    x.minn -= y.sum + y.lz;
    int ans = 0;
    if (x.minn < 0)
    {
        ans += 0 - x.minn;
        x.sum += 0 - x.minn;
    }
    ans += abs(x.sum - 0);
    printf("%d\n",ans);
}
void flip()
{
    scanf("%d",&pos);
    pos --;
    if (s[pos] == '(') {
        update(pos,n,0,n,1,-2);
        s[pos] = ')';
    }
    else {
        update(pos,n,0,n,1,2);
        s[pos] = '(';
    }
}
void sub1()
{
    int cnt = 0,minn = 1e9;
    for (int i1 = 1; i1 <= q; i1++)
    {
        cin >> c;
        if (c == 'C')
        {
            scanf("%d",&pos);
            pos--;
            if (s[pos] == '(') s[pos] = ')';
            else s[pos] = '(';
            R[i] = s;
        } else if (c == 'Q'){
            scanf("%d%d",&l,&r);
            l--;
            r--;
            for (int i = l; i <= r; i++)
            {
                if (s[i] == '(') cnt++;
                else cnt--;
                minn = min(minn,cnt);
            }
            int ans = 0;
            if (minn < 0)
            {
                cnt += 0 - minn;
                ans += 0 - minn;
            }
            ans += abs(cnt);
            printf("%d\n",ans);
            R[i] = s;
        } else {
            scanf("%d",&k);
            for (int i = 0; i <= R[k-1].size(); i++)
            {
                s[i] = R[k-1][i];
            }
        }
    }
}
void sub2()
{
    for (int i1 = 1; i1 <= q; i1++)
    {
        cin >> c;
        if (c == 'C')
        {
            flip();
        } else if (c == 'Q'){
            query();
        }
    }
}
int init()
{
    for (int i = 0; i <= n; i++)
    {
        if (s[i] == '(') update(i,n,0,n,1,1);
        else update(i,n,0,n,1,-1);
    }
}
int main()
{
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    cin >> s;
    n = s.size() - 1;
    init();
    scanf("%d",&q);
    if (q <= 1005)
    {
        sub1();
    } else {
        sub2();
    }
    return 0;
}
