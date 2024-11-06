#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Ǯ��.
// �켱���� ť�� �̿��Ͽ� ������ �����ϸ� �ű�� �����ΰ� ������ �׳� ���ͷ� Ǯ����.
// �켱���� ť�� �̿��ϸ� �Ź� ��ȸ�� �ʿ䰡 ������ �ξ��� ������ �Ұ��̴�.

// �ڼ��� ������ �ּ����� �����.

pair<int, int> board[100000]; // ������ �ð�, ����� Ƚ��.
vector<pair<int, int>> answer;
int N;

void MakeAnswer()
{
    // ���� ���� �����ϰ� ���� ���� ������ ������ ����.
    sort(board, board + N);
    answer.push_back(make_pair(board[0].second, 1));
    // ��� �ο����� ��ȸ�ϸ� ������ �ִ� ���� �ְ�, ������ ���ٸ� ���ο�
    // ��ǻ�͸� �߰��Ѵ�.
    for (int iter = 1; iter < N; ++iter)
    {
        int idx = answer.size();
        bool IsFind = false;
        for (int i = 0; i < idx; ++i)
        {
            if (answer[i].first <= board[iter].first)
            {
                answer[i] = make_pair(board[iter].second, answer[i].second + 1);
                IsFind = true;
                break;
            }
        }
        if (!IsFind)
            answer.push_back(make_pair(board[iter].second, 1));
    }
    cout << answer.size() << '\n';
    for (auto& now : answer)
        cout << now.second << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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