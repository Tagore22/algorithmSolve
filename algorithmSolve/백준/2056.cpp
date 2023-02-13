#include <iostream>
#include <vector>

using namespace std;

// Ǯ��
// ����Ǵ� �۾��� ��� �ڽ��� ��ȣ���� ���� �͵��̰�, 1�� �۾��� ������ �����۾����� �����ϴ�.
// �׷��Ƿ� 1������ N������ ��ȸ�� ���� �۾� �ð��� ���ϸ� �ȴ�.
// �־��� �Է°����� ���� �۾� i�� �����۾��� ��� �Ϸ�Ǿ�� �ϱ⿡ �����۾����� ���� �ð��� �����ɸ��� �۾� + i���� �۾��ð��� ���ϸ�
// i���� ���� �۾��ð��� ������, ����Ͽ��� N������ ��ȸ�Ͽ� ���� ū �۾��ð��� ����ϸ� �ȴ�.

vector<vector<int>> board;
vector<int> answer;
int N;

void MakeAnswer()
{
    int max_time;
    for (int i = 1; i <= N; ++i)
    {
        max_time = 0;
        for (int j = 0; j < board[i].size(); ++j)
            max_time = max(max_time, answer[board[i][j]]);

        answer[i] += max_time;
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i)
        ans = max(ans, answer[i]);

    cout << ans << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N + 1, vector<int>());
    answer.resize(N + 1, 0);
    int time, num;
    for (int i = 1; i <= N; ++i)
    {
        cin >> time >> num;
        answer[i] = time;
        int first;
        for (int j = 0; j < num; ++j)
        {
            cin >> first;
            board[i].push_back(first);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}