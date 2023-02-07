#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// Ǯ��
// 1461�� ������ ������ ����� ������. �� ������ ���� �� ���� �ִ�ȭ ��Ű���� �̿��̸� ū �μ����� ����� �ϴµ� ���������� ��� �ִ�.
// 
// 1. ����� ������� ���´�.
// 2. ������ �������� ���´�.
// 3. ����� 0�� ���ؼ� ����� Ŀ���� �ʴ´�.
// 4. ������ 0�� ���ؼ� �� Ŀ����.

// �� ���ǿ� ���� ������ 0���� ó���� �ϰ� ����� 0�� ������ �������� ó���� �ؾ��Ѵ�. ��, ����� ������ ��������Ѵ�.
// ��谪 bound�� ������ N���� ���� �Է¹����� �ش� ���� 0���� �۰ų� ���ٸ� bound�� �������� ��ġ�� �����Ѵ�.
// ���� ���ʺ���(0����) bound - 1���� 2ĭ�� �ٸ� �� ���� ���� �պ��� ũ�ٸ� �����ָ� ���꿡 ���Ǿ��ٴ� ������
// check�� true�� ���Ž�Ų��. �����ʵ�(N-1����) bound�� ������ �������� �����ϸ� �ݺ��Ѵ�.
// ���� check�� ��ȸ�ϸ� ���� ���꿡 ���Ե��� ���� ������ ��� ���� ����ϸ� �ȴ�.

int board[50];
bool check[50];
int N, bound = 0;

void MakeAnswer()
{
    int answer = 0;
    sort(board, board + N);

    for (int i = 0; i < bound - 1; i += 2)
        if (board[i] * board[i + 1] > board[i] + board[i + 1])
        {
            check[i] = true;
            check[i + 1] = true;
            answer += board[i] * board[i + 1];
        }

    for (int i = N - 1; i > bound; i -= 2)
        if (board[i] * board[i - 1] > board[i] + board[i - 1])
        {
            check[i] = true;
            check[i - 1] = true;
            answer += board[i] * board[i - 1];
        }

    for (int i = 0; i < N; ++i)
        if (!check[i])
            answer += board[i];

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, false, sizeof(check));

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        if (board[i] <= 0)
            ++bound;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}