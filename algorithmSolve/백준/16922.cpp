#include <iostream>

using namespace std;

// Ǯ��.
// ��� ��츦 �� ����غ��� ��Ʈ��ŷ �����̴�. ������ �����ϴ� idx���� ����ؼ� ������ �ߺ��Ǵ°� ���� �ܼ�
// ��ͷθ� Ǯ���� �ߴµ� ��𼱰� �ߺ��� �ȴ�. �ᱹ ã���� ������ bool �迭�� �̿��Ͽ� �ɷ������ �ߴ�.
// ���߿� �ѹ� �� �����غ��ƾ߰ڴ�.

int N, answer = 0;
int board[4] = { 1, 5, 10, 50 };
bool check[10001] = { false, };

void BackTrack(int idx, int num, int sum)
{
    if (num == N)
    {
        if (!check[sum])
        {
            ++answer;
            check[sum] = true;
        }
        return;
    }

    for (int i = idx; i < 4; ++i)
        BackTrack(i, num + 1, sum + board[i]);
}

int main()
{
    cin >> N;
    BackTrack(0, 0, 0);

    cout << answer << '\n';
    return 0;
}