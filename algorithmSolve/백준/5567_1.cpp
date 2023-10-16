#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 5567���� DFSǮ��.
// ū Ʋ�� ��� ���� ���� ��ĸ� ���� �ٸ���.

vector<vector<int>> board;
bool isanswer[501], visit[501];
int N, M;

// DFS ��ȸ�� �����ϴ� �Լ�.
void DFS(int here, int num)
{
    // �̵��� 2�ʰ���� �����ϰ� Ż���Ѵ�.
    if (num > 2)
        return;

    visit[here] = true;
    isanswer[here] = true;

    // here���� �̵��Ҽ� �ִ� ��� ������ ��ȸ�Ѵ�.
    for (int i = 0; i < board[here].size(); ++i)
    {
        int there = board[here][i];

        // ���� ���� there�� �̹� �湮�Ѱ��̶�� �����Ѵ�.
        if (visit[there])
            continue;

        DFS(there, num + 1);
    }
    // here�� �湮 ���θ� �����Ѵ�.
    visit[here] = false;
}

void MakeAnswer()
{
    memset(isanswer, false, sizeof(isanswer));
    memset(visit, false, sizeof(visit));
    DFS(1, 0);

    int answer = 0;
    // 1���� �Ŷ��̹Ƿ� �����ϰ� 2������ ã�´�.
    for (int i = 2; i <= N; ++i)
    {
        if (isanswer[i])
            ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N + 1, vector<int>());
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        board[from].push_back(to);
        board[to].push_back(from);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}