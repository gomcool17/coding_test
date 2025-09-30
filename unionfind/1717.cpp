#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MN = 1000001;

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

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0)
        {
            _union(b, c);
        }
        else
        {
            if (_find(b) == _find(c))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}