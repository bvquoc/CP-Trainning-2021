//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "minsum"
#define maxn 100000
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)

typedef char NameFile[1000];

using namespace std;

NameFile input, output, answer;
ifstream fi, fo, fa;

int n, k;

int read()
{
    fi >> n >> k;
}

int readInput()
{
  fi.open(input);
}

int readOutput()
{
  fo.open(output);
}

int readAnswer()
{
  fa.open(answer);
}

bool check()
{
    long long a1, b1, c1, d1, a2, b2, c2, d2;
    for (int i = 1; i <= n; i++){
        fo >> a1 >> b1 >> c1 >> d1;
        fa >> a2 >> b2 >> c2 >> d2;
        if (a1 != a2) swap(a1, c1), swap(b1,d1);
        if (a1 != a2 || b1 != b2 || c1 != c2 || d1 != d2){
            cout << "Dong " << i << " sai! \n";;
            return 0;
        }
    }
// others here


  cout << " Ket qua dung!!! \n";
  return 1;
}

main()
{
  gets(input);
  gets(output);

  strcpy(answer, input);
  strcat(input,  Task".inp");
  strcat(output, Task".out");
  strcat(answer, Task".out");

  readInput();
  readOutput();
  readAnswer();
  read();
  cout << ((check()) ? "1.00" : "0.00");
  fi.close();
  fo.close();
  fa.close();
//  system("pause");
}
