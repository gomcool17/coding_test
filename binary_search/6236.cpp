#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

long long result = 0;
long long n, m;

vector<long long> datas;

long long binary_(long long money)
{
    long long date = 0;
    long long _now = 0;
    int cnt = 1;

    for (long long i = 0; i < datas.size(); i++)
    {
        if (datas[i] > money)
            return -1;

        if(m-cnt == n -i) {
            cnt++;
            continue;
        }

       if(datas[i] <= money) {
            if(_now + datas[i] <= money) {

                _now += datas[i];
            }
            else {
                cnt++;
                _now = datas[i];
            }
       }
    }

    return cnt;
}

int main()
{
    cin >> n >> m;

    long long add_data = 0;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        add_data += a;
        datas.push_back(a);
    }

    long long low = 0, high = add_data; // 높이에 대한 값

    for (int i = 0; i < 40; i++)
    {
        long long mid = (low + high) / 2;

        long long cnt = binary_(mid);
       // cout << mid << " " << cnt << "\n";
        if(cnt == -1) {
            low = mid + 1;
            continue;
        }

        if (cnt > m)
        {
            low = mid + 1;
        }
        else
        {
            if(cnt == m) result = mid;
            high = mid - 1;
        }
    }

    cout << result << "\n";
}