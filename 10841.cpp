#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
// #include <utility>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    int n;
    vector<pair<int, string>> data;

    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        string s;
        cin >> a >> s;
        data.push_back(make_pair(a,s));
    }

    stable_sort(data.begin(), data.end(), compare);

    for(int i=0; i<data.size(); i++) {
        cout << data[i].first << " " << data[i].second << "\n";
    }
}