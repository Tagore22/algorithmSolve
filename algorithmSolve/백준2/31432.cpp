#include <iostream>

using namespace std;

// 풀이.
// 처음에는 1 하나만으로는 무조건 소수가 아닌 수를 만들어낼 수 없다고 생각해서
// 1이 아닌 경우에는 11을 곱해 출력하도록 했는데 97퍼에서 계속 틀렸다.
// 알고보니 111이 37 * 3으로 소수가 아닌 수였다. 따라서 그 어떤 수가 나오든간에
// 111을 곱하여 무조건 소수가 아닌 수를 만들 수 있었다.

int N;
int board[10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    for (int i = 0; i < N; ++i)
    {
        cout << "YES" << '\n';
        cout << board[i] * 111 << '\n';
        break;
    }
    return 0;
}