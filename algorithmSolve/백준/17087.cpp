#include <iostream>

using namespace std;

// Ǯ��.
// ��� ������ ��Ʈ��ŷ ���� �ɷ� �����ϰ� Ǯ��� �Ұ� ������ �ǻ��� �׷��� �ʴ�.
// ���� ��ġ +- D������ D�� �ִ밪�� ���ؾ� �ϴµ� �̴� �ٸ� ���� D��ŭ �̵�������
// ��� ������� ������ �ִٴ� ���̸� �̰��� ���� ��ġ���� ����������� ��ġ�鿡 ����
// ��������� ��Ÿ����. ���� ���� ū D�� ���ؾ� �ϹǷ� ��������� ��������� �Ÿ�����
// �ִ� ������� ���ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[100001];
int N, S;

// �� �� lhs�� rhs�� �ִ������� ���ϴ� �Լ�.
int GDC(int lhs, int rhs)
{
    if (rhs == 0)
        return lhs;
    return GDC(rhs, lhs % rhs);
}

void MakeAnswer()
{
    // ù��° �������� �Ÿ��� �����Ѵ�.
    int answer = abs(S - board[0]);
    // ��� ��������� �Ÿ����� �ִ� ������� ���Ѵ�.
    for (int i = 1; i < N; ++i)
        answer = GDC(answer, abs(S - board[i]));

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}