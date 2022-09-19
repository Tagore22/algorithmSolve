#include <iostream>
#include <cstring>

using namespace std;

//�׸���� Ǯ�� �ָ��Ͽ� �ᱹ ����Ž���� �ؾ��ϳ� �ִ� ������ 3�� 1000�����̴�. �ð����� ������ �Ұ����ϴ�
//DP�� �̿��ؼ� �� �ڸ��� 3���� ��θ� ����ϴ� ����� ���� ���س���.

int N;
const int DIVNUM = 1000000;
int cashe[1001][1001][2][3];

int Cal(int idx, int O_num, int L_num, int A_num)
{
    if (L_num >= 2 || A_num >= 3)
        return 0;
    if (idx == N)
        return 1;

    int& ans = cashe[idx][O_num][L_num][A_num];
    if (ans != -1)
        return ans;

    ans = Cal(idx + 1, O_num + 1, L_num, 0) + Cal(idx + 1, O_num, L_num + 1, 0) +
        Cal(idx + 1, O_num, L_num, A_num + 1);

    return ans %= DIVNUM;
}

void MakeAnswer()
{
    cout << Cal(0, 0, 0, 0) << '\n';
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