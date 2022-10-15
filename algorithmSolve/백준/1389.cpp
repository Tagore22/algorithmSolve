#include <iostream>
#include <vector>

using namespace std;

//�׷������� �ѹ��� ���� ��ǥ���� �Ÿ��� �˾ƾ��ϴ� �÷��̵� �ͼ� �����̴�. �ܼ��ϰ� a�� b�� �ִܰŸ��� �ƴ�
//1���� 2,3,4,5�� �Ÿ�, 2���� 1,3,4,5�� �Ÿ� �� �������� �ִܰŸ��� ��� �˾ƾ��ϱ� �����̴�.

vector<vector<int>> board;
int N, M;

//i���� i�� 0���� �Ѵ�. �� �˰����� a���� b�� �ִܰŸ� + b���� c�� �ִܰŸ��� ���� a���� c�� �ִܰŸ��� ���ϱ� ������
//i���� i�� ��ǻ� �������� �ʴ� �ִܰŸ��� ���Ե��� �ʴ� �κ��̿����ϱ⿡ 0�� �����ϴ�.

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        board[i][i] = 0;
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);

    pair<int, int> answer = make_pair(-1, 987654321);
    for (int i = 0; i < N; ++i)
    {
        int check = 0;
        for (int j = 0; j < N; ++j)
            check += board[i][j];

        answer = check < answer.second ? make_pair(i, check) : answer;
    }
    cout << answer.first + 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N, vector<int>(N, 150));
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a - 1][b - 1] = 1;
        board[b - 1][a - 1] = 1;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}