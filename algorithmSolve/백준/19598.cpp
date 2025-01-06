#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���� �Ͽ� �׸��� �˰����� �����ϸ� ����� ������ ���Ծ���. �׶��� ����ð��� �������� �����Ͽ�
// ������ Ǯ���� �� ����� �ǻ�� �Ȱ��� �Ͽ��µ� ���� ������ �ʾҴ�. �̷��� �Ƿ� ���� �����ߴ�.
// ť�� 30, 40�� �����ְ� ���� ȸ�ǰ� 50 ~ 60, 30 ~ 70�� �� ����ð��� �������� �Ѵٸ� 
// 50 ~ 60�� ���� ť�� �����Ѵ�. 50�� 30���� �۱⿡ ��ü�ǰ� �״��� 30 ~ 70�� ť�� �������� ��
// 30�� �� ��κ��� �۱⿡ ���ο� ȸ�ǽ��� �����. ������ ���۽ð��� �������� �����Ѵٸ�
// �߰��� ȸ�ǽ��� �ʿ� ����.

// �������� �̷� ���� �ִ� �� ������ �� ����صξ�߰ڴ�. ȸ�ǽ��� �� ���� ������ ȸ���� ������� ����ð���
// ȸ�ǽ��� ���� ���� ������ ���۽ð��� ��������. �������� �ƴϰ����� ��ħ���δ� �� �� ����.

// �ڼ��� ������ �ּ����� �����.


pair<int, int> board[100000];
int N;

void MakeAnswer()
{
    sort(board, board + N);
    priority_queue<int> que;
    que.push(-board[0].second);
    int answer = 1;
    for (int i = 1; i < N; ++i)
    {
        int prev = -que.top();
        if (prev <= board[i].first)
            que.pop();
        else
            ++answer;
        que.push(-board[i].second);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}