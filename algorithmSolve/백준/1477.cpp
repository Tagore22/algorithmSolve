#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Ǯ��.
// ��ư� �����ؼ� ���� ��̴�. �Ű� ���� Ž���� ���� �Ÿ����� �ִ°ͱ����� ����� �ʰ� �����س�������
// �� ���� �Ѱ��� ������ �ްԼҸ� ����� ������ �������� �ʾҴ�. 0���� �Ÿ�����ŭ + �ؼ� �ؾ��ϳ� �̷�����
// ������ ����. ��������δ� �� �ްԼ� ������ ������ ���� �Ÿ������� ������ ����� �ִ� �������� ������ �Ǿ���.

// �ڼ��� ������ �ּ����� �����.

int N, M, L;
vector<int> board;

// �Ÿ��� num���� M���� �ްԼҸ� �߰������� ����� �ִ��� Ȯ���ϴ� �Լ�.
bool CheckFunc(int num)
{
    int ans = 0;
    // �� �ްԼҰ��� ���̰����� ��ȸ�ϸ� �߰������� ����� �ִ� �ްԼ��� ���� ���Ѵ�.
    for (int i = 0; i < board.size() - 1; ++i)
    {
        int dist = board[i + 1] - board[i];
        ans += dist / num;
        // ���� ���������� 0�̶�� �̹� ������ �ްԼұ��� ���ԵǹǷ� �Ѱ��� ����.
        ans = dist % num == 0 ? ans - 1 : ans;
    }
    return ans <= M;
}

void MakeAnswer()
{
    // �� �ްԼҰ��� �Ÿ��� ���ϱ� ���� 0�� L�� �߰����ش�.
    board.push_back(0);
    board.push_back(L);
    sort(board.begin(), board.end());

    int l = 1, r = L;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (CheckFunc(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    // �� �κп��� ���� ��ž���. �����غ��� �����Ѱ��ε� ���� CheckFunc �Լ��� �����Ѵٸ� 
    // r�� r - 1�� �Ǿ� �ٽ� while������ ���ư���. �� ���¿��� ������ r�̸�, ������
    // r�� l�� �����Ҷ����� �����ߴٸ� r�� �ٽ� r - 1��, �����ߴٸ� �� ���� r���� r + 1��
    // ������ �ȴ�. ��������� r + 1�� ����ϸ� �ȴ�.
    cout << r + 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> L;
    for (int i = 0; i < N; ++i)
    {
        int here;
        cin >> here;
        board.push_back(here);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}