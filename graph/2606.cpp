#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
// #include <utility>

using namespace std;

const int MN = 1001;

vector<int> g[MN];
bool visit[MN];
int cnt = 0;

void dfs(int n)
{
    visit[n] = true;
    for (int next : g[n])
    {
        if (!visit[next])
        {
            cnt++;
            dfs(next);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    // int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    cout << cnt << "\n";
}