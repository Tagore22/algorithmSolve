#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �����̷� ������. �� ������ ���� �ּ��� ���Ҷ� ���ϴ� ����� ��� ������.
// �ͼ�ġ ���� �о߿��� �� �����ߴµ� �����ߴ�. ��ǻ� ��Ʈ��ŷ�̶� ����ߴ�.
// 3�� �̻��̶�� 3���� ���� �׷��� �ʴٸ� 1���� ��������. �׸���
// �� �ʸӰ��� �������� ��ȯ�ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int dp[1000][2];
int N;

// ���� �ʸ� ���� ����� �����Ͽ� 0�� ��ȯ������ ���� �����ϰ� �ȴ�.
// �׷��Ƿ� �� �ʸӰ��� �������� ����ϸ� �ȴ�.
bool BackTrack(int num, bool isSk)
{
    if (num <= 0)
        return 0;

    int& ans = dp[num][isSk];
    if (ans != -1)
        return ans;

    ans = 0;
    //  num�� 3�̻��� ���.
    if (num >= 3)
        ans |= !BackTrack(num - 3, !isSk);

    ans = !BackTrack(num - 1, !isSk);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    int answer = BackTrack(N, true);
    if (answer)
        cout << "SK" << '\n';
    else
        cout << "CY" << '\n';
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