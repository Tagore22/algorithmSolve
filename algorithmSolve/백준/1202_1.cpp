#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//1202�� ������ �� ����Ǯ��
//���溰�� ������ �ִ� ��� �������� �켱���� ť�� �����Ͽ�
//���� ��ġ �ִ� ������ ���� ���Ѵ�.
//���� Ǯ�̴� �������� �� * long(������� ��)��ŭ�� �ð����⵵�� �ʿ��Ͽ�����,
//�� Ǯ�̴� ������� �� + �������� ���� �ð����⵵�� �ʿ��Ͽ� �� ������.
//�ٽ��� ���� now��, �Ź� �������� ��ȸ���� �ʰ� �ִ� ��ȸ�Ͽ��� �ε����� �����Ͽ�
//�ð����⵵�� ������ �ƴ� ������ �ǰ� �Ѵ�.

const int MAXNUM = 300000;
pair<int, int> board[MAXNUM];
int backpack[MAXNUM];
int N, K;


void MakeAnswer()
{
    sort(board, board + N);
    sort(backpack, backpack + K);

    long long answer = 0;
    priority_queue<int> que;
    int now = 0;
    for (int i = 0; i < K; ++i)
    {
        while (now < N && backpack[i] >= board[now].first)
            que.push(board[now++].second);
        if (!que.empty())
        {
            answer += que.top();
            que.pop();
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
    for (int i = 0; i < K; ++i)
        cin >> backpack[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}