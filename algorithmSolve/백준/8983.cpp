#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Ǯ��. 
// ũ�� ����� �ʾҴ�. ���� Ǭ 17609�� ����ó�� ���� �ϳ��� ¥���� �ϴ� ������. ���� ������ ��ġ�� �ִ�
// 10���� �־����� ������ �ָԱ��������� �������ڸ� 10�� * 10������ �ִ� 100���� ���귮�� �ʿ�� �ϴµ�
// �̷��� �ð��ʰ��� �ɸ���. ���� �̰� �ϳ��� ������ �ذ��ؾ� �Ѵ�. �Ʒ� Ǯ�̴� �̺� Ž���� ����Ͽ���.
// ���� ������ y���� ��� 0�̱� ������ x���� �����ϸ� �Ǵµ� ����� ��ġ�� ������ ���¿��� �������� ��ġ��
// �޴´�. �̶� ������ x������ ���� ����� ����� x���� ã�´�. lower_bound�� upper_bound�� ũ�� ����� ����.
// �߿��Ѱ� ���� ����� ���ʰ� ������ ��븦 ã�� ���̴�. ���� �� ������ �Ÿ��� ���ϰ� �̰��� L���� �۰ų� ũ�ٸ�
// ��Ÿ����� �����ϴ� ���̴�.

// �ڼ��� ������ �ּ����� �����.

vector<int> board;
int M, N, L;

// ������ y���� ����� ����. �� ����� y���� 0�̱� �����̴�. 
// �� ������ ��ġ���� x���� ����� x���� ���Ͽ� ���� ����� ��븦 ã�´�. 
// �� ������ �Ÿ��� ���Ͽ� ��Ÿ����� ����ִ��� Ȯ���Ѵ�.

// idx��° ���� ��ǥ���� x, y�� ������ �Ÿ��� ���ϴ� �Լ�.
bool FindRange(int idx, int x, int y)
{
    // ���� �ε������� ����ٸ� �����Ѵ�.
    if (idx < 0 || idx >= M)
        return false;

    return L >= abs(board[idx] - x) + y;
}

void MakeAnswer()
{
    // �̺�Ž���� ���� ����.
    sort(board.begin(), board.end());
    int x, y, answer = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y;
        // lower_bound�� ���� ����� ������ ��븦 ã�´�.
        int idx = lower_bound(board.begin(), board.end(), x) - board.begin();
        // ���� Ȥ�� ������ ������ �Ÿ��� ���ϰ� ��Ÿ����� �����Ѵٸ� ������ answer�� 1 ������Ų��.
        if (FindRange(idx - 1, x, y) || FindRange(idx, x, y))
            ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N >> L;
    int cur;
    for (int i = 0; i < M; ++i)
    {
        cin >> cur;
        board.push_back(cur);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}