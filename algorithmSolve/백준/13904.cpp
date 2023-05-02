#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// Ǯ��.
// ���� ������ ���Ĺ�����. �״��� ����� �ʾ����� �ð��� ���� �ɷȴ�.
// ������ ������ ����.

// 1. �ִ��� ���� ���� ������ Ǯ��� �ϱ⿡ �ڿ�������(�־��� �ϼ��� ���� ū������) ������ �������� �ذ��Ѵ�.
// 2. �ִ��� ���� ������ ȹ���ؾ� �ϱ⿡ ���ڰ� ���� ��� ������ ū ������ �����Ѵ�.

// �� ������ �ǰ��Ͽ� �־��� �������� ������ ū������ ������ ���ٸ� ���� �ϼ��� ū ������ �����Ѵ�.
// �� �� ���� �ϼ��� ���ų� �� ū �������� ������ ū ������ �����ؾ� �Ѵ�. �ٸ� �ߺ��� �ǹ̰� ���⿡
// �ѹ� ���õ� ������ �����Ǿ�� �ϴµ�, ���� ������ ó���� �������� ���̱� ������ ���� ���� ���θ� üũ�ϴ�
// bool �迭�� ����� ��ü�Ͽ���. ��, bool ���Ұ� true�� �Ǿ� �ִٸ� �̹� ���õǾ��� �����̱⿡
// �����Ҽ� ���� �Ǵ� ���̴�.

// �ڼ��� ������ �ּ����� �����.

bool check[1000];
pair<int, int> board[1000];
int N, day = 0;

// �������� �����ϴ� �Լ�. ����Ͽ��� ������ ū������, ������ ���ٸ� ���� �ϼ��� ū������ �����Ѵ�.
bool SortFunc(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    if (lhs.second != rhs.second)
        return lhs.second > rhs.second;
    else
        return lhs.first > rhs.first;
}

void MakeAnswer()
{
    sort(board, board + N, SortFunc);
    memset(check, false, sizeof(check));

    int answer = 0;

    while (day > 0)
    {
        for (int i = 0; i < N; ++i)
            // ���� �ϼ����� ũ�ų� ������ ���� ���õ��� ���� �������� ù��°(������ ū������ ���ĵǾ��⿡)
            // ������ �����Ѵ�.
            if (board[i].first >= day && !check[i])
            {
                answer += board[i].second;
                check[i] = true;
                break;
            }
        --day;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i].first >> board[i].second;
        day = max(day, board[i].first);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}