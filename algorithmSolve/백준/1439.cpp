#include <iostream>

using namespace std;

// Ǯ��.
// �Է¹��� ���ڿ��� �� ���Ҹ� ��ȸ�ϸ� �տ��ҿ� ���� �ι� �ٸ������� ������ answer�� 1�� ��������
// ��ȸ �Ŀ� answer�� ����ϸ� �ȴ�. ù��° �ٸ������� ���� �ٷ� ���������� �� ���ĺ��ʹ� 2��°����
// �����ϱ⿡ bool ������ �̿��Ͽ��� �ߴ�.

// �ڼ��� ������ �ּ����� �����.

string str;

void MakeAnswer()
{
    // ���� ������ üũ�ϴ� bool ����.
    bool isTrans = false;
    int answer = 0;
    for (int i = 1; i < str.size(); ++i)
    {
        // �տ��ҿ� ���� �ٸ������� bool ������ ������Ų��.
        if (str[i] != str[i - 1])
        {
            isTrans ^= 1;
            // bool ������ true���� �Ǿ����� answer�� 1�� ������Ų��.
            // ���ø� �ߺ��� ù��°�� ���� �ٸ������� ���� �ٷ� �����ϳ�
            // �� ���ĺ��ʹ� �ι� �޶�� ���� 1�����ؾ��Ѵ�.
            answer = isTrans ? answer + 1 : answer;
        }
    }

    // ������ ���.
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}