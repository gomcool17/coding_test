#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

long long result = 0;
long long n, m;

vector<long long> nums;

long long binary_(long long high)
{
    long long sum = 0;

    for (long long i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= high)
            sum += high;
        else 
            sum += nums[i];
    }

    return sum;
}

int main()
{
    cin >> n;
    long long mmax = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        mmax = max(mmax, a);
        sum += a;
        nums.push_back(a);
    }

    cin >> m;

    long long low = 0, high = 1e9; // 높이에 대한 값

    for (int i = 0; i < 40; i++)
    {
   //     cout << result << "\n";
        long long mid = (low + high) / 2;

        long long len = binary_(mid);

        if (len > m)
        {
            high = mid;
        }
        else
        {
            result = mid;
            low = mid;
        }
    }

    if(sum <= m) cout << mmax << "\n";
    else cout << result << "\n";
}