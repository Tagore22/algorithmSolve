#include <iostream>

using namespace std;

// Ǯ��.
// �־��� ������ �ߺ��� ���� ������ ã�� ����.

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