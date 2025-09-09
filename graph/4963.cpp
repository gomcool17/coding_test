#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MN = 51;

int map[MN][MN];
bool visit[MN][MN];
int cnt = 0;
int w, h;

void dfs(int ni, int nj)
{
    visit[ni][nj] = true;

    int dy[8] = {0, 0, 1, -1, -1, -1, 1, 1};
    int dx[8] = {1, -1, 0, 0, -1, 1, -1, 1}; // 동,서,남,북

    for (int i = 0; i < 8; i++)
    {
        int ny = ni + dy[i];
        int nx = nj + dx[i];

        if (map[ny][nx] && !visit[ny][nx] && nx < w && ny < h && nx >= 0 && ny >= 0)
        {
            dfs(ny, nx);
        }
    }
}

int main()
{
    while (1)
    {
        cin >> w >> h;
        cnt = 0;
        if (w == 0 && h == 0)
            break;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (map[i][j] && !visit[i][j])
                {
                    cnt++;
                    dfs(i, j);
                }
            }
        }

        memset(visit, false, sizeof(visit));
        memset(map, 0, sizeof(map));
        cout << cnt << "\n";
    }
}