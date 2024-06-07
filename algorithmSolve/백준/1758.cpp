#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���� ��� ����� �����Ҷ� ���� �ִ밪�� ����ϴ� ������. ���� ������������ �����Ͽ� �ִ��� ������ ���ִ� �����
// �����غ����� ������, ��� �̹��������� ���� �����϶��� 0���� ó���ϱ� ������ �ݴ�� �����ؾ� �Ѵ�.
// ������������ �����Ͽ� �ִ��� ���� ������ ��� �������� 0�� ó���ؾ��Ѵ�. ��, ���ĸ� �����ָ� �ȴ�.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int board[100000];
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    sort(board, board + N, greater<int>());
    long long answer = 0;
    for (int i = 0; i < N; ++i)
        answer += board[i] - i > 0 ? board[i] - i : 0;
    cout << answer << '\n';
    return 0;
}