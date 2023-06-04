#include <iostream>
#include <algorithm>

using namespace std;

// 14225���� ���� ����ȭ�� Ǯ��.
// 0���� �����ϴ°� ��������� ������ �������� Ǫ�� ����̴�.
// ������ �̷� ����� Ǯ�̹���� �ô� �� ������ �̹��� 2��° ���� ���̶�
// ����� ���� �ʾҴ�. ������ �����ϱ⿡ �� ����صξ�߰ڴ�.

int board[20];
int N;

void MakeAnswer()
{
    sort(board, board + N);
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        // �̹� ���Ұ��� ���� ������ 2�̻� ũ�ٸ� ���� �� + 1�� ���� ���Ҽ� ����.
        if (board[i] > answer + 1)
            break;
        // ���簪�� �������鼭 1 ~ ���簪������ ��� ���� �κм����� ���Ҽ� �ִ�.
        answer += board[i];
    }
    cout << answer + 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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