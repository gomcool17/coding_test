#include <iostream>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

vector<long long> datas;

#define ll long long

int main()
{
    int n;
    ll result = 2001001001;
    vector<ll> datas;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        datas.push_back(a);
    }

    sort(datas.begin(), datas.end());

    int left = 0, right = n - 1;
    int result_l = 0, result_r = 0;
    while(left < right) {
        ll temp = datas[left] + datas[right];

        if(result > abs(temp)) {
            result_l = left, result_r = right;
            result = abs(temp);
        }
       
       // cout << left << " " << right << "\n";
        
        if(temp == 0) {
            left++;
            right--;
        }
        else if(temp > 0) {
           right--;
        }
        else {
            left++;
        }
    }

    cout << datas[result_l] << " " << datas[result_r] << "\n";
}
