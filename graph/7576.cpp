#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
// #include <utility>

using namespace std;

const int MN = 1001;

bool visit[MN][MN];

int cnt[MN][MN];
int original[MN][MN];
int datas[MN][MN];

vector<pair<int, int>> v;

int n, m;
void bfs()
{
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};
    queue<pair<int, int>> q;

    for (pair<int, int> now : v)
    {
        q.push({now.first, now.second});
    }

    while (!q.empty())
    {
        int ny = q.front().first;
        int nx = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int y = ny + dy[i];
            int x = nx + dx[i];

            if (!visit[y][x] && original[y][x] == 0 && y >= 0 && x >= 0 && y < n && x < m)
            {
                visit[y][x] = true;
                datas[y][x] = 1;
                cnt[y][x] = min(cnt[y][x], cnt[ny][nx] + 1);
                q.push({y, x});
            }
        }
    }
}

int main()
{

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;

            original[i][j] = a;
            cnt[i][j] = MN * MN;
            if (a == 1)
            {
                cnt[i][j] = 0;
                v.push_back({i, j});
            }
        }
    }

    bfs();

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (cnt[i][j] == MN * MN && original[i][j] != -1)
            {
                result = -1;
                break;
            }
            else if (original[i][j] == -1)
                continue;
            else
                result = max(result, cnt[i][j]);
        }

        if (result == -1)
            break;
    }

    cout << result << "\n";
}