#include <iostream>

using namespace std;

//Ǯ��
//�Է� �޴� ���� 0 Ȥ�� 1���� 2�����̱⿡ ���� �迭�� ����� ������ �ʿ� ���� ���� 2���� ������ �� ��Ȳ�� ����Ҽ� �ִ�. ���� 4���� ���� ����ް� ���������� 5����
//������ �ϳ��� �´� ���� ����ϸ� �Ǵµ� ��� ��� ���ؼ� 4�� ���;� �ϹǷ� ���� �ϳ��� Ȯ���ص� ���¸� �˼� �ִ�.

char board[5] = { 'E', 'A', 'B', 'C', 'D' };

void MakeAnswer()
{
    int one, zero, num;
    for (int i = 0; i < 3; ++i)
    {
        one = zero = 0;
        for (int j = 0; j < 4; ++j)
        {
            cin >> num;
            if (num == 0)
                ++zero;
            else
                ++one;
        }
        cout << board[zero] << '\n';
    }
}

int main()
{
    MakeAnswer();
}