#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Ǯ��
// 2���� �켱����ť�� �����Ѵ�. max_top�� M/2���� ���������� ������ ���̰�, min_top�� ū������ ������ ���̴�.
// M���� ���� max_top���� �ֵ�, ū������ ���� ���� min_top.top()�� ���������� ���� ū���� max_top.top()���� ũ�ٸ�
// �ΰ��� ��ȯ���ش�. �̰��� M�� �ݺ��ϸ� Ȧ�������� ���� �߾Ӱ� ��, max_top.top()�� ������ answer�� �������ְ�
// M���� ��ȸ�� ������ answer�� ũ��� ���Ұ����� ������ָ� �ȴ�.

// �� Ǯ�̴� �켱����ť�� ������ ���İ��� �ǵ帮�� �ʰ� ���԰� ��ȯ�� -������ ���־� ó���ߴµ�, �־����� �Է°���
// �ſ� ũ�ų� ������ -������ �ϴ� int���� ������ �������. �Ź� -���굵 �ؾ��ϰ� �������� ��� ��쵵 ������,
// �׳� ������ ���� �� ���İ��� �ٲ��־�߰ڴ�.

int T;

void MakeAnswer()
{
    int M;
    vector<long long> answer;
    for (int i = 0; i < T; ++i)
    {
        priority_queue<long long> max_top, min_top;
        answer.clear();
        cin >> M;
        long long num;
        for (int j = 1; j <= M; ++j)
        {
            cin >> num;
            if (max_top.size() == min_top.size())
                max_top.push(num);
            else
                min_top.push(-num);

            if (!max_top.empty() && !min_top.empty() && max_top.top() > -min_top.top())
            {
                long long from_min = -min_top.top();
                min_top.pop();
                long long from_max = max_top.top();
                max_top.pop();
                min_top.push(-from_max);
                max_top.push(from_min);
            }

            if (j % 2 != 0)
                answer.push_back(max_top.top());
        }

        cout << answer.size() << '\n';
        for (int i = 0; i < answer.size(); ++i)
        {
            if (i != 0 && i % 10 == 0)
                cout << '\n';
            cout << answer[i] << ' ';
        }
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}