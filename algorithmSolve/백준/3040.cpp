#include <iostream>

using namespace std;

// Ǯ��.
// 0 ~ 9��° �ε������� 2�� for������ �ϳ��� �����Ҷ� �� 2���� ������
// ������ 7���� ���� 100�̶�� ����Ѵ�.

int board[9];
int answer = 0;

int main()
{
    for (int iter = 0; iter < 9; ++iter)
    {
        cin >> board[iter];
        answer += board[iter];
    }

    for (int i = 0; i < 9; ++i)
        for (int j = i + 1; j < 9; ++j)
            if (answer - board[i] - board[j] == 100)
            {
                for (int iter = 0; iter < 9; ++iter)
                    if (iter != i && iter != j)
                        cout << board[iter] << '\n';
                return 0;
            }
}