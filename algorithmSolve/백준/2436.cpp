#include <iostream>
// #include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// Ǯ��.
// ������ ���� �������⿡ ��Ȯ���� �ʾҴ�. �׷��� �־��� ������ �ϳ� �۱� ������ �غ��Ұ� �����ߴ�.
// ������ڸ� � �� A�� �ּҰ������ ������ ������ ��� A�� ����� �ǰ�, � �� B�� �ִ������� ������ ����
// ��� B�� ����� �ȴ�. ������ A�� ������� ������ B�� ����麸�� Ȯ���� ���⿡ �̰� �̿��ؾ��ߴ�. ����
// A�� ��� ������� vector�� �����ϰ�, �� ������ 2���� �ߺ����� �ʰ� ��� �ִ������� �ּҰ������ Ȯ���Ͽ�
// �� ���� ���� ���� ���� ������ ����Ѵ�. �ϳ� �����ؾ������� �ּҰ������ ���Ҷ� �� ���� ���ϴµ� �ԷµǴ� ����
// �ִ밪�� 1���̱� ������ int���� ����� �־� long long������ ĳ������ �ʿ��ϴ�.

// �ڼ��� ������ �ּ����� �����.

vector<int> board;
int A, B;

// �ִ������� ���ϴ� �Լ�.
int GCD(int l, int r)
{
    if (r == 0)
        return l;
    return GCD(r, l % r);
}

// �ּҰ������ ���ϴ� �Լ�. ����Ѵ�� int���� ����� �ֱ� ������ ù��° ����
// long long���� �޴´�. �ٵ� GCD�� ȣ���� �ߺ��Ǳ⿡ �ؿ����� �׳� �μ��� �� / �ִ������� �ߴ�.
// �̰� �� ��������.
int LCM(long long l, int r)
{
    return l * r / GCD(l, r);
}

int main()
{
    cin >> A >> B;
    // �����佺�׳׽��� ü�� �����Ͽ� B�� ��� ����� ���ݴ� ������ ���Ѵ�.
    int sqrtnum = sqrt(B);
    for (int i = 1; i <= sqrtnum; ++i)
    {
        if (B % i == 0)
        {
            board.push_back(i);
            board.push_back(B / i);
        }
    }
    // �������� ������ �־�����. �ٽ� �����غ��� ������ ��� ��ȸ�� �ؾ��ϱ⿡ ������ �ʿ����.
    // sort(board.begin(), board.end());
    // �� ���� �ּҰ��� ���ؾ��ϱ⿡ ���������ϰ� ū���� ������ answer�� �ʱ�ȭ�Ѵ�.
    pair<int, int> answer = make_pair(100000000, 100000000);
    // ��� ������ ��ȸ�ϸ� �ּҰ������ �ִ������� ��ġ�ϴ� ���� ���� ������ ã�´�.
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = i; j < board.size(); ++j)
        {
            // �ִ�����.
            int g = GCD(board[i], board[j]);
            // �ּҰ����. ����Ѵ�� �μ��� ���� int���� ����� �ֱ⿡ ù��° ���� long long���� ĳ������.
            int l = static_cast<long long>(board[i]) * board[j] / g;
            if (g == A && l == B && board[i] + board[j] < answer.first + answer.second)
            {
                int first = min(board[i], board[j]);
                int second = max(board[i], board[j]);
                answer = make_pair(first, second);
            }
        }
    }
    cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}