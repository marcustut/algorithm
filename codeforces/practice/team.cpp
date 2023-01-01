// https://codeforces.com/problemset/problem/231/A
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int ans(0);

	multiset<int> s;
	while (n--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		s.insert(a);
		s.insert(b);
		s.insert(c);
		if (s.count(1) >= 2) ans++;
		s.erase(1);
	}

	cout << ans << "\n";
}
