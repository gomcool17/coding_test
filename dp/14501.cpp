#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MN = 17;

int dp[MN];
int t[MN];
int p[MN];
int n;

int main()
{
    cin >> n;
    int re = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> p[i];
    }


    for (int i = 0; i < n; i++)
    {
        int day = i + t[i];

        if(day <= n) {
            dp[day] = max(dp[day], dp[i] + p[i]);
            re = max(dp[day], re);
        }

        dp[i + 1] = max(dp[i], dp[i + 1]);
    }

    cout << re;
}