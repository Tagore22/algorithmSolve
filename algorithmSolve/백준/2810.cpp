#include <iostream>

using namespace std;

// Ǯ��.
// ��� ��Ȧ���� ���� ����� ���� �����ϴ� ����� ���� ���Ͽ� �� ���� ���� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int N;

void MakeAnswer()
{
    string str;
    cin >> str;

    int idx = 0;
    int answer = 1;
    // 0 ~ N���� ��ȸ�ϸ� ��� ��Ȧ���� ���� ����Ѵ�.
    while (idx < N)
    {
        // �Ϲ��¼��̶�� ��ĭ��, Ŀ�ü��̶�� 2ĭ�� �ǳ� �ڴ�.
        if (str[idx] == 'S')
            ++idx;
        else
            idx += 2;
        // ��Ȧ���� 1���� �����Ѵ�.
        ++answer;
    }
    answer = min(answer, N);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}