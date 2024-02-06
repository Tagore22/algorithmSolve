#include <iostream>

using namespace std;

// 풀이.
// 두 의견을 총합하여 많은쪽으로 출력하는 문제.

int N;

int main()
{
    int board[2] = { 0, };
    cin >> N;
    int cute;
    for (int i = 0; i < N; ++i)
    {
        cin >> cute;
        ++board[cute];
    }

    if (board[1] > board[0])
        cout << "Junhee is cute!" << '\n';
    else
        cout << "Junhee is not cute!" << '\n';
    return 0;
}