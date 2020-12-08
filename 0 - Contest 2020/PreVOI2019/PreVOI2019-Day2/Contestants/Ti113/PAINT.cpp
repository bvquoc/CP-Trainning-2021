#include <bits/stdc++.h>

using namespace std;
const string filename = "PAINT";

vector<int> pos[27];
int id[27];
int n;
char res[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen( (filename + ".inp").c_str(), "r", stdin);
	freopen( (filename + ".out").c_str(), "w", stdout);

	cin >> n;
	int top = 0;
	for (int i=1;i<=26;i++)
		id[i] = i;
	for (int i=1;i<=n;i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			char c; cin >> c;
			int cur = c - 'a' + 1;
			top++;
			pos[id[cur]].push_back(top);	
		}
		else
		{
			char a,b; cin >> a >> b;
			int x = a - 'a' + 1, y = b - 'a' + 1;
			if (pos[id[x]].size() > pos[id[y]].size())
			{
				while(!pos[id[y]].empty())
				{
					pos[id[x]].push_back(pos[id[y]].back());
					pos[id[y]].pop_back();
				}				
				swap(id[x],id[y]);
			}
			else
			{
				while(!pos[id[x]].empty())
				{
					pos[id[y]].push_back(pos[id[x]].back());
					pos[id[x]].pop_back();
				}
			}
		}
	}
	for (int i=1;i<=26;i++)
		for (int j=0;j<pos[id[i]].size();j++)
			res[pos[id[i]][j]] = (i + 'a' - 1);
	for (int i=1;i<=top;i++)
		cout << res[i]; 				
}