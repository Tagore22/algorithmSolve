#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// �÷��̵� �˰��� �����̳� ������ ���Ⱑ �������.
// �ٷ� ģ���� 1��, ģ���� ģ���� 2�� ���� ����� ��, �ٷ� �湮 ������ ������ 1��,
// �湮 ������ �������� �湮 ������ ������ 2���� �����ϴ�.
// ��, ��� �������� �ٸ� ��� �������� �������� ���� ū ������ ��� �� ������
// ���� ���� �������� ã�� ���� Ǯ�� ����̴�.
// ����, ��� �����鰣�� ������ ���ϱ� ���ؼ� �ܼ� BFS�� �ƴ� �÷��̵� �˰����� ����ؾ� �Ѵ�.

// �ڼ��� ������ �ּ����� �����.

vector<vector<int>> board;
int N, answer;

// ��� �����鰣�� ������ ���ϴ� �Լ�.
void Floyd()
{
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

void MakeAnswer()
{
    answer = 987654321;
    Floyd();

    int cur;
    vector<int> ans;
    for (int iter = 1; iter <= N; ++iter)
    {
        // ��� �������� �������� ���� ū ������ ã�´�.
        cur = 0;
        for (int i = 1; i <= N; ++i)
            if (i != iter)
                cur = max(cur, board[iter][i]);

        // �� ������ ���� �ּ� �������� �۴ٸ� �������� �迭�� ���� �ٸ���
        // ������ �����Ѵ�.
        if (cur < answer)
        {
            answer = cur;
            ans.clear();
            ans.push_back(iter);
        }
        // �� ������ ���� �ּ� ������ ���ٸ� ���� ������ �������� �迭�� ���Խ�Ų��.
        else if (cur == answer)
        {
            ans.push_back(iter);
        }
    }

    // ���� ���̾����� �ٷ� �� �κп��� 1�ð� �����̸� ���ȴ�;;
    // �׳� ���⸸ ����ϸ� �Ǵµ� ", "�� ����ϰ� �־��� T^T
    cout << answer << ' ' << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N + 1, vector<int>(N + 1, 987654321));
    int first, second;
    while (true)
    {
        cin >> first >> second;
        if (first == -1 && second == -1)
            break;
        board[first][second] = 1;
        board[second][first] = 1;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}