#include <iostream>

using namespace std;

// Ǯ��.
// ���������� ���������� ������ �� ������ ���ϰ� �������� Ȥ�� ������ ������������
// ���������� ���� 0���� �ʱ�ȭ�ϸ� ��ȸ���ָ� �ȴ�.
// �ٸ�, �ִ� 1000���� �迭�� ���� �Ⱦ �ٸ��� �غ��Ҵ�.

// �ڼ��� ������ �ּ����� �����.

int N, prev_num, cur;

void MakeAnswer()
{
    prev_num = 1001;
    int answer = 0;
    int ans = 0;
    // �ִ� 1000���� �޸𸮸� �Ẹ�� �ʱ� ���� ������ 2���� ���� ���۸��� ����ϵ� ���� ��ü�Ѵ�.
    // �� �Է¸��� ���������� ���������� �����ٸ� �� ������ ���ϰ� �׷��� �ʴٸ�
    // ���������� 0���� �ʱ�ȭ���ش�.
    for (int i = 0; i < N; ++i)
    {
        cin >> cur;
        if (cur > prev_num)
        {
            ans += cur - prev_num;
        }
        else
        {
            answer = max(answer, ans);
            ans = 0;
        }
        prev_num = cur;
    }
    answer = max(answer, ans);
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