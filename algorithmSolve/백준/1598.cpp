#include <iostream>

using namespace std;

//�� �ڸ��� ��ǥ�� �ش� ���� 4�� ���� ���� ������������ ���Ҽ��ִ�.
//y�� : ���� 4�� ���� ��������(�ٸ� 0�Ͻÿ��� 4�� �ٲ���)
//x�� : ���� 4�� ���� ��(�ٸ� ���������� ���� ��� +1 ����)

int from, to;

void MakeAnswer()
{
    int from_X = from / 4;
    from_X = from % 4 != 0 ? from_X + 1 : from_X;
    int to_X = to / 4;
    to_X = to % 4 != 0 ? to_X + 1 : to_X;

    int from_Y = from % 4 != 0 ? from % 4 : 4;
    int to_Y = to % 4 != 0 ? to % 4 : 4;

    int answer = abs(from_X - to_X) + abs(from_Y - to_Y);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> from >> to;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}