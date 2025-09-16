#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
// #include <utility>

using namespace std;

const int MN = 5001;

vector<int> g[MN];
bool visit[MN];
int result = 25000000;
int n, m;
int min_p = MN;

void bfs(int num)
{
    int count = 0;
    queue<pair<int, int>> q;
    visit[num] = true;
    q.push({num, 0});

    while (!q.empty())
    {
        int now = q.front().first;
        int now_cnt = q.front().second;
        count += now_cnt;
        q.pop();

        for (int next : g[now])
        {
            if (!visit[next])
            {
                q.push({next, now_cnt + 1});
                visit[next] = true;
            }
        }
    }

    if(result > count) {
        result = count;
        min_p = num;
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

    for (int i = 1; i <= n; i++)
    {

        bfs(i);

        memset(visit, false, sizeof(visit));
    }

    cout << min_p << "\n";
}