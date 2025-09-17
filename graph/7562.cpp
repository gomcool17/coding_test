#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
// #include <utility>

using namespace std;

const int MN = 301;

bool visit[MN][MN];
int cnt[MN][MN];
int result = 0;
int n, m;
int y, x, y2, x2;

void bfs()
{
    int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    queue<pair<int, int>> q;
    q.push({y, x});

    visit[y][x] = true;
    while (!q.empty())
    {
        int ny = q.front().first;
        int nx = q.front().second;

        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nyy = ny + dy[i];
            int nxx = nx + dx[i];

            if (!visit[nyy][nxx] && nyy >= 0 && nxx >= 0 && nyy < n && nxx < n)
            {
                visit[nyy][nxx] = true;
                cnt[nyy][nxx] = cnt[ny][nx] + 1;
                q.push({nyy, nxx});
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cin >> y >> x >> y2 >> x2;

        memset(visit, false, sizeof(visit));
        memset(cnt, 0, sizeof(cnt));

        bfs();
        cout << cnt[y2][x2] << "\n";
    }
}