#include <iostream>
#include <set>
#include <string>

using namespace std;

// Ǯ��.
// �� ������ �ǳʶٰ� �ٸ� �������� Ǭ�� ���� ��� Ǫ���� ���� �ȿԴ� ���������� ����. Ǯ� �����̴�.
// DP�� ���, ��Ʈ��ŷ�� �������� ���� �ٸ� ������� ��Ʋ�� Ǯ����ߴ�. ���� ������� K���� ���� ��� �ϳ��� ������
// ����µ� �װ��� �̹� �����Ѵٸ� �����ؾ��ϱ� �����̴�. �ٸ� ����� �ִ� ���� 1�� - 1�̱� ������ int��
// DP�迭�� ����� ����� Set<>�� ����ؾ��ߴ�.

// �ڼ��� ������ �ּ����� �����.

set<string> dp;
bool check[10] = { false, };
int board[10];
int N, K, answer = 0;

// ��� ������ ã�ƺ��� ����Լ�.
void CalNum(int num, string str)
{
    // K���� ��� ����ٸ�.
    if (num == K)
    {
        // ���� ������ ������ ���� �ʾҴٸ�.
        if (dp.find(str) == dp.end())
        {
            // ������ answer�� 1 �����ϰ�, set<>�� ���� ������ �߰��Ѵ�.
            ++answer;
            dp.insert(str);
        }
        return;
    }

    // ��� ����(ī��)�� ��ȸ�Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        // ���� ���� ���� ����(ī��)���
        if (!check[i])
        {
            check[i] = true;                             // ���������� �����ϰ�
            CalNum(num + 1, str + to_string(board[i]));  // ������° ī�带 ����.
            check[i] = false;                            // ���� ���������� ������Ų��.
        }
    }
}

void MakeAnswer()
{
    CalNum(0, "");
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}