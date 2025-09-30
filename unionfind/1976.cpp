#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MN = 201;

int dp[MN];
int t[MN];
int p[MN];
int n, m;

int _find(int a)
{
    if (p[a] == a)
        return a;
    else
        return p[a] = _find(p[a]);
}

void _union(int a, int b)
{
    a = _find(a);
    b = _find(b);

    p[a] = b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        p[i] = i;

    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= n;j++) {
            int a;
            cin >> a;
            if(a == 1)
                _union(i, j);
        }
    }
    vector<int> plan;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        plan.push_back(a);
    }
    string result = "YES";
    for (int i = 0; i < m - 1;i++) {
        if (_find(plan[i]) != _find(plan[i + 1]))
        {
            result = "NO";
            break;
        }
    }

    cout << result;
}