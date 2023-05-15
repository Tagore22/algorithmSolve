#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// DP��� �з��Ǿ� ������ ��ǻ� LIS�� �ش��ϴ� �����̴�.
// �迭�� �����Ҷ� �ʿ��� �ּ����� ���� ���ϴ� ���� �̹� LIS�� �����ϱ� �����δ�.
// �ٸ� ������ Ǯ��������� �ұ��ϰ� ����� �ȳ� �ᱹ ã�ƺô�.
// ���� ����. ������ ���Ұ� - LIS�̴�.

// �ڼ��� ������ �ּ����� �����.

vector<int> board;
int N;

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
    {
        int now;
        cin >> now;

        // ���� ���Ұ��� board�� ���� ū��(���ذ�)���� ũ�ų� board�� ����ٸ� �׳� �����Ѵ�.
        if (board.empty() || board.back() < now)
            board.push_back(now);
        // �׷��� �ʴٸ� ���� ��ġ���� ã�Ƴ��� �����.
        else
            *lower_bound(board.begin(), board.end(), now) = now;
    }

    cout << N - board.size() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}