#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
// #include <utility>

using namespace std;

const int MN = 1001;

vector<int> g[MN];
bool visit[MN];

void dfs(int n)
{
    visit[n] = true;

    for (int next : g[n])
    {
        if (!visit[next])
        {
            dfs(next);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visit[i])
        {
            cnt++;
            dfs(i);
        }
    }

    cout << cnt << "\n";
}