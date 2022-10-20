#include <iostream>
#include <vector>

using namespace std;

//�ѹ��� ������ ���� x,y�� �ִܰŸ� Ȥ�� ���ް��ɼ��� �ľ��ϴ� �÷��̵� ���� �����̴�. Ư���� �����ؾ��ϴ����� ���⿡ ����� ������,
//�ٸ� ���� �÷��̵� ������ i���� i�� �̵����� �ʴ� �״���̱⿡ ���ް������� �̸� ��ó��������, �̹� ������ i���� i�� ���ް�������
//�ʴ´�(�Է��� [i][i]�� 0�� ���)��� �־����� ��쵵 �ֱ⿡ ������ �� ��ó���� ���� �����߰� �����Ҽ��� �־���.

vector<vector<int>> board;
int N;

void MakeAnswer()
{
    /*for (int i = 0; i < N; ++i) <<< �������� �ʾƵ� �־����� �ش� ���Ұ��� 0�̶�� �����Ҽ� ���ٰ� �ؾ���.
        board[i][i] = 0;*/

    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                board[i][j] |= board[i][k] & board[k][j];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}