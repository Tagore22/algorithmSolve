#include <iostream>

using namespace std;

//�־��� �� M,N,x,y�� ������ M�� ��� + x�� N�� ��� + y�� �������� �����Ѵٸ� �� ���� ����ϰ�, ���ٸ� -1�� ����ϴ� �����̴�.
//�ٸ� M�� N�� ����� ���Ҷ� �� �ִ밪�� �˾ƾ��ϴµ� �� �ִ밪�� �� �� M�� N�� �ּҰ���� ���� �˼� �ִ�.
//ó���� M�� ����� N�� ����� �ִ밪���� ��� ���Ͽ� �迭�� ��ȸ�ϸ� ���� ��츦 ã�Ҵµ� �̻��ϰ� ���� ������ �ʾƼ�
//M�� ������Ű�� N���� ���������� y�� ������ ���� �ٲپ���. �޸𸮴� �� ���� ���� �ϰ� ���굵 ���⿡ �ӵ��� �� ������.

int T, M, N, x, y;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int Cal()
{
    const int MAX_NUM = lcm(M, N);

    for (int i = x; i <= MAX_NUM; i += M)
    {
        int check = i % N == 0 ? N : i % N;
        if (check == y)
            return i;
    }

    return -1;
}

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        cin >> M >> N >> x >> y;
        cout << Cal() << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}