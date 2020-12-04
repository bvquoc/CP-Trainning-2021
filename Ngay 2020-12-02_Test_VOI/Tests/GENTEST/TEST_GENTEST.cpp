#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(a) (a).begin(),(a).end()
typedef long long ll;
mt19937 gen;
uniform_int_distribution<ll> dis;
ll random(ll L,ll H){if(H<L)return H;return(0LL+dis(gen)+rand())%(H-L+1)+L;}
int testID;
#define subtask subtaskOf(testID)
#define testmax (subtaskOf(testID+1)>subtask)
#define test_th(i) (subtaskOf(testID-i)==subtask && subtaskOf(testID-i-1)<subtask)
///////////////////////////////////////////////main///////////////////////////////////////////

const ll nmax[]={500, 1000000000, 500, 1000000000};
const ll nmin[]={ 50,   10000000, 400,   10000000};
const ll mmax[]={500, 500, 100000, 100000};
const ll mmin[]={100, 100,  50000,  50000};
vector<int> ntest = {2, 6, 6, 6};// % number of test of each subtask

int subtaskOf(int n){if(n<0)return-1;for(int i=0;i<ntest.size();++i)if((n-=ntest[i])<0)return i;return ntest.size();}

void test0_99(int num){
    int n = random(nmin[subtask], nmax[subtask]);
    int m = random(mmin[subtask], mmax[subtask]);
    if (testmax) n = nmax[subtask], m = mmax[subtask];
    m = min(1LL * m, 1LL * n * (n-1) / 2);
    cout << n << ' ' << m << '\n';
    long long E = 1LL * n * (n-1) / 2;
    for (int t = 1; t <= m; ++t){
        ll i = random(1, E);
        if (test_th(0)) i = E;
        if (test_th(1)) i = max(1LL, E-1);
        if (testmax) i = min(2LL, E);
        cout << i << ' ';
        --E;
    }
}

/////////////////////////////////////////////end////////////////////////////////////////////////
int main(int argc,char** argv){
    testID = 0;

    if (argc > 2){
        testID = atoi(argv[1]);
        freopen(argv[2],"w",stdout);
    } else {
        char* s = argv[0];
        int n=strlen(s), i=n-1;
        while(i&&s[i-1]!='_') --i;
        while(s[n-1]!='.') s[--n]=0;
        sprintf(s+n,"inp");freopen(s+i,"w",stdout);
        sprintf(s+n,"test");freopen(s+i,"r",stdin);
        cin>>testID;
    }
    if (subtask >= ntest.size()){
        return 125;
    }

    int k = testID;
    if (argc>3) k += atoi(argv[3]);
    while(k--) 0LL+dis(gen)+rand();
    test0_99(testID);
}
