#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

#define MN 101

char map[MN][MN];
int check[MN][MN];
int len[MN][MN];
int N, M;

void sol(int ni, int nj)
{
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};
    queue<pair<int, int>> q;
    q.push({ni, nj});
   // check[ni][nj] = true;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        check[y][x] = true;
        for (int i = 0; i < 4; i++)
        {
            int yy = y + dy[i];
            int xx = x + dx[i];
            
            if (!check[yy][xx] && map[yy][xx] == '1' && yy < M && xx < N && yy >= 0 && xx >= 0)
            {
                q.push({yy, xx});
                len[yy][xx] = len[y][x] + 1;
            }
        }
    }
}
int main()
{
    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    len[0][0] = 1;
    sol(0, 0);

    cout << len[M - 1][N - 1] << "\n";
}