#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

long long result = -1;
long long x, y;
long long now;

bool binary_(long long mid)
{
    long long num = (y+mid) * 100 / (x+mid);
   // cout << num << "\n";
    if(num > now) return true;
    else return false;
}

int main()
{
    cin >> x >> y;

    now = y * 100 / x;


    //cout << "now : " << now << "\n";

    long long low = 0, high = 30e9; 

    for (int i = 0; i < 40; i++)
    {
        long long mid = (low + high) / 2;

        bool re = binary_(mid);
       //  cout << mid << "\n";

        if(re) {
            result = mid;
            high = mid;
        }
        else {
            low = mid;
        }
        
    }

    cout << result << "\n";
}