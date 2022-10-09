#include <iostream>
#include <cmath>

//����� �������� �����̴�. �־��� ������ 4����س����� ������ʿ� �ش�� ��� �ణ�� ���Ʈ������ ���� ����Ѵ�.
//�� ������ Ǯ�� ���ؼ� 2���� ���� �ʿ��ѵ�
//1. ���� y�ప Ȥ�� x�ప�� 2�� ���� �� div
//2. �� div�� ������ mul
//�� 2������ �ʿ��ϴ�. �� ��ǥ���� div�� ���� ���������� ������ 4��� �Ͽ����� ���ο� ��ǥ���̰�, �� ��ǥ���� div�� ���� ����
//���� ���ǿ��� ���Ҽ� �ִ� ������ ��(�� ������ ��������)�̴�. ��, ���� ���ǿ��� ���Ҽ� �ִ� ������ ���ϰ� 4����Ͽ� ���� ��������
//�Ѿ�� ��͸� �̿��Ͽ� ��������� y�ప Ȥ�� x�ప�� 2�϶� ������ ������ �߰��Ͽ� �� ������ ���Ѵ�.

using namespace std;

int N, r, c;
int answer = 0;

//��ȸ ������ ���� ���, ���� ���, ���� �ϴ�, ���� �ϴ��̱⿡ x���� ���� ������ mul���� ��������
//y���� ���� ������ mul * 2�� ������Ѵ�.

void MakeAnswer(int side_size, int y, int x)
{
    if (side_size == 2)
    {
        answer += y * 2;
        answer += x * 1;
        cout << answer << '\n';
        return;
    }

    int div = side_size / 2;
    int mul = div * div;
    int next_y = y % div;
    answer += y / div * mul * 2; //��ȸ ������ ���� 2�� �߰��� ������.
    int next_x = x % div;
    answer += x / div * mul;

    MakeAnswer(side_size / 2, next_y, next_x);
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> r >> c;
}

int main()
{
    Input();
    MakeAnswer(pow(2, N), r, c);
    return 0;
}