#include <iostream>

using namespace std;

//Ǯ��
//�־��� �迭������ �������� ���۰����� ���������� ������ ��� ���Ͽ� ����Ѵ�.
//������ ���� �ִ밪�� 2�� 32���� - 1 ���� �۴ٰ� ������ ���� �����Ƿ� int�ε� ����� ������ �ִ�.

int board[300][300];
int N, M, K, from_y, from_x, to_y, to_x;

void MakeAnswer()
{
    int answer;
    for (int i = 0; i < K; ++i)
    {
        cin >> from_y >> from_x >> to_y >> to_x;
        answer = 0;

        for (int from = from_y - 1; from < to_y; ++from)
            for (int to = from_x - 1; to < to_x; ++to)
                answer += board[from][to];

        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
    cin >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}