#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// sort()�� ���� ������ �Ǵ� �Լ��� ����� ���� �߿��� �Լ��̴�.
// ����, ����, ����, �̸� ������ �񱳸� �ϰ� �Ǵµ� ���� �񱳵Ǵ� �κ���
// ���� �ʴٸ� �� �ܰ迡�� �ٷ� �񱳰� �ǰ� �׷��� �ʴٸ� ���� �� ������ �Ѿ��.
// �񱳸� ������ ���� ������� �̸��� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

// �� ������� ǥ���ϴ� ����ü.
struct person
{
    string name;
    int l;
    int e;
    int m;
};

person board[100000];
int N;

// ������ ������ �Ǵ� �Լ�. ����, ����, ����, �̸������� ���ϵ�
// ���� �� �񱳰��� �ٸ��ٸ� �񱳰� �����ϰ� ���ٸ� ���� �� ������� �Ѿ �ٽ� ����.
bool ComparePerson(const person& lhs, const person& rhs)
{
    if (lhs.l != rhs.l)
        return lhs.l > rhs.l ? true : false;
    else if (lhs.e != rhs.e)
        return lhs.e < rhs.e ? true : false;
    else if (lhs.m != rhs.m)
        return lhs.m > rhs.m ? true : false;
    else
        return lhs.name < rhs.name ? true : false;
}

void MakeAnswer()
{
    // �� �Լ��� �̿��Ͽ� �������� ������� �̸��� ����Ѵ�.
    sort(board, board + N, ComparePerson);
    for (int i = 0; i < N; ++i)
        cout << board[i].name << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].name >> board[i].l >> board[i].e >> board[i].m;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}