#include <iostream>

using namespace std;

// Ǯ��.
// �������� ���� ���� �Ⱦ��ϴ� ������ ������.
// �� ������ ���ſ� Ǯ���� CCW�� ������� �ϰ� �ִ�.
// ��� ���п��� �ٸ� ������ �� ���� CCW�������� ���� �����ų� 0�̶�� �� ������ �����Ѵ�.
// �ٸ� �Ʒ��� ���ÿ� ����

// �� �� 

// �ѿ��� ���� �� ���� CCW�������� ���� �������� ������ �� ������ �������� �ʴ´�.
// �׷��� ������ �ϳ��� ���п����� �˻����� �ʰ� �ٸ� ���п����� �˻縦 �غ����Ѵ�.
// �� �˻��� ����� first�� second��� �Ҷ� ��� ���� ������ ����.

// 1. first == second == 0
// �� �� ���п��� �ٸ� ������ CCW������ ��� 0�� ����̴�.
// �̷������� 2���� ���� �ٽ� ���������µ� 
// 1-1. �� ������ �������� : �������� �������� ��쵵 ������ �����Ѵٰ� ������ 1�� ����Ѵ�.
// 1-2. �� ������ ������������(ex �� �� ) : 0�� ����Ѵ�.

// 2. first > 0 || second > 0
// first Ȥ�� second ���� �ϳ��� 1�� �Ǿ��ٴ°� ���ʿ��� CCW���� 1, 1 Ȥ�� -1, -1�� ���ͼ�
// ���� ���� 1�� �Ǿ��ٴ� ���ε� �̰� � ���� A���� B�� CCW������ ���� ���� �Ѱ��� ���� �ִٴ� ���̱⿡
// �����Ҽ� ����.

// 3. ������ ���
// ���� ������ ��� ��� �����Ѵ�.

// ����, �� ��ǥ�� ���� �ִ� 100���� ���ϱ� ������ int���� ����� �־�
// long long ���� ����ؾ��Ѵ�.

// �ڼ��� ������ �ּ����� �����.

pair<long long, long long> board[4];

// CCW ���� �Լ�.
int CheckCCW(const pair<long long, long long>& a, const pair<long long, long long>& b, const pair<long long, long long>& c)
{
    long long result = (b.first - a.first) * (c.second - b.second) - (b.second - a.second)
        * (c.first - b.first);

    if (result > 0)
        return 1;
    else if (result < 0)
        return -1;
    else
        return 0;
}

int CalAnswer()
{
    // �� ����Ͽ��� ���ʿ����� �� ����� �Ǵ��Ҽ� ���⿡ �ΰ��� ���� ��θ� �������� ��� CCW�� �� 4�� ȣ���Ѵ�.
    int first = CheckCCW(board[0], board[1], board[2]) * CheckCCW(board[0], board[1], board[3]);
    int second = CheckCCW(board[2], board[3], board[0]) * CheckCCW(board[2], board[3], board[1]);

    // �� ����� ����.
    if (first == 0 && second == 0)
    {
        if (board[0] > board[1])
            swap(board[0], board[1]);
        if (board[2] > board[3])
            swap(board[2], board[3]);
        if (board[1] < board[2] || board[0] > board[3])
            return 0;
        else
            return 1;
    }
    else
    {
        if (first <= 0 && second <= 0)
            return 1;
        else
            return 0;
    }
}

void MakeAnswer()
{
    int answer = CalAnswer();

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}