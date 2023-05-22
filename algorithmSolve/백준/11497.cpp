#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// Ǯ��.
// ������ �����Ͽ��� �ô� �ִ���, �ּ����� ����� ������.
// �ΰ��� deque�� ���� ������ �����Ͽ� ������� �հ� �ڿ� �ִ´�.
// �׸��� deque���� ��ȸ�ϸ� �����ϴ� ������ ������ ���밪�� ���� ū���� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[10000];
int T, N;

void MakeAnswer()
{
    deque<int> first, second;
    for (int test = 0; test < T; ++test)
    {
        first.clear();
        second.clear();
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> board[i];

        sort(board, board + N);

        // �� ������ �������(¦���϶��� first��, Ȧ���϶��� second��) �ִ´�.
        for (int i = 0; i < N; ++i)
        {
            if (i % 2 == 0)
                first.push_back(board[i]);
            else
                second.push_front(board[i]);
        }

        // ��ó�� ���� �� ���� ���� ���� ���ʷ� ���Ѵ�.
        int answer = abs(first[0] - second[second.size() - 1]);
        // first�� �ι�° ������ �ǳ����� �ڽ��� ��ĭ �հ� ���̸� ���Ѵ�.
        for (int i = 1; i < first.size(); ++i)
            answer = max(answer, abs(first[i] - first[i - 1]));

        // first�� �� ������ second�� �� ó�� ���� ����Ѵ�.
        answer = max(answer, abs(first[first.size() - 1] - second[0]));
        // ���������� second�� �ι�° ������ �ǳ����� �ڽ��� ��ĭ �հ� ���̸� ���Ѵ�. 
        for (int i = 1; i < second.size(); ++i)
            answer = max(answer, abs(second[i] - second[i - 1]));

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