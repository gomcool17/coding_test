#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MN = 51;

bool map[MN][MN];
bool visit[MN][MN];

int N, M, K;

int dy[8] = {0, 0, 1, -1};
int dx[8] = {1, -1, 0, 0};

void dfs(int ni, int nj)
{
    visit[ni][nj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = ni + dy[i];
        int nx = nj + dx[i];
        if (map[ny][nx] && !visit[ny][nx] && nx < M && ny < N && nx >= 0 && ny >= 0)
        {
            dfs(ny, nx);
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        cin >> M >> N >> K;
        int cnt = 0;
        vector<int> result;

        for (int i = 0; i < K; i++)
        {
            int y, x;
            cin >> x >> y;

            map[y][x] = true;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (map[i][j] && !visit[i][j])
                {
                    cnt++;
                    dfs(i, j);
                }
            }
        }

        memset(visit, false, sizeof(visit));
        memset(map, false, sizeof(map));
        cout << cnt << "\n";
    }
}