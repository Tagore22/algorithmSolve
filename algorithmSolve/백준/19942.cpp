#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// �㹫�������� ������ ��������. N���� ��� ���� �����ε� ����� �˼� ������, N�� �ִ� 15�ۿ� �ȵǱ⿡
// ���� �˰����� ����ϱ�� �ߴ�. �� ����Ḧ ������ ���� �ʴ��� 2���� �������� ������ ������
// �� ���������� ������� �ּ� ������� �������, �ݾ��� �� ������, �� ������� ��ȣ�� ���������� �� �ռ�����
// Ȯ���Ͽ� �Ź� ���� �����ϸ� �ȴ�. �ʹ� ���� ���ö� �ణ �Ҿ������� �����̾���. �ڽŰ��� ������.

// �ڼ��� ������ �ּ����� �����.

vector<int> answer;
int board[16][5];
const int MAXNUM = 10000;
int N, mp, mf, ms, mv, sum = MAXNUM;

// ���� �˰��� �Լ�.
void Nap(int a, int b, int c, int d, int s, vector<int> cur, int idx)
{
    // ����ġ��. ���� ������ �̹� �ּҰ����� ũ�ٸ� �����Ѵ�.
    if (s > sum)
        return;
    // ���������� �湮������ ���簪�� �ּҰ����� Ȯ���Ѵ�.
    if (idx > N)
    {
        // �ּ� ������� Ȯ���ߴ°�, �� �������� ���������� �ռ��°� Ȯ���ϰ� ���� �����Ѵ�.
        // ������ �̹� �Ź� ����ġ��� Ȯ���ϹǷ� �Ű澲�� �ʾƵ� �ȴ�.
        if ((a >= mp && b >= mf && c >= ms && d >= mv) && (answer.empty() || cur < answer))
        {
            answer = cur;
            sum = s;
        }
        return;
    }
    // ���� ����Ḧ ���� �ʾ��� ���.
    Nap(a, b, c, d, s, cur, idx + 1);
    // ���� ����Ḧ ����� ���.
    cur.push_back(idx);
    Nap(a + board[idx][0], b + board[idx][1], c + board[idx][2], d + board[idx][3], s + board[idx][4], cur, idx + 1);
}

void MakeAnswer()
{
    Nap(0, 0, 0, 0, 0, vector<int>(), 1);
    // �� �κ��� �����ؼ� �ѹ� Ʋ�ȴ�.
    // ���������� ���� ���� ������ ��� -1�� ����Ѵ�.
    if (sum == MAXNUM)
    {
        cout << -1 << '\n';
        return;
    }
    cout << sum << '\n';
    for (auto& num : answer)
        cout << num << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> mp >> mf >> ms >> mv;
    for (int i = 1; i <= N; ++i)
        cin >> board[i][0] >> board[i][1] >> board[i][2] >> board[i][3] >> board[i][4];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}