#include <iostream>

using namespace std;

// 풀이.
// 주어진 수들중 중복된 수의 개수를 찾는 문제.

int main()
{
    bool board[101] = { false, };
    int N;
    cin >> N;
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        if (!board[num])
            board[num] = true;
        else
            ++answer;
    }
    cout << answer << '\n';
    return 0;
}