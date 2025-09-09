#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MN = 26;

char map[MN][MN];
bool visit[MN][MN];
int cnt = 0;
int N;

void dfs(int ni, int nj)
{
    visit[ni][nj] = true;

    int dy[8] = {0, 0, 1, -1};
    int dx[8] = {1, -1, 0, 0};
    
    for (int i = 0; i < 4; i++)
    {
        int ny = ni + dy[i];
        int nx = nj + dx[i];
        if (map[ny][nx] == '1' && !visit[ny][nx] && nx < N && ny < N && nx >= 0 && ny >= 0)
        {
            cnt++;
            dfs(ny, nx);
        }
    }
}

int main()
{

    cin >> N;
    cnt = 0;
    vector<int> result;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == '1' && !visit[i][j])
            {
                cnt++;
                dfs(i, j);
                result.push_back(cnt);
                cnt = 0;
            }
        }
    }

    // memset(visit, false, sizeof(visit));
    // memset(map, 0, sizeof(map));
    sort(result.begin(), result.end());
    cout << result.size() << "\n";

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }
}