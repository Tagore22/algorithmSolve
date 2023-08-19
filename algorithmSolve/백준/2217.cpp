#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ��ĸ� �˸� ������ �����׸Ա��� ������.
// ������������ ������ �Ͽ� ������� �������� ���Ҽ� * ���� ������ ��ƿ�� �ִ� �߷��� ��� ���Ҹ� ��ȸ�ϸ�
// ������ �� �ִ밪�� ����ϸ� �ȴ�. �ٸ� ���� ��� 10������ ������ �߷��� ��ƿ�� �ִ� ���� �ϰ�� 
// 10���� - 1���� ���ǹ��ϰ� ����ؾ��ϳ� �ִ� 10�����̹Ƿ� �����ص� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[100000];
int N;

void MakeAnswer()
{
    // ��� ���ҵ��� ������������ �����Ѵ�.
    sort(board, board + N);
    int answer = 0;

    // ��� ���ҵ��� ��ȸ�ϸ� ���� �߷� * ������� �������� ���Ҽ��� ���Ͽ� �ִ밪�� ���Ͽ� �ִ밪�� �����Ѵ�.
    for (int i = 0; i < N; ++i)
        answer = max(answer, board[i] * (N - i));

    cout << answer << '\n';
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