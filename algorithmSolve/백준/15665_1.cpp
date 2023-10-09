#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// 15665���� �ٸ� Ǯ��.
// ������ �� Ǯ�̰� �ٸ� ������� Ǯ�̺��� ������ �ٽ� Ǯ��ô�.
// ��Ͱ� �ʹ� ���� ȣ��Ǵ� �ǰ� �; �̹����� �ƿ� �Է¹�����
// �ߺ��� ���ֹ��ȴ�. ����� ���� �ӵ�����;;

vector<int> board;
int answer[7];
bool visit[10001];
int N, M;

void BackTrack(int idx)
{
    if (idx == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < board.size(); ++i)
    {
        answer[idx] = board[i];
        BackTrack(idx + 1);
    }
}

void MakeAnswer()
{
    sort(board.begin(), board.end());
    BackTrack(0);
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(visit, false, sizeof(visit));

    cin >> N >> M;
    int cur;
    for (int i = 0; i < N; ++i)
    {
        cin >> cur;
        // �̹� ����� ������ üũ�ϴ� visit�� �̿��Ͽ� �Ȱ��� ���� ������ �������� �ʴ´�.
        if (!visit[cur])
        {
            visit[cur] = true;
            board.push_back(cur);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}