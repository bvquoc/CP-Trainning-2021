#ifdef THEMIS
    #include "testlib_themis.h"
#else
    #include "testlib.h"
#endif // THEMIS

using namespace std;

string ending(int x)
{
    x %= 100;
    if (x / 10 == 1)
        return "th";
    if (x % 10 == 1)
        return "st";
    if (x % 10 == 2)
        return "nd";
    if (x % 10 == 3)
        return "rd";
    return "th";
}

int main(int argc, char * argv[])
{
    setName("compare sequences of tokens");

#ifdef THEMIS
    registerTestlibThemis("chocolate.inp", "chocolate.out");
#else
    registerTestlibCmd(argc, argv);
#endif // THEMIS

    std::string strAnswer;

    int n = 0;
    string concat;

    while (!ans.seekEof()) 
    {
      n++;
      std::string j = ans.readWord();
      std::string p = ouf.readWord();
      strAnswer = p;
      if (j != p)
        quitf(_wa, "%d%s words differ - expected: '%s', found: '%s'", n, ending(n).c_str(), j.c_str(), p.c_str());

      concat += j + " ";
    }

    quitf(_ok, "'%s'", concat.c_str());
    return 0;
}
