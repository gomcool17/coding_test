#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MN = 91;

long long dp[MN];
int n;

int main()
{
    cin >> n;

    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    cout << dp[n];
}