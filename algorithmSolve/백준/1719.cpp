#include <iostream>
#include <vector>

using namespace std; //����� �׷���, ������ ��ȣ�� 1������ N����

vector<vector<int>> board;
const int MAXNUM = 987654321;
int N, M;

void Floyd()
{
    vector<vector<int>> answer(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (i != j)
                answer[i][j] = j; //�̺κ��� ���� �߿��ߴµ� �ٸ� ������ �鸣�� �ʰ� ���� ���°��� �ִܰŸ��϶�
    for (int i = 1; i <= N; ++i)  //answer[i][j]�� �ٲ��� �ʱ⿡ �ʱⰪ�� �ʿ��ߴ�.
        board[i][i] = 0;
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
            {
                if (i == j)
                    continue;
                if (board[i][j] > board[i][k] + board[k][j]) //�ִܰŸ��� �ٲ���
                {
                    board[i][j] = board[i][k] + board[k][j]; //�ִܰŸ��� �����ϰ�
                    answer[i][j] = answer[i][k];             //�߰��� �鸣�� �Ǵ� ���� k�� �鸣�� ���� ���� ó�� �鸣��
                }                                            //���� ����
            }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (answer[i][j] == 0)
                cout << '-' << ' ';
            else
                cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N + 1, vector<int>(N + 1, MAXNUM));
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a][b] = min(board[a][b], c);
        board[b][a] = min(board[b][a], c);
    }
}

int main()
{
    Input();
    Floyd();
    return 0;
}