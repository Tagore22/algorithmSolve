#include <iostream>

using namespace std;

// 1 ~ 30 ������ ������ �Է¹��� 28���� ���Ե��� �ʴ� ���� ã�� ������.
// int �迭�� �ʱ�ȭ�Ҷ� {0, } �� ���� 0���� �ʱ�ȭ�� �����ߴµ�
// bool ���� {false, }�� ��� �ʱ�ȭ�� �����ߴ�. �������� cstring�� include�ؼ�
// memset()�� ����Ͽ��µ� ���� �׷� �ʿ䰡 ���°� ����.

int main()
{
    bool board[31] = { false, };
    for (int iter = 0; iter < 28; ++iter)
    {
        int num;
        cin >> num;
        board[num] = true;
    }
    for (int iter = 1; iter < 31; ++iter)
        if (!board[iter])
            cout << iter << '\n';
    return 0;
}