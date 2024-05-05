#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ������ ����ϱ淡 Reverse()�� ����ϴ��� �˾Ҵµ� ���� �ƴϾ���. ���� �� 4���� ���� �迭������ ������Ѿ� �Ѵ�.
// 1. �� ó������ i������.
// 2. k���� j����.
// 3. i���� k������.
// 4. j + 1���� ����������.

// �׷��� ������ Ǯ���� �����Ϳ� �̻��� �ִٴ� ������ ����. ������ ��ü�� ���� �ʾҴµ� ���Ҹ��ΰ� �ϰ� �迭�� Ǯ�����
// ������ ����. �����غ��� N, M�� ������ �ִ� 100��������. �� ���� 10������ �˾ҳ�. ������ �� ����. ���� ������ ����ġ ������ ����.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, i, j, k, idx;
    cin >> N >> M;

    vector<int> answer, board;
    for (int iter = 0; iter <= N; ++iter)
        answer.push_back(iter);

    for (int iter = 0; iter < M; ++iter)
    {
        board = answer;
        idx = 0;
        cin >> i >> j >> k;
        for (int cur = 0; cur < i; ++cur)
            answer[idx++] = board[cur];
        for (int cur = k; cur <= j; ++cur)
            answer[idx++] = board[cur];
        for (int cur = i; cur < k; ++cur)
            answer[idx++] = board[cur];
        for (int cur = j + 1; cur <= N; ++cur)
            answer[idx++] = board[cur];
    }
    for (int idx = 1; idx <= N; ++idx)
        cout << answer[idx] << ' ';
    cout << '\n';
    return 0;
}