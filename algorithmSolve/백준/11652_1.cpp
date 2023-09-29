#include <iostream>
#include <algorithm>

using namespace std;

// 11652���� �ٸ� Ǯ��.
// ���̰��� �̿����� �ƴ��ϰ� ���� �ϳ��� ���簪�� ���İ��� ���Ѵ�.
// ū ������ ������ �̰͸� �ٸ���. �޸𸮳� ���ɿ����� ���̰� ������.

// �ڼ��� ������ �ּ����� �����.

long long board[100000];
int N;

void MakeAnswer()
{
    sort(board, board + N);
    pair<int, long long> answer = make_pair(-1, -1); // ����, ���Ұ�.
    pair<int, long long> prev_num = make_pair(1, board[0]); // ������ ��ġ��, ���Ұ�.
    for (int i = 0; i < N - 1; ++i)
    {
        // ���簪�� ���İ��� ���ٸ� ���簪�� ����Ƚ���� 1 �����Ѵ�.
        if (board[i] == board[i + 1])
        {
            ++prev_num.first;
        }
        // �׷��� �ʴٸ� ���簪�� ����Ƚ���� ������ answer�� ���Ͽ� answer�� �����ϰ�
        // ���������� �����Ѵ�.
        else
        {
            answer = prev_num.first > answer.first ? prev_num : answer;
            prev_num = make_pair(1, board[i + 1]);
        }
    }
    // �������� �ѹ� �� �����ؾ��Ѵ�.
    answer = prev_num.first > answer.first ? prev_num : answer;
    cout << answer.second << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}