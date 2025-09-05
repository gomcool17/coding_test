#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

long long result = 0;
long long k, n;

vector<long long> lans;

long long binary_(long long mid)
{
    long long sum = 0;

    for (long long i = 0; i < lans.size(); i++)
    {
       sum += lans[i] / mid;
    }

    return sum;
}

int main()
{
    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        long long a;
        cin >> a;

        lans.push_back(a);
    }


    long long low = 0, high = 1e10; // 높이에 대한 값

    for (int i = 0; i < 40; i++)
    {
   //     cout << result << "\n";
        long long mid = (low + high) / 2;

        long long len = binary_(mid);

        if (len < n)
        {
            high = mid;
        }
        else
        {
            result = mid;
            low = mid;
        }
    }

    cout << result << "\n";
}