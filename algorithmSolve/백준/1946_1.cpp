#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ������ 1946�� Ǯ�̺��� �� ������ �뷮�� ���� �����ϴ� Ǯ��.
// map�� ����, �ݺ��ڵ� ������ ������ �� �����ϴ�.
// y���� �������� �����Ѵ��� ������ ��ȸ�ϸ�, ���� x������ �� ���� ���Ҹ� ������
// ���� 1�� �����ϰ� ���� x���� ���ŵȴ�.

vector<pair<int, int>> board;
int T, N;

void MakeAnswer()
{
    int y, x, answer;
    for (int i = 0; i < T; ++i)
    {
        board.clear();
        cin >> N;
        for (int j = 0; j < N; ++j)
        {
            cin >> y >> x;
            board.push_back(make_pair(y, x));
        }

        // ��� ���Ұ����� y���� �������� �����Ѵ�.
        sort(board.begin(), board.end());

        answer = 1; // y���� 1�� ���Ҵ� �ּ��� ������ �ȴ�.
        int cur = board[0].second; // ������ �Ǵ� ������ x������ �۾ƾ� �Ѵ�.
        for (int j = 1; j < N; ++j)
            if (cur > board[j].second)
            {
                // �� ���� ���� �߰��ߴٸ� ������ answer�� 1�����ϸ�, �ֽŰ��� cur�� �����Ѵ�. (���� ������)
                ++answer;
                cur = board[j].second;
            }
        cout << answer << '\n';
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