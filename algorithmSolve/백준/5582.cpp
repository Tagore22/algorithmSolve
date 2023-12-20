#include <iostream>

using namespace std;

// Ǯ��. 
// ���� ���� ���ڿ�, �� LCS�� �̿��� ��������.
// ��ȭ���� ������ ����.

// if(i == 0 || j == 0)
//    board[i][j] = 0;
// else if(A[i] == B[j])
//    board[i][j] = board[i + 1][j + 1] + 1;
// else 
//    board[i][j] = 0;

// �ٸ� �����̵� �����츦 �̿��� �� ���� Ǯ�̰� �����ߴ�.
// �ڼ��� ������ �ּ����� �����.

int board[4001][4001] = { 0 };
string A, B;

void MakeAnswer()
{
    // LCS�� �������� �˰��� ����.
    int Asize = A.size(), Bsize = B.size();
    int answer = 0;
    // �� A�� B�� ���̸�ŭ ��ȸ�ϸ� �� ��ȭ���� �����Ѵ�.
    // �ٸ� �ֽô��� 0���� �ʱ�ȭ�Ͽ� ��ȭ�Ŀ��� �� �� ������ �����Ҽ� �ִ�.
    for (int i = 0; i < Asize; ++i)
        for (int j = 0; j < Bsize; ++j)
        {
            if (A[i] == B[j])
            {
                board[i + 1][j + 1] = board[i][j] + 1;
                answer = max(answer, board[i + 1][j + 1]);
            }
            else
            {
                board[i + 1][j + 1] = 0;
            }
        }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> A >> B;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}