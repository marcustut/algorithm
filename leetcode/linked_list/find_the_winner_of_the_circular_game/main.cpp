#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> queue;
        for (int i = 1; i <= n; i++)
            queue.push(i);

        while (queue.size() > 1)
        {
            int count = k;
            while (count > 1)
            {
                int current = queue.front();
                queue.pop();
                queue.push(current);
                count--;
            }
            queue.pop();
        }

        return queue.front();
    }
};

int main()
{
    Solution sol;

    cout << sol.findTheWinner(5, 2) << '\n';
}
