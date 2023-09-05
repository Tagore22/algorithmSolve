#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ���ͺ��� �׸����ϰ� Ǯ�� ������ ������ �����δ� �׷��� �ʴ�.
// ���� ����Ž���� ����ؾ��Ѵ�. �ٸ� ���� ����Ž���� �Ҷ����� �ߺ��� ���� ����
// dp�� ���� ����ϳ� �̹� ������ �ߺ��� �������� �ʱ⿡ dp�� ������� �ʴ´�.
// Ǯ�̴� �ǿܷ� �����ѵ� �ִ� N���� ������ �ߺ��� �����Ͽ� �Ѱ��� ��󰡸� �ȴ�.
// |a[0] - a[1]| + |a[1] - a[2]| ... |a[N - 2] - a[N - 1]|�� �̷�� ��ȭ�Ŀ� �� ������� �ϳ���
// �� ���� ��� �� ����� �ִ밪�� ���ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

// P.S solved�� ���� �˰����� ���� Ǯ�̿��� BackTrack()�� �Ű������� 2������. �ٵ� ���� �����ϸ� ����
// ù��° �Ű����� idx�� �ʿ��� �ٽ� Ǯ���µ� �ӵ��� ������ ��������. ���� ������ �ӵ����̴� �Ű澲��
// ���ƾ߰ڴ�. �ͽ���������.

int board[8];
bool check[8];
int N;

// ��� ������ �����ϴ� �Լ�.
int BackTrack(int prev_num)
{
    int ans = 0;
    // 0 ~ N - 1��° ���Ҹ� ��ȸ�ϸ� ���� ������� ���� ���Ҹ� ã�� ���� ���� �����غ���
    // ���ư���. ������� �ִ밪�� ��ȯ�Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        if (check[i])
            continue;
        check[i] = true;
        ans = max(ans, BackTrack(i) + abs(board[prev_num] - board[i]));
        check[i] = false;
    }
    return ans;
}

void MakeAnswer()
{
    memset(check, false, sizeof(check));
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        check[i] = true;
        answer = max(answer, BackTrack(i));
        check[i] = false;
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
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}