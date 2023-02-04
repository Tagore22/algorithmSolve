#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

//Ǯ��
//A�� B�� �ŷ��Ѵٴ°� B�� ��ŷ������ A�� �Ѿ�� �ִٴ°��� ���Ѵ�. �׷����� 2���� ���͸� �����Ͽ� A�� B�� �ŷ��Ҷ�
//board[B]�� A�� �־� �� �������� �����Ҽ� �ִٴ°� ����صд�. �� ���� 1~N�� ��ǻ�Ϳ��� �����Ͽ� �����Ҽ� �ִ� �ִ밪��
//����Ͽ� ���� ���� �����Ҽ� �ִ� ��ǻ���� ��ȣ�� ����Ѵ�.

vector<vector<int>> board;
int answer[10001];
bool check[10001];
int N, M;

void BFS(int from)
{
    queue<int> que;
    que.push(from);
    check[from] = true;
    int ans = 0;

    while (!que.empty())
    {
        int here = que.front();
        que.pop();
        ++ans;

        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i];
            if (!check[there])
            {
                que.push(there);
                check[there] = true;
            }
        }
    }
    answer[from] = ans;
}

void MakeAnswer()
{
    for (int i = 1; i <= N; ++i)
    {
        memset(check, false, sizeof(check));
        BFS(i);
    }

    int num = *max_element(answer, answer + N + 1);
    for (int i = 1; i <= N; ++i)
        if (answer[i] == num)
            cout << i << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(answer, 0, sizeof(answer));

    cin >> N >> M;
    board.resize(N + 1, vector<int>());
    int a, b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        board[b].push_back(a);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}