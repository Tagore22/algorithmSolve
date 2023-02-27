#include <iostream>
#include <vector>

using namespace std;

// Ǯ��
// ���� �� ������ ������ ��� ���ʿ��� �����ؼ� �ݴ������� ���ư��� �ִ� ��츦 ���� ���ư��� ��� �Ҷ�
// ���� ���ư��� �ִ� ���� ������ ����.

// 1. ó������ ������ ���� ���� ���.
// 2. ���� ���� ���� ���� 1���� ���� ���θ� �ξ� ó������ ������ ��������.

// �ٸ� ���δ� ��ĭ�� ���� �ϳ��ۿ� �Ѽ� ����, ���̰� 1�϶����� �Ѽ� �ִ�.
// �� �׷����� �۰� ������ �ϳ��� Ǯ���.

// 1. [idx][0]���� �����Ͽ� [idx][N - 1]���� ���η� ���� �ִ��� Ȯ���ϴ� �Լ�.
// 2. [0][idx]���� �����Ͽ� [N - 1][idx]���� ���η� ���� �ִ��� Ȯ���ϴ� �Լ�.
// 3. �� ����� ��ȯ�ϴ� �Լ�.

// 1�� �Լ��� ������ ������ ����.
// 1. ���簪�� �������� ���� dis�� ���Ѵ�.
// 2. dis�� 2���� ũ�ٸ� ���θ� ����Ͽ��� �������� �����Ƿ� 0�� ��ȯ�Ѵ�.
// 3. dis�� 1�̶�� ���θ� �ΰ� �Ѿ�� �ִ�. ������ ���� ���θ� �� L���� ĭ�� Ȯ���Ǿ��ִ��� Ȯ���ؾ��Ѵ�.
// 3-1. ���簪�� �������� ���Ͽ� ����ʿ� ���θ� �ξ���ϴ��� Ȯ���Ѵ�.
// 3-1-1. ���θ� �δ� L���� ĭ�� �ִ��� Ȯ���ϰ� �������� �ʴ´ٸ� 0�� ��ȯ�Ѵ�.
// 3-1-2. �����Ѵٸ� L���� ĭ�� ��� ���� ���� ������ �ִ���, ������ ���θ� �ξ��������� ��� Ȯ���ϵ�, �ϳ��� ���ǿ� �������� �ʴ´ٸ�
// 0�� ��ȯ�ϰ� ��� �����Ѵٸ� ���θ� �а��� vector<vector<bool>> check ���Ϳ� ��������, �������� �Ѿ��.
// 4. 0�� ��ȯ���� �ʰ� ��� ��ȸ�� �����ٸ�(�̹� ���� ���ư��� �ִٸ�) 1�� ��ȯ�Ѵ�.

// 2�� �Լ��� ������ 1���� ����, ���ο� ������ ���̸��� �����Ѵ�. 

// 3�� �Լ��� 0���� N-1��ŭ ��ȸ�ϸ� idx��° ���� Ȥ�� ���ΰ� ���� ���ư��� �ִ��� 1�� �Լ��� 2�� �Լ��� ȣ���Ͽ� Ȯ���Ѵ�.�ٸ� 2�� �Լ��� ȣ���ϱ��� 
// ���θ� �ξ����� Ȯ���ϴ� check�� �ٽ� ������ �־���Ѵ�. 1�� �Լ��� ��ȸ�� ������ 2�� �Լ��� ��ȸ�� ���� ���� ��ǥ���� ������ �Ǿ� 1�� �Լ�����
// � ��ǥ���� ���θ� �ξ������� ���� ���ΰ� 2�� �Լ����� ������ ��ġ�� �ȵǱ� �����̴�. ���� ��°� answer�� 0���� �ΰ�, 1�� Ȥ�� 2�� �Լ��� ȣ��
// �Ҷ����� �� ���η� ���� answer���� �����ϰ� ��� ��ȸ�� �������� answer�� ����Ѵ�.

vector<vector<int>> board;
vector<vector<bool>> check;
int N, L, answer = 0;

int CangoCol(int idx)
{
    int dis;
    for (int i = 0; i < N - 1; ++i)
    {
        dis = abs(board[i][idx] - board[i + 1][idx]);
        if (dis >= 2)
        {
            return 0;
        }
        else if (dis == 1)
        {
            if (board[i][idx] > board[i + 1][idx])
            {
                if (i + L >= N)
                {
                    return 0;
                }
                else
                {
                    for (int j = 0; j < L; ++j)
                        if (board[i + 1][idx] != board[i + 1 + j][idx] || check[i + 1 + j][idx])
                            return 0;

                    for (int j = 0; j < L; ++j)
                        check[i + 1 + j][idx] = true;
                }
            }

            else
            {
                if (i + 1 - L < 0)
                {
                    return 0;
                }
                else
                {
                    for (int j = 0; j < L; ++j)
                        if (board[i][idx] != board[i - j][idx] || check[i - j][idx])
                            return 0;

                    for (int j = 0; j < L; ++j)
                        check[i - j][idx] = true;
                }
            }
        }
    }

    return 1;
}

int CangoRow(int idx) // ���η� ���ư���.
{
    int dis;
    for (int i = 0; i < N - 1; ++i)
    {
        dis = abs(board[idx][i] - board[idx][i + 1]);
        if (dis >= 2)
        {
            return 0;
        }
        else if (dis == 1)
        {
            if (board[idx][i] > board[idx][i + 1])
            {
                if (i + L >= N)
                {
                    return 0;
                }
                else
                {
                    for (int j = 0; j < L; ++j)
                        if (board[idx][i + 1] != board[idx][i + 1 + j] || check[idx][i + 1 + j])
                            return 0;

                    for (int j = 0; j < L; ++j)
                        check[idx][i + 1 + j] = true;
                }
            }

            else
            {
                if (i + 1 - L < 0)
                {
                    return 0;
                }
                else
                {
                    for (int j = 0; j < L; ++j)
                        if (board[idx][i] != board[idx][i - j] || check[idx][i - j])
                            return 0;

                    for (int j = 0; j < L; ++j)
                        check[idx][i - j] = true;
                }
            }
        }
    }

    return 1;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        answer += CangoRow(i);

    check.clear();
    check.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; ++i)
        answer += CangoCol(i);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;
    board.resize(N, vector<int>());
    check.resize(N, vector<bool>(N, false));
    int cur;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> cur;
            board[i].push_back(cur);
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}