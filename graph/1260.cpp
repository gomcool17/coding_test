#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
// #include <utility>

using namespace std;

const int MN = 10001;

vector<int> g[MN];
bool visit_dfs[MN];
bool visit_bfs[MN];
int result = 25000000;
int countt = 0;
int n, m, v;

void dfs(int num)
{
    visit_dfs[num] = true;
    cout << num << " ";
    for (int next : g[num])
    {
        if (!visit_dfs[next])
        {
            dfs(next);
        }
    }
}

void bfs(int num)
{
    queue<int> q;
    q.push(num);
    visit_bfs[num] = true;
    cout << num << " ";
    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < g[now].size(); i++)
        {
            int next = g[now][i];

            if (!visit_bfs[next])
            {
                cout << next << " ";
                visit_bfs[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    int min_p = MN;
    cin >> n >> m >> v;
    // int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < m; i++)
    {
        sort(g[i].begin(), g[i].end());
    }

    dfs(v);
    cout << "\n";
    bfs(v);
    cout << "\n";
}