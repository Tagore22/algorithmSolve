#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//����� DPǮ��. �����Դ� ���� �������̳� �뷮�� �� ���� ���, �� ������

//Ǯ��
//N�� ���� �ʴ� ��� ���������� ���س���, num���� ���� �ִ� ��� ����� ������ ��������. 0�� �Ǹ� ���̻� �Լ��� ȣ���Ҽ� ���⿡ 0�� ��ȯ�ϸ�
//DP�� ����Ͽ� �ִ� 10���� ���귮�� ������.

vector<int> board, cashe;
int N;

int DP(int num)
{
    if (num == 0)
        return 0;

    int& ans = cashe[num];
    if (ans != -1)
        return ans;

    ans = 100001;
    int idx = distance(board.begin(), upper_bound(board.begin(), board.end(), num));
    for (int i = 0; i < idx; ++i)
        ans = min(ans, DP(num - board[i]) + 1);

    return ans;
}

void MakeAnswer()
{
    int sqrt_num = sqrt(N);
    for (int i = 1; i <= sqrt_num; ++i)
        board.push_back(i * i);

    int answer = DP(N);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cashe.resize(N + 1, -1);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}