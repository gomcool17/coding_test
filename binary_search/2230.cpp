#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

long long result = 0;
long long n, m;

vector<long long> datas;

#define ll long long

int main()
{
    ll n,m;
    ll result = 2001001001;
    vector<ll> datas;
    
    cin >> n >> m;

    for(int i=0;i<n;i++) {
        int a; cin >> a;
        datas.push_back(a);
    }

    sort(datas.begin(), datas.end());

    for(int i=0;i<n;i++) {
        // index를 반환함
        int re =  lower_bound(datas.begin(), datas.end(), datas[i] + m)  - datas.begin();

        if(datas[re] - datas[i] >= m) {
            result = min(result, datas[re] - datas[i]);
        }
    }

    cout << result << "\n";
}
