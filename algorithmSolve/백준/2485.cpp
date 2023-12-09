#include <iostream>

using namespace std;

// Ǯ��.
// ���� Ǯ���� ������ ����ϰ� �ִ������� ���ϴ� ������. �� ���μ����� ��ġ�� �־�����
// ��� ���μ��� ������ �Ÿ��� �����ϰԲ� ����� ���� �ּ������� �߰��ؾ��ϴ� ���μ����� ���� ���ؾ��Ѵ�.
// ��� ���μ��� ������ �Ÿ��� ������� ���Ҽ� �ִµ� ���μ��� �ּ������� �߰��ϱ� ���ؼ��� �ִ� �������
// ã�ƾ� �Ѵ�. �� �Ÿ��� ������ ���� �Ÿ� / �ִ� ����� - 1�� �ϸ� �� ���μ��� ���̿� �߰��Ǵ� ���� ���Ҽ�
// ������ �� ������ ������ ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[100000];
int N;

// �ִ� ������� ���ϴ� �Լ�.
int GDC(int lhs, int rhs)
{
    if (rhs == 0)
        return lhs;
    return GDC(rhs, lhs % rhs);
}

void MakeAnswer()
{
    // ������ �Ÿ��� ���� 0��, 1�� ���Ұ��� �̸� �����´�.
    int here = board[0], next = board[1];
    int dist = next - here;
    here = next;
    // ���� ��� ���μ����� ��ȸ�ϸ� �� ���μ��� ���� �Ÿ��� �ִ������� ã�´�.
    for (int i = 2; i < N; ++i)
    {
        next = board[i];
        dist = GDC(dist, next - here);
        here = next;
    }
    int answer = 0;
    // �� ����Ͽ��� �߰��ؾ� �ϴ� ���μ��� ���ϴ� ��ȭ����
    // �� ���μ����� ���� �Ÿ� / �ִ� ����� - 1�̴�.
    for (int i = 1; i < N; ++i)
        answer += (board[i] - board[i - 1]) / dist - 1;

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