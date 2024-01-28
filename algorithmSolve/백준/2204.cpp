#include <iostream>

using namespace std;

// Ǯ��.
// ���� string�� ���� ���ؿ��� ��ҹ����� ���ε� ���ԵǴµ� �� �������� ��ҹ����� ������ ����� �ϱ� ������
// ��� ���ڸ� �빮�� Ȥ�� �ҹ��ڷ� �ٲ��־�� �ߴ�. �� ���� �� ���ڿ����� ���Ͽ� ���� ���������� ���� ���ڿ���
// ����ϸ� �ȴ�. �Ѱ��� ���� �Ȱ͵� �ִµ� �ƽ�Ű �ڵ忡�� �빮�ڰ� �� �ڿ� �ִ��� �˾Ҵµ� ������ �ҹ��ڰ� �� �ڿ�
// �־���.

// �ڼ��� ������ �ּ����� �����.

int N;

void MakeAnswer()
{
    while (true)
    {
        cin >> N;
        if (N == 0)
            break;
        string prev = "z", answer = prev;
        for (int i = 0; i < N; ++i)
        {
            string cur;
            cin >> cur;
            // ���� �ռ��� ���ڿ��� ��ȯ ���� ���·� ����ؾ� �ϱ� ������ �����صд�.
            string now = cur;
            // ���� ���ڿ��� ��� �ҹ��ڷ� ġȯ�Ͽ� ���Ѵ�.
            for (int j = 0; j < cur.size(); ++j)
                if ('A' <= cur[j] && cur[j] <= 'Z')
                    cur[j] += 32;
            if (cur < prev)
            {
                prev = cur;
                answer = now;
            }
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}