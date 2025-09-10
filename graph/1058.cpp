#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
// #include <utility>

using namespace std;

const int MN = 51;

vector<int> g[MN];
bool visit[MN];
int result = 0;
int cnt = 0;
int n, m;

void dfs(int num)
{

    for (int next : g[num])
    {
        if (!visit[next])
            cnt++;

        visit[next] = true;
    }
}

int main()
{
    cin >> n;
    // int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < n;j++) {
            if(s[j] == 'Y') {
                g[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n;i++){
        visit[i] = true;

        for (int next : g[i])
        {
            if (!visit[next])
            {
                cnt++;
                visit[next] = true;
            }

            dfs(next);
            result = max(result, cnt);
        }
        memset(visit, false, sizeof(visit));
        cnt = 0;
    }

    cout << result << "\n";
}