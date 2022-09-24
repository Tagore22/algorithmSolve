#include <iostream>
#include <cstring>

//���ڸ��� 1���̳��� 2���� ���� �߰��ذ��� ����� �ִ� N�ڸ� ���� ���� ���ϴ� �����̴�.
//����Ž������ Ǯ�⿣ �뷫 9 * 2�� 99���������� �ü� �ֱ⿡ DP�� ����ؾ��ϴµ�
//ó���� ���̿� �� ��ġ�� ���� ĳ���߾��µ�, �׷��� �� ���ڸ��� ������ ������ä ĳ���� �Ǿ�
//�������� ������� ���ߴ�. �׷��� ��Ʈ����ũ�� ����ؾ� ������ �ִ� 0~9���� 10���� ��Ʈ����ŷ �ϸ� �Ǵ�,
//������ ������.
//P.S ��� ���� ���ڸ����� �ڽź��� 1�� ũ�ų� �۾ƾ������� ��Ʈ�� ���ٴ°� �ݵ�� ���±��� ���� ���� �����Ҽ��ۿ� ����.
//���� ��� ��Ʈ����ũ�� ������� �ʴ´ٸ� �Ȱ��� 3��° �ڸ��� 7�� �ִ´ٸ�
//5 6 7 �� 9 8 7 �� �����Ҽ��� ����. ������ ��Ʈ����ũ�� ����Ѵٸ� 3���� ĳ�̰����� ������ ������ �����ϴ�.

using namespace std;

const int DIVNUM = 1000000000;
long long cashe[100][10][1 << 10];
int N;

int Cal(int idx, int now, int bit) //���� ��ġ��, ������, ��Ʈ����ũ
{
    if (idx == N - 1)
        return bit == (1 << 10) - 1 ? 1 : 0;

    long long& ans = cashe[idx][now][bit];
    if (ans != -1)
        return ans;
    ans = 0;

    int next = now + 1;
    if (next < 10)
        ans += Cal(idx + 1, next, bit | (1 << next));

    next = now - 1;
    if (next > -1)
        ans += Cal(idx + 1, next, bit | (1 << next));

    return ans %= DIVNUM;
}

void MakeAnswer()
{
    if (N < 10)
    {
        cout << 0 << '\n';
        return;
    }
    long long answer = 0;
    for (int i = 1; i < 10; ++i) //0���� ���۵Ǵ� ���� �����Ҽ� ����. �׷��Ƿ� �������� 1.
    {
        answer += Cal(0, i, 1 << i);
        answer %= DIVNUM;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}