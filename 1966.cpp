#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int t;

    cin >> t ;

    while (t--)
    {
        /* code */
        int n,m;
        queue<pair<int, int>> prints, nums;
        priority_queue<int> priority;
        vector<pair<int, int>> original;

        cin >> n >> m;

        for(int i=0; i <n; i++) {
            int num; cin >> num;
            pair<int, int> p = make_pair(i, num);
            original.push_back(p);
            nums.push(p);
        }

        for(int i=0; i<original.size(); i++) {
            priority.push(original[i].second);
        }

        int result = 0;
        while(!nums.empty()) {
            // 현재 제일 높은 우선순위
            int now = priority.top();
            // 현재 차례인 프린트
            pair<int,int> now_print = nums.front();
            nums.pop();

            if(now > now_print.second) { // 현재의 높은 우선순위가 지 차례보다 높다면
                nums.push(now_print); // 다시 넣어준다
            }

            if(now == now_print.second) { // 현재 문서가 알맞은 우선순위면 우선순위에서 제거
                result++;
                priority.pop();

                if (m == now_print.first)
                { // 원하는 문서일시
                    break;
                }
            }
        }

        cout << result << "\n";
    }
}