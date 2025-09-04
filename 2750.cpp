#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

/*
    stack을 쓸려했지만 안써도 돼서 안씀
*/
int main()
{
    // ios_base::sync_with_stdio(false); 
    // cin.tie(0); cout.tie(0);

    int num[1000];
    int n;

    cin >> n;
    for(int i =0; i<n; i++) {
        int variable;
        cin >> variable;
        num[i] = variable;
    }

    sort(num, num+n);

    for(int i =0; i<n; i++) {
        cout << num[i] << '\n';
    }
}