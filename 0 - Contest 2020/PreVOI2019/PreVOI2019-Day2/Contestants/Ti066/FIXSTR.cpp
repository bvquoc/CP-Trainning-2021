#include <bits/stdc++.h>
#define task "FIXSTR"
#define inpt freopen(task".inp","r",stdin);
#define outpt freopen(task".out","w",stdout);
#define for(a,b,c) for (int a=b;a<=c;a++)
#define maxn 1005
#define f first
#define s second

using namespace std;

string S,ST[maxn];
pair <int,int> a[maxn],tree[maxn*4];

int n,m;
void nhap()
{
	ios_base::sync_with_stdio(0);cin.tie();cout.tie();
	inpt;
	outpt;
	cin>>S;
	cin>>m;
	n=S.size();
	S=" "+S;
}
void xuly()
{
    char res;
    cin>>res;
    if (res=='C')
    {
        int pos;
        cin>>pos;
        if (S[pos]==')') S[pos]='(';
            else S[pos]=')';
        //cout<<S<<endl;
    }
    if (res=='U')
    {
        int pos;
        cin>>pos;
        S=ST[pos-1];
    }
    if (res=='Q')
    {
        int l,r,dem=0,kq=0;
        cin>>l>>r;
        for(i,l,r)
        {
            if (dem==0 && S[i]==')') kq++;
            if (dem!=0 && S[i]==')') dem--;
            if (S[i]=='(') dem++;
        }
        cout<<kq+dem<<endl;
    }
}
void build(int k,int l,int r)
{
    if (l>r) return;
    if (l==r) {tree[k].f=a[l].f,tree[k].s=a[l].s;return;}
    int g=(l+r)/2;
    build(k*2,l,g);
    build(k*2+1,g+1,r);
    tree[k].f=max(0,tree[2*k].f-tree[2*k+1].s);
    tree[k].s=tree[2*k].s+max(0,tree[2*k+1].s-tree[2*k].f);
}
void update(int k,int l,int r,int pos)
{
    if (l>r) return;
    if (pos<l||pos>r) return;
    if (l==r&&l==pos) {tree[k].f=(a[l].f+1)%2,tree[k].s=(1+a[l].s)%2;return;}
    int g=(l+r)/2;
    build(k*2,l,g);
    build(k*2+1,g+1,r);
    tree[k].f=max(0,tree[2*k].f-tree[2*k+1].s);
    tree[k].s=tree[2*k].s+max(0,tree[2*k+1].s-tree[2*k].f);
}
pair <int,int> get( int id , int l , int r , int L , int R  )
{
    if( r < L || l > R ) return make_pair(0 , 0);
    if( L <= l && r <= R ) return make_pair(tree[id].f,tree[id].s);
    int mid=(l+r)/2;
    return make_pair(max(get( 2 * id , l , mid , L , R ).f-get( 2 * id + 1 , mid + 1 , r , L , R ).s,0)+get( 2 * id + 1 , mid + 1 , r , L , R ).f,
                    get( 2 * id , l , mid , L , R ).s+max(0,get( 2 * id + 1, l , mid , L , R ).s-get( 2 * id , mid + 1 , r , L , R ).f));
}

void xuly2()
{
    char res;
    cin>>res;
    if (res=='C')
    {
        int pos;
        cin>>pos;
        if (S[pos]==')') S[pos]='(';
            else S[pos]=')';
        update(1,1,n,pos);
        //cout<<S<<endl;
    }
    if (res=='U')
    {
        int pos;
        cin>>pos;
        S=ST[pos-1];
        for (i,1,n)
        {
            if (S[i]==')') a[i].s=1;
            else a[i].f=1;
        }
        build(1,1,n);
    }
    if (res=='Q')
    {
        int l,r,dem=0,kq=0;
        cin>>l>>r;
        cout<<abs(get(1,1,n,l,r).f+get(1,1,n,l,r).s)<<endl;
    }
}
int main()
{
    nhap();
    if (n<=1000)
        for(i,1,m)
        {
            xuly();
            ST[i]=S;
        }
    else
        {
            for (i,1,n)
            {
                if (S[i]==')') a[i].s=1;
                else a[i].f=1;
            }
            build(1,1,n);
            for(i,1,m)
            {
                ST[i]=S;
                xuly2();
                //cout<<S<<endl;
            }
        }
    return 0;
}
