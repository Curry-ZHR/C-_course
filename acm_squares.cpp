#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, m;
int cnt[10];
bool you[10][10];
bool xia[10][10];

bool che(int x, int y, int size)
{
	bool ok = true;
	for (int i = x; i <= x + size - 1; ++i)
	{
		if (xia[i][y] && xia[i][y + size]);
		else
		{
			ok = false;
			break;
		}
	}
	for (int j = y; j <= y + size - 1; ++j)
	{
		if (you[x][j] && you[x + size][j]);
		else
		{
			ok = false;
			break;
		}
	}
	return ok;
}

int main()
{
	int times = 1;
	while (cin >> n >> m)
	{
		memset(cnt, 0, sizeof cnt);
		memset(you, 0, sizeof you);
		memset(xia, 0, sizeof xia);
		for (int i = 1; i <= m; ++i)
		{
			string opt;
			int a, b;
			cin >> opt >> a >> b;
			if (opt[0] == 'H')
			{
				you[a][b] = true;
			}
			else
			{
				xia[b][a] = true;
			}
		}

		for (int size = 1; size <= n; ++size)
		{
			for (int x = 1; x + size <= n; ++x)
			{
				for (int y = 1; y + size <= n; ++y)
				{
					if (che(x, y, size))
					{
						cnt[size]++;
						// cout << x << " " << y << " " << size << endl;
					}
				}
			}
		}
		if (times != 1)
		{
			cout << "\n**********************************\n\n";
		}
		cout << "Problem #" << times << endl << endl;

		int ans = 0;
		for (int i = 1; i <= n; ++i)
			ans += cnt[i];
		if (ans)
		{
			for (int i = 1; i <= n; ++i)
			{
				if (cnt[i])
				{
					cout << cnt[i] << " square (s) of size " << i << endl;
				}
			}
		}
		else
		{
			cout << "No completed squares can be found." << endl;
		}

		times++;
	}

	return 0;
}