#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
// #include <utility>

using namespace std;

const int MN = 10001;

vector<int> g[MN];
bool visit[MN];
int result = 0;
int n, m;

void dfs(int num)
{

    for (int next : g[num])
    {
        if (!visit[next])
            result++;

        visit[next] = true;
    }
}

int main()
{
    cin >> n >> m;
    // int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    visit[1] = true;
    for (int next : g[1])
    {
        if (!visit[next]){
            visit[next] = true;
            result++;
        }

        dfs(next);
    }

    cout << result << "\n";
}