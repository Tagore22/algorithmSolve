#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// ���� ū ������ 1�� ����� 1�� ��ǥ���� ���� Ŀ�������� �ݺ��Ѵ�.

priority_queue<int> que;
int N, cur;

void MakeAnswer()
{
    int answer = 0;
    if (N == 1)
    {
        cout << answer << '\n';
        return;
    }
    while (true)
    {
        int next = que.top();
        if (cur > next)
        {
            cout << answer << '\n';
            break;
        }
        que.pop();
        ++cur;
        --next;
        ++answer;
        que.push(next);
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> cur;
    for (int i = 0; i < N - 1; ++i)
    {
        int here;
        cin >> here;
        que.push(here);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}