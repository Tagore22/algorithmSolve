#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// �������� ����� �ʾҴµ� �������� 40�۰� �ȵǾ��� ����.
// �Ʒ� Ǯ�� �̿ܿ��� ���� Ǯ�̰� �����ϴµ� ���� ù��°�� �������� ���� �� ������ �������� �迭�� �����Ͽ�
// ������ K��° ������ ���� lower_bound()�� �����Ͽ� �� ù��° ���ҷκ����� �Ÿ��� ����ϴ� ���̴�.
// �ٸ� ���� ��쿡�� ���� 4��¥�� ����ü�� ���� �Ⱦ��� �׳� �Ʒ� ó�� Ǯ����.

// �ڼ��� ������ �ּ����� �����.

struct point
{
    int g;
    int s;
    int b;
};
int N, K;
point board[1000];
point piv;

// �� ���� ���ϴ� �Լ�. ó���� invalid comparator ������ ������.
bool ComparePoint(const point& lhs, const point& rhs)
{
    // �� �޴��� �ٸ��ٸ� ū���� �տ� ���Բ� �����ϵ�, ��� ���ٸ� �����Ѵ�.
    // Ȯ������ ����� �ȳ��µ� �������� ���� ��� false ������ ���⵵.
    if (lhs.g != rhs.g)
        return lhs.g > rhs.g;
    else if (lhs.s != rhs.s)
        return lhs.s > rhs.s;
    else if (lhs.b != rhs.b)
        return lhs.b > rhs.b;
    else
        return false;
}

void MakeAnswer()
{
    // ���غ��� �� ���� �����Ѵ�.
    sort(board, board + N, ComparePoint);
    int answer = 1;
    // �迭�� ��ȸ�ϸ� ����� ���� ���߾� ����. ã���� �ϴ� ������ �޴ް� ������ ��찡 ��������
    // ��ȸ�� Ż���Ѵ�. �������� ���� ��� Ȥ�� �׺��� �Ʒ��� ����鸸 ������ �����̴�.
    for (int i = 0; i < N; ++i)
    {
        if (board[i].g == piv.g && board[i].s == piv.s && piv.b == board[i].b)
            break;
        ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num >> board[i].g >> board[i].s >> board[i].b;
        if (num == K)
            piv = board[i];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}