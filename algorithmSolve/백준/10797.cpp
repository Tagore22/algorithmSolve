#include <iostream>

using namespace std;

// 풀이.
// 5개를 수를 입력받되, 주어진 일자와 같은 수를 입력받을때마다 최종값 answer가 1씩 증가한다.

int N;

int main()
{
    cin >> N;
    int num, answer = 0;
    for (int i = 0; i < 5; ++i)
    {
        cin >> num;
        if (num == N)
            ++answer;
    }
    cout << answer << '\n';
}