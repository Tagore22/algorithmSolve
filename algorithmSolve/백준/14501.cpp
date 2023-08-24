#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ó���� ���Ĺ������� �˾Ҵµ� N�� �ִ밪�� 15�� �ſ� �۰�, �ܼ��� �ð� Ȥ�� �ݾ��� ũ��� �����ص� 
// Ǯ�� �ָ��ߴ�. �׷��� dp�� ���� ����Ž���� �����ߴ�. ū Ʋ ��ü�� ������ ����.

// 1. 0 ~ N - 1���� ��ȸ�Ѵ�.
// 2. ���� �ϼ� idx�κ��� ���� ����� ������ ������ڸ� �ٽ� ���� ��ȸ�غ���.
// 3. �ִ밪 answer�� ����Ѵ�.

// �ٸ� �Ѱ��� ���������� �־��µ� ���� ���ڷ� �Ѿ�� N�� ���Ƶ� �ȴٴ� ���̴�.
// ���� ��� �־��� ���ð� 1, 1, 10�϶� 0�� �Ϸ縦 �Ἥ 10���� �ް� 1�Ͽ� ����ص� �Ǳ� �����̴�.
// �̷��� ������ BackTrack()�� for���� i <= N�� �Ǿ��� �������� ���� ������ ���� �ɾ���ߴ�.

// �ڼ��� ������ �ּ����� �����.

pair<int, int> board[15];
int dp[15];
int N;

int BackTrack(int idx)
{
    // �� ����� ���Ƕ����� ���� ���� ����.
    // ���� ���� idx�� N�� ���ų� ũ�ٸ� 0�� ��ȯ�Ѵ�.
    if (idx >= N)
        return 0;

    int& ans = dp[idx];
    if (ans != -1)
        return ans;

    ans = 0;
    int plus = board[idx].first;
    // �� ��� 2����� ��������� ������ ���ں��� ��� ��¥�� ��ȸ�Ѵ�.
    // ���� ����� �������� ������ i <= N�� �Ǿ���.
    for (int i = idx + plus; i <= N; ++i)
        ans = max(ans, BackTrack(i) + board[idx].second);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    int answer = 0;
    for (int i = 0; i < N; ++i)
        answer = max(answer, BackTrack(i));

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}