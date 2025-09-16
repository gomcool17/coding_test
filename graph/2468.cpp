#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
// #include <utility>

using namespace std;

const int MN = 101;

int map[MN][MN];
bool visit[MN][MN];
int n, m;
int maxx = 0, minn = MN;

void dfs(int ni, int nj, int h)
{
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};

    visit[ni][nj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = ni + dy[i];
        int nx = nj + dx[i];

        if (!visit[ny][nx] && map[ny][nx] > h && ny >= 0 && nx >= 0 && ny < n && nx < n)
        {
            dfs(ny, nx, h);
        }
    }
}

int main()
{
    cin >> n;
    int result = 0;
    // int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            maxx = max(maxx, map[i][j]);
        }
    }

    for (int k = 0; k <= maxx; k++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visit[i][j] && map[i][j] > k)
                {
                    dfs(i, j, k);
                    cnt++;
                }
            }
        }

        result = max(result, cnt);
        memset(visit, false, sizeof(visit));
    }

    cout << result;
}