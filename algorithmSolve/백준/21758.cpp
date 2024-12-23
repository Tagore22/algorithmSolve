#include <iostream>

using namespace std;

// Ǯ��.
// ô ���⿡�� �����غ����� ������ �������� ������. �̹��� ���ݴ� �����ϰ� Ǯ��Ҵ�. ó������
// ��� ��츦 ���������ϳ� �����ߴ�. ������ 10������ 3���� ���� ���� 10C3���� �ʹ� ���Ҵ�.
// �ִ밪�� ���ϱ� ���ؼ��� ������ ���� 3���� ��찡 �����Ѵ�.

// 1. ������ �� ����, �߾� ��򰡿� ������ ������ �� �����ʿ� ������.
// 2. ������ �� ������, �߾� ��򰡿� ������ ������ �� ���ʿ� ������.
// 3. ������ �� �����ʰ� �� ���ʿ� ������ ������ �߾� ��򰡿� ������.

// �ֳ��ϸ� ��� ���� ����̸� �ִ밪�� ���ؾ� �ϱ� ������ ���� ���ڶ����� �� ���� ���������ϱ� �����̴�.
// ���� �� 3���� ��츦 �����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[100000], sum_arr[100000];
int N, sum = 0;

void MakeAnswer()
{
    int answer = 0;
    // ������ ����, �߾��̰� ������ ������
    int left = sum - board[0];
    for (int i = 1; i < N - 1; ++i)
    {
        int ans = left - board[i];
        ans += sum - sum_arr[i];
        answer = max(answer, ans);
    }
    // ������ ������, �߾��̰� ������ ����
    int right = sum - board[N - 1];
    for (int i = N - 2; i >= 1; --i)
    {
        int ans = right - board[i];
        ans += sum_arr[i - 1];
        answer = max(answer, ans);
    }
    // ������ ����, ������ �߾�
    for (int i = 1; i < N - 1; ++i)
    {
        int ans = sum - board[0] - board[N - 1] + board[i];
        answer = max(answer, ans);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        sum += board[i];
        sum_arr[i] = sum;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}