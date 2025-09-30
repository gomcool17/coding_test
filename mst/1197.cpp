#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
// #include <utility>
//
using namespace std;

struct edge
{
    int u, v, w;
};

const int MN = 100001;

int p[10001];
edge tree[MN];

bool compare(const edge &a, const edge &b)
{
    return a.w < b.w;
}

int _find(int a)
{
    if (p[a] == a)
        return a;
    else
        return p[a] = _find(p[a]);
}

void _union(int a, int b)
{
    a = _find(a);
    b = _find(b);

    p[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        cin >> tree[i].u >> tree[i].v >> tree[i].w;
    }

    for (int i = 1; i <= v; i++)
    {
        p[i] = i;
    }

    sort(tree, tree + e, compare);

    int cnt = 0, sum = 0;

    for (int i = 0; i < e; i++)
    {
        if (cnt == v - 1)
            break;

        int u = tree[i].u;
        int v = tree[i].v;
        if (_find(u) != _find(v))
        {
            _union(u, v);
            cnt++;
            sum += tree[i].w;
        }
    }
    cout << sum << "\n";
}