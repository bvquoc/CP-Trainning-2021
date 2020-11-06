#include<iostream>

using namespace std;

long long n, a[100001], k , t, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (long long j  = 0, l = 0; l <= n; l++ , j++)
	{
		t += a[l];
		t -= a[j];
		while (t < m)
		{
			l++;
			t += a[l];
			k++;
		}
	}
	cout << k;
}