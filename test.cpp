#include <iostream>

using namespace std;

int main()
{
    // 시간초과 방지
    // 입출력 양이 많아지면 입출력하는데 소모시간 상승 -> 시간초과남
    ios_base::sync_with_stdio(false); // c와 c++ 표준 stream의 동기화를 비활성화
    // 기존에는 scanf, prinft등 c스타일과 c++ 스타일을 혼합할수있지만
    // ios_base를 사용하면 혼합은 안됨
    cin.tie(0);
    // cin과 cout를 풀어준다 ** 기존에는 묶임, 내부적으로 묶이는 작업을 하지 않으니까 수행시간 절약

    int a,b;

    cin >> a >> b;
    cout << a+b << endl; // endl대신 '\n'을 사용해야 시간 절약
}