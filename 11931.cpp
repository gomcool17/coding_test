#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
// #include <utility>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    vector<int> numbers;

    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        numbers.push_back(a);
    }

    sort(numbers.begin(), numbers.end(), compare);

    for (const auto &number : numbers)
    {
        cout << number << "\n";
    }
}