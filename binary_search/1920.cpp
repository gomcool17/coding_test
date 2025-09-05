#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    vector<int> nn,mm;
    cin >> n;
    for(int i=0;i<n;i++) {
        int a; cin>>a;
        nn.push_back(a);
    }

    sort(nn.begin(), nn.end());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        mm.push_back(a);
    }

    for (int i = 0; i < mm.size(); i++)
    {
        if(binary_search(nn.begin(), nn.end(), mm[i])) 
            cout << "1\n";
        else    
            cout << "0\n";
    }

}