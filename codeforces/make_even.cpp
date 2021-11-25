// not complete (doesn't pass all test cases)
// unable to find the least number (not optimal solution)
#include <bits/stdc++.h>
using namespace std;

int count_digit(int number) {
	return int(log10(number) + 1);
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
			if ((n[i] - '0') % 2 == 0)
			{
				posEven = i;
				break;
			}

		if (posEven == -1)
		{
			cout << "-1\n";
			continue;
		}

		int steps = 0;
		string temp = n; // "387"
		for (int l = 2; l <= n.length(); l++)
		{
			steps = 0;
			int x = l;
			temp = n;

			while(x <= n.length()) // x = 2
			{
				reverse(temp.begin(), temp.begin() + x);
				steps++;
				if (stoi(temp) % 2 == 0) 
				{
					cout << steps << "\n";
					break;
				}
				x++; 
			}	
			if (stoi(temp) % 2 == 0) break;
		}

		if (stoi(temp) % 2 == 0) continue;
	}
}
