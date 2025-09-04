#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
// #include <utility>

using namespace std;

bool compare(char a, char b)
{
    return a > b;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

   string str;
   cin >> str;

   sort(str.begin(), str.end(), compare);

   cout << str;
}