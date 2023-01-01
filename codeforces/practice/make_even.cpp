#include <bits/stdc++.h>
using namespace std;

bool is_even(string s)
{
	return stoi(s) % 2 == 0;
}

bool is_even_char(char c)
{
	return (c - '0') % 2 == 0;
}

int main()
{
	int t;

	cin >> t;

	while(t--)
	{
		string n;
		cin >> n;

		if (stoi(n) % 2 == 0)
		{
			cout << "0\n";
			continue;
		}

		int posEven = -1;
		for (int i = 0; i < n.length(); i++)
			if (is_even_char(n[i]))
			{
				posEven = i;
				break;
			}

		if (posEven == -1)
		{
			cout << "-1\n";
			continue;
		}

		int steps = 0, l = posEven + 1;
		string temp = n; // "387"
		for (int i = 0; i <= 2; i++)
		{
			steps = 0;
			temp = n;

			while(l <= n.length()) // x = 2
			{
				if (is_even_char(temp[0]) && !is_even_char(temp[temp.length() - 1]))
				{
					reverse(temp.begin(), temp.end());
					steps++;
					l++;
					cout << steps << "\n";
					break;
				}
				reverse(temp.begin(), temp.begin() + l);
				steps++;
				l++; 
			}	
			if (is_even(temp)) break;
		}

		if (is_even(temp)) continue;
	}
}
