#include <bits/stdc++.h>
#define tfi "KMULT.INP"
#define tfo "KMULT.OUT"
#define tfa "KMULT.ANS"

using namespace std;

FILE    *themis_p_in,     // problem's input
        *themis_p_out,    // problem's output
        *themis_t_out,    // tested program's output
        *themis_t_src,    // tested program's source
        *themis_score,    // score for the program, for challenge problems
        *themis_u_info,   // additional info - psetter only
        *themis_p_info;   // additional info - psetter and solution's owner

void themis_init(const char*, const char*);
void local_init(const char*, const char*, const char*);
void read_in(const char*, ...);
void read_out(const char*, ...);
void read_ans(const char*, ...);
void message(const char*, ...);
void result(int);

#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
typedef long long LL;
typedef pair<int, int> II;

const int MAXN = 1+int(1e5);
const int INF = int(1e9);


int n, k, a[10005];
char x[10005];

int main(){
	themis_init(tfi, tfo);
    //local_init(tfi, tfo, tfa);
    read_in("%d%d",&n,&k);
    for(int i=1;i<=n;i++) read_in("%d",&a[i]);
    int kqa; read_ans("%d",&kqa);
    int kqo; read_out("%d\n",&kqo);
    if (kqa!=kqo) {
        message("Wrong answer!\n");
        result(0);
        return 0;
    }
    if (kqa) {
        for(int i=1;i<=n-1;i++) read_out("%c",&x[i]);
        int t=a[1];
        for(int i=2;i<=n;i++)
            if (x[i-1]=='+') t+=a[i]; else t-=a[i];
        if (t%k!=0) {
            message("Wrong answer!\n");
            result(0);
            return 0;
        }
    }
    message("Correct!\n");
    result(1); //1 - AC; 0 - WA
    return 0;
}

char TestPath[1000], CurrPath[1000];
char fINP[1000], fOUT[1000], fANS[1000];

void themis_init(const char* inName, const char* outName){
    gets(TestPath);
    gets(CurrPath);

    sprintf(fINP, "%s\\%s", TestPath, inName);
    sprintf(fANS, "%s\\%s", TestPath, outName);
    sprintf(fOUT, "%s\\%s", CurrPath, outName);

    themis_p_in     = fopen(fINP, "r");
    themis_p_out    = fopen(fANS, "r");
    themis_t_out    = fopen(fOUT, "r");
}

void local_init(const char* inName, const char* outName, const char* ansName){
    themis_p_in     = fopen(inName, "r");
    themis_p_out    = fopen(ansName, "r");
    themis_t_out    = fopen(outName, "r");
}

void read_in(const char * format, ...){
	va_list args;
	va_start (args, format);
	int res = vfscanf (themis_p_in, format, args);
	va_end (args);
	if(res == EOF){
        message("Input not enough!!!\n");
        result(0.0);
	}
}

void read_ans(const char * format, ...){
	va_list args;
	va_start (args, format);
	int res = vfscanf (themis_p_out, format, args);
	va_end (args);
	if(res == EOF){
        message("Answer not enough!!!\n");
        result(0.0);
	}
}

void read_out(const char * format, ...){
	va_list args;
	va_start (args, format);
	int res = vfscanf (themis_t_out, format, args);
	va_end (args);
	if(res == EOF){
        message("Output not enough!!!\n");
        result(0.0);
	}
}

void message(const char * format, ...){
	va_list args;
	va_start (args, format);
	vfprintf (stdout, format, args);
	va_end (args);
}

void result(int score){
	fprintf(stdout, "%ld\n", score);
	exit(0);
}
