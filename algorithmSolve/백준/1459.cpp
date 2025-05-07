#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// BFS�ε� ������ Ǯ �� ���� �� ������ ���� �ʹ� ũ��. ���� �� ������� ���� ����� �Ŀ� 
// �ּҰ��� ���ؾ��ߴ�. �� ����� ������ ����.

// 1. ����, ���ηθ� ���� ���
// 2. �밢�����θ� ���� ���
// 3. �� ����� ȥ���ϴ� ���

// �����ؾ��� ���� �밢�����θ� �� ���ε� ¦����ŭ�� �̵��� �����ϴٴ� ���̴�. ���� �� �Ÿ���
// Ȧ���϶��� �밢������ �ִ��� �̵��ϰ� �������� 1�� ������� �̵��ϰԲ� �����Ѵ�.
// �̰��� �Ʒ� CalMinWay()�� �����Ͽ���. 3�� ����� X�� Y�� �ּҰ���ŭ �밢������ �����̰�
// ������ �Ÿ��� �ٽ� 1���� 2�� ����� �ּҰ��� �����ָ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

long long X, Y, W, S;

// �Ÿ� len��ŭ �̵��Ҷ� �ּ� ����� ���ϴ� �Լ�.
long long CalMinWay(long long len)
{
    // 1�� ������� �̵��� ��.
    long long OnlyStraight = len * W;
    // 2�� ������� �̵��� ��.
    long long OnlyDiagonal = len / 2 * 2 * S + len % 2 * W;
    return min(OnlyStraight, OnlyDiagonal);
}

void Solve()
{
    long long FirstWay = CalMinWay(X + Y);
    long long Commonlen = min(X, Y);
    // 3�� ������� �̵��� ��.
    long long SecondWay = Commonlen * S;
    SecondWay += CalMinWay(X + Y - Commonlen * 2);
    long long answer = min(FirstWay, SecondWay);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> X >> Y >> W >> S;
}

int main()
{
    Input();
    Solve();
    return 0;
}