#include <iostream>
#include <cstring>

using namespace std;

//Ǯ��
//����Ž�� + �ִ� 2��50���� + ��ġ�� �κ��� ���������� DP���� ��� �κ��� DP�� ��ƾ����� ������ ����ߴµ�,
//�������� DP�� ������ �ȴ�. �������� ������ 0 ~ 1000�̰� �ִ� ���� ���� 50�̹Ƿ� �� 5���̱⿡ ����� �ð����� ������ �����ϴ�.
//�迭�� 2���� �迭�� [���� ���� �ε���][������]���� ���� ���� ��ȸ�ϸ� �����ϴ� ���������� ���� ���� ���������� ���������� ����, ����
//������ �غ��� ������ ������� �� true�� �������ش�. ��� ���� ��ȸ�ϸ� ������ N��° ��� �ִ� �������� ����ϸ� �ȴ�.

int board[50];
bool check[51][1001];
int N, S, M;

void MakeAnswer()
{
    check[0][S] = true;

    for (int i = 1; i <= N; ++i)
        for (int j = 0; j <= M; ++j)
            if (check[i - 1][j])
            {
                if (j + board[i - 1] <= M)
                    check[i][j + board[i - 1]] = true;
                if (j - board[i - 1] >= 0)
                    check[i][j - board[i - 1]] = true;
            }

    int answer = -1;
    for (int i = 0; i <= M; ++i)
        if (check[N][i])
            answer = i;

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, false, sizeof(check));

    cin >> N >> S >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}