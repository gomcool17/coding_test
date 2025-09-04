#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
// #include <utility>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
    if(a.second == b.second)   return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    // ios_base::sync_with_stdio(false); 
    // cin.tie(0); cout.tie(0);

    vector<pair<int, int>> p;

    int n;

    cin >> n;
    for(int i =0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        p.push_back(make_pair(a,b));
    }

    sort(p.begin(), p.end(), compare);
    vector<pair<int, int>>::iterator iter;
   for(const auto& pairs : p) {
    cout << pairs.first << " " << pairs.second << "\n";
   }
}