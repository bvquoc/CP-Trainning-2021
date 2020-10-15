#include <bits/stdc++.h>
#include <windows.h>
#include <direct.h>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define N 100003
#define maxc 1000000003


using namespace std;


char Name_file[] = "";
char exe_file[100] = "";
char inp_file[100] = "";
char out_file[100] = "";
string folder = "Test00";
int n;
struct X
{
  long long x, a;
};
X d[N], D[N];
bool lf(const X x, const X y)
{
    return x.x < y.x;
}
int rand(int x)
{
    long long u = rand() % maxc;
    long long v = rand() % maxc;
    long long k = rand() % maxc;
    return ((u * v + k) % x + 1);
}


long long rand(long long x)
{
    int u = rand(1000000);
    int v = rand(1000000);
    //int k = rand(1000000000);
    return ((1ll*u*v))+1;
}

void make_test(int test)
{
    long long MaxC = test * test * test * test * 10;
    int Max = 1000;
    int n;

    if (test <= 5){
            n = rand(20);
            Max = 10;
    }
    else if (test <= 10)
    {
        n = rand(1000);
        Max = 100000;
    }
    else {
            n = rand(100000);
            Max = 1000000;
    }
    if (test == 20) {n = 100000;}
    if (test <= 10)
    {

        for(int i=1; i<=n; i++)
        {
            d[i].x = rand(Max);
            d[i].a = rand(Max);
        }
    }
    else
    {
         for(int i=1; i<=n; i++)
        {
            d[i].x = rand(MaxC);
            d[i].a = rand(MaxC);
        }
    }
    sort(d + 1, d + n + 1, lf);
    int m = 1;
    D[0] = d[1];
    for(int i=1; i<=n; i++)
    {
        if (d[i].x != D[m-1].x)
        {
            D[m++] = d[i];
        }
    }
    cout << m << endl;
    for(int i=0; i< m; i++) cout << D[i].x <<' '<<D[i].a << endl;
}

void run_answer()
{
    system(exe_file);
}

void Rename_file(int test)
{
    folder[4] = test/10 + 48;
    folder[5] = test%10 + 48;
    mkdir(&folder[0]);
    string output_path = folder + "\\" + inp_file;
    CopyFile(inp_file, &output_path[0], false);
    output_path = folder + "\\" + out_file;
    CopyFile(out_file, &output_path[0], false);
}

void Make_file_name()
{
    strcpy(exe_file,Name_file);
    strcpy(inp_file,Name_file);
    strcpy(out_file,Name_file);

    strcat(exe_file,"SOL.exe");
    strcat(inp_file,"RICE.INP");
    strcat(out_file,"RICE.OUT");

}

int main()
{

    Make_file_name();
    FOR(test,1,20)
    {
       // cout << test << endl;
        freopen(inp_file, "w", stdout);
        make_test(test);
        run_answer();
        Rename_file(test);
    }
    DeleteFile(inp_file);
    DeleteFile(out_file);
    return 0;
}
