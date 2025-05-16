#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���� �� �ִ� ��� ���������� B���� �����鼭 0���� �������� �ʴ� ���� ū ���� ���ϴ� ������.
// �� �ڸ��� ��Ʈ��ŷ�̳� DFS�� ���ؼ� ���� ���� ���� ������ ������ STL�� ������ �� �ô� 
// next_permutation()�� �������� �� �����ϰ� �ڵ带 © �� ���� ���̹Ƿ� ����غ��Ҵ�.

vector<int> board;
int A, B;

int main()
{
    cin >> A >> B;
    while (A > 0)
    {
        board.push_back(A % 10);
        A /= 10;
    }
    sort(board.begin(), board.end());
    int answer = -1;
    while (next_permutation(board.begin(), board.end()))
    {
        int sum = 0;
        for (int i = 0; i < board.size(); ++i)
            sum = sum * 10 + board[i];
        if (board[0] == 0 || sum >= B || sum <= answer)
            continue;
        answer = sum;
    }
    cout << answer << '\n';
    return 0;
}