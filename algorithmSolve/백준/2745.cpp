#include <iostream>
#include <cmath>

using namespace std;

// Ǯ��.
// ���� ��ȯ�� ������ �״�� �����ϸ� �ȴ�. 10���� �� 5�� 2�������� ��ȯ�ϸ�
// 101�� �ȴ�. ��� ��ȯ�Ͽ��°�? 2�� ������ �������� ��Ƶθ� �ȴ�.
// ���� �̰� ������ ����Ͽ� B������ ����� �ȴ�. 0�� �ڸ����� �־��� ����
// B�� i������ ���Ͽ� �� ������ ��� ���ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

string str;
int B;

void MakeAnswer()
{
    // ���� �ڸ���, string���� int�� ��ȯ�ϱ� ���� ������ ��, ������.
    int idx = 0, minus, answer = 0;
    // 0�� �ڸ��� �ǵں��� 0��° ���ұ��� ��ȸ�Ѵ�.
    for (int i = str.size() - 1; i >= 0; --i)
    {
        // ���� ���� ���ڶ�� 48�� ���� ���� ����� �ȴ�.
        if ('0' <= str[i] && str[i] <= '9')
            minus = 48;
        // ���ĺ� �빮�ڶ�� 55�� ���� 'A'�� 10���� �����ϰ� �ϸ� �ȴ�.
        else
            minus = 55;

        // B�� ���� �ڸ��� ���� * ���� ���� ���Ͽ� �����信 ���ϸ� �ȴ�.
        answer += pow(B, idx) * (str[i] - minus);
        // �ڸ��� ����.
        ++idx;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str >> B;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}