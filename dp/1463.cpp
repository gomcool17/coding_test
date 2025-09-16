#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MN = 1000001;

long long dp[MN];
int n;

int main()
{
    cin >> n;

    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        if (i % 3 == 0 && i % 2 == 0)
            dp[i] = min(dp[i / 3] + 1, dp[i / 2] + 1);
        else if (i % 3 == 0)
            dp[i] = min(dp[i / 3] + 1,  dp[i-1] + 1);
        else if (i % 2 == 0)
            dp[i] = min(dp[i / 2] + 1, dp[i-1] + 1);
        else
            dp[i] = dp[i - 1] + 1;
    }

    cout << dp[n];
}