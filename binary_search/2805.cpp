#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

long long result = 0;
long long n, m;

vector<long long> h;

long long binary_(long long high) 
{
    long long sum = 0;

    for(long long i=0; i<h.size(); i++) {
        if(h[i] >= high) sum += (h[i] - high);
    }

    return sum;
}

int main()
{
     cin >> n >> m;

    for(int i=0;i<n;i++) {
        long long a;
        cin >> a;
        h.push_back(a);
    }

    long long low = 0, high = 1e9; // 높이에 대한 값

    for(int i=0;i<40;i++) {
        long long mid = (low + high) / 2;

        long long len = binary_(mid);

        if(len >= m) {
            result = mid;
            low = mid;
        }
        else {
            high = mid;
        }
    }

    cout << result << "\n";
}