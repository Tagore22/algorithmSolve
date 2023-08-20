#include <iostream>

using namespace std;

// Ǯ��.
// ������ ����� �ֻ������� ���� ���� �����ε� �巴�� ��� �������� ��������.
// ������ �����ڸ� i��° ���ҿ��� ���������� �ڱ��ڽź��� ���� ���ӵ� ���� �ִ밪�� ����ϸ� �Ǵ� ���̴�.
// ūƲ�� ������ ����.

// 1. 0��° ���Һ��� ��ȸ�� �����Ѵ�.
// 2. ���簪�� ���ذ����� ũ�ٸ� ���±��� �߰��� �� ans�� answer�� �����ϰ� ans�� �ٽ� 0���� �ʱ�ȭ�� ���ذ��� ���簪�� �����Ѵ�.
// 3. ���簪�� �� �۴ٸ� ans�� 1 �߰���Ų��.
// 4. ��� ��ȸ������ ���������� answer�� �����Ѵ�. ex) 5 4 3 2 1�϶�.

// �ڼ��� ������ �ּ����� �����.

int N;

void MakeAnswer()
{
    int answer = 0;  // ������.
    int ans = 0;     // ���ذ��� ó���Ҽ� �ִ� ����.
    int cur;         // ���簪.
    int prev_num = -1; // ���ذ�.
    for (int i = 0; i < N; ++i)
    {
        cin >> cur;
        // ���簪�� �� ũ�ٸ� �� ����� 2����� ó���Ѵ�.
        if (cur > prev_num)
        {
            answer = max(answer, ans);
            ans = 0;
            prev_num = cur;
        }
        // �׷��� �ʴٸ� �� ����� 3����� ó���Ѵ�.
        else
        {
            ++ans;
        }
    }
    // ����� 4��ó��.
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