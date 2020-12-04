#include<bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define x first
#define y second
typedef pair<int,int> pii;
typedef pair<pii,pii> Rectangle;
int U[100011], V[100011], X[100011], Y[100011], n, m, k;

int readJuryInput(FILE *f){
    assert(fscanf(f,"%d%d%d", &n, &m, &k) == 3);
    for (int i=1;i<=k;++i){
        assert(fscanf(f,"%d%d%d%d", U+i, V+i, X+i, Y+i) == 4);
    }
    return 0;
}

long long ansj;
int readJuryOutput(FILE *f){
    assert(fscanf(f, "%lld", &ansj) == 1);
    return 0;
}

long long ansp;
string compare(FILE *f){// read student's output and compare
    int anshs;
    if (fscanf(f, "%lld", &ansp) != 1) return "SAI\nKhong doc duoc dong 1";
    if (ansp == -1 && ansj != -1) return "SAI\nCo dap an";
    if (ansp > ansj) return "SAI\nKet qua xau";
    vector<int> orders(k), mark(k+2);
    for (int i = 0; i < k; ++i){
        if (fscanf(f, "%d", &orders[i]) != 1){
            return ansp == ansj ? "DUNGMOTPHAN\n0.5\nKhong doc duoc dogn 2" : "SAI\nKet qua sai";
        }
        if (orders[i] > k || orders[i] < 1 || mark[orders[i]]++){
            return ansp == ansj ? "DUNGMOTPHAN\n0.5\nKhong phai hoan vi" : "SAI\nKet qua sai";
        }
    }

    map<int, set<int>> byTop, byLeft;
    map<pii, set<pii>> byTopLeft;
    #define let(dosmt,u,v,x,y) byTop[u].dosmt(v),byLeft[v].dosmt(u),byTopLeft[{u,v}].dosmt({x,y})
    auto which = [&](int i){//return the top left rectangles by line i-th
        int top, left;
        if (U[i] == X[i]){
            left = V[i];
            if (byLeft[left].empty() || *byLeft[left].begin() >= U[i])
                return Rectangle(pii(-1,-1), pii(-1, -1));
            top = *--byLeft[left].lower_bound(U[i]);
        } else {
            top = U[i];
            if (byTop[top].empty() || *byTop[top].begin() >= V[i])
                return Rectangle(pii(-1,-1), pii(-1, -1));
            left = *--byTop[top].lower_bound(V[i]);
        }
        pii A(top, left), B = *byTopLeft[A].begin();
        // cerr << i << ": " << top << " " << left << " " << B.x << " " << B.y << endl;
        return Rectangle(A, B);
    };
    let(insert,0,0,n,m);
    long long sum = 0;
    for (int i : orders){
        Rectangle tmp = which(i);
        if (tmp.x.x == -1)
            return ansp == ansj ? "DUNGMOTPHAN\n0.5\nThu tu khong hop ly" : "SAI\nKet qua sai";
        pii A = tmp.first, B = tmp.second;
        let(erase, A.x, A.y, B.x, B.y);
        if (A <  pii(X[i], Y[i]))
            let(insert, A.x, A.y, X[i], Y[i]);
        else
            return ansp == ansj ? "DUNGMOTPHAN\n0.5\nThu tu khong hop ly" : "SAI\nKet qua sai";
        if (pii(U[i], V[i]) < B)
            let(insert, U[i], V[i], B.x, B.y);
        else
            return ansp == ansj ? "DUNGMOTPHAN\n0.5\nThu tu khong hop ly" : "SAI\nKet qua sai";
        sum += 1LL*(B.x-A.x)*(B.y-A.y);
        // cerr << sum << endl;
    }
    if (ansp != sum){
        char s[100];
        sprintf(s, " Yours = %lld, trace = %lld, Jurys = %lld", ansp, sum, ansj);
        return (ansp == ansj ? "DUNGMOTPHAN\n0.5\nTruy vet sai" : "SAI\nKet qua sai") + string(s);
    }
    if (ansp < ansj) return "DUNG\nKet qua toi uu hon dap an";
    return "DUNG\n";
}

int main(int argc,char *argv[]){

    FILE *fin, *fout_ans, *fout_ts;

if (argc <= 3){//C6 of themis
    char s[300]; sprintf(s, "%s", argv[0]);
    int n=strlen(s), i=n-1;
    while(i&&s[i-1]!='_'&&s[i-1]!='\\') --i;
    while(s[n-1]!='.') s[--n]=0;
    char path[1000];
    freopen("compar$r.inp","r",stdin);
    cin.getline(path,1000);
    fclose(stdin);
    int m=strlen(path);
    if (path[m-1]!='\\') path[m++]='\\';

    sprintf(path+m,"%sINP",s+i);
    fin=fopen(path,"r");

    sprintf(path+m,"%sOUT",s+i);
    fout_ans=fopen(path,"r");

    fout_ts=fopen(path+m,"r");
} else {//CMS
    fin = fopen(argv[1], "r");
    fout_ans = fopen(argv[2], "r");
    fout_ts = fopen(argv[3], "r");
}

    readJuryInput(fin);
    readJuryOutput(fout_ans);

if (argc <= 3){
    freopen("compar$r.out","w",stdout);
    cout<<compare(fout_ts);
} else {
    string r = compare(fout_ts);
    if (r[0]=='D' && (r.size()<5||r[5]!='M')) cout<<1;
    else cout<<0;
    cerr << " " << r;
}

    fclose(fin);
    fclose(fout_ans);
    fclose(fout_ts);
    return 0;
}
