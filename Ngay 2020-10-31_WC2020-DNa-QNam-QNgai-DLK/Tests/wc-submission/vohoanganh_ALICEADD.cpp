#include <bits/stdc++.h>

using namespace std;

__int128_t atoint128_t(std::string const & in)
{
    __int128_t res = 0;
    size_t i = 0;
    bool sign = false;

    if (in[i] == '-')
    {
        ++i;
        sign = true;
    }

    if (in[i] == '+')
    {
        ++i;
    }

    for (; i < in.size(); ++i)
    {
        const char c = in[i];
        res *= 10;
        res += c - '0';
    }

    if (sign)
    {
        res *= -1;
    }

    return res;
}

std::ostream& operator<<(std::ostream& os, __int128 x){
    if(x<0) return os << "-" << -x;
    if(x<10) return  os << (char)(x+'0');
    return os << x/10 << (char)(x%10+'0');
}

int main()
{
    int q;
    cin >> q;

    while (q-->0)
    {
        string x, y;
        cin >> x >> y;

        __int128_t a = atoint128_t(x);
        __int128_t b = atoint128_t(y);
        
        cout << a + b << '\n';
    }
    
    return 0;
}