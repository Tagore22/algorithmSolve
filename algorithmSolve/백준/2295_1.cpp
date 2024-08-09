#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

// 2295���� �ٸ� Ǯ��. bitset�� ����Ͽ� �ӵ��� Ȯ���� ���������� �޸𸮰� ���� �þ��.
// ������ ���͵� ���� ���ε� bitset�� ���� �������� ��԰� �־���. �Ѹ���� ǥ�����ڸ�
// bit�� �迭�̴�. ���ø� �Ű������� �ִ�� ǥ���ϰ��� �ϴ� ������ ���̴�. �̰��� �迭ó��
// array[]�ȿ� ������ �����Ѵ�. �ڼ��� ���� STLå�� 521p���� ���캸��.

int board[1000];
// ����� bitset��. 
bitset<200000001> sum;
int N;
const int MAXNUM = 200000000;

// a, b, c�� ���� d�� �迭�ȿ� �����ؾ���.
// �� a + b�� ���س����� �迭���� ��� �� �� y - x�� 
// a + b�� ���ٸ� y�� ���� ū���� �ȴ�.

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            // �迭�� ���Ұ��� �ִ� 2���� ���� �ʴ°� �̿��� ����ġ��.
            if (board[i] + board[j] <= MAXNUM)
                sum[board[i] + board[j]] = 1; // ���� ���� ��Ʈ 1�� �ٲپ� ���縦 ǥ���Ѵ�.

    sort(board, board + N);

    for (int i = N - 1; i >= 0; --i)
        for (int j = i; j >= 0; --j)
            if (sum[board[i] - board[j]] == 1)
            {
                cout << board[i] << '\n';
                return;
            }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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