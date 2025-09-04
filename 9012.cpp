#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
    stack을 쓸려했지만 안써도 돼서 안씀
*/
int main()
{
     ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    stack<int> stack;

    int t;
    string str;

    cin >> t ;

    while (t--)
    {
        /* code */
        cin >> str;
        int cnt = 0;
        for(string::iterator iter = str.begin(); iter != str.end(); iter++) {
            if(*iter == '(') cnt++;
            if(*iter == ')') {
                if(cnt == 0) {
                    cnt = 100;
                    break;
                }
                else cnt--;
            }
        }

        if(cnt == 0) cout << "YES\n";
        else cout << "NO\n";
        
    }

    

}