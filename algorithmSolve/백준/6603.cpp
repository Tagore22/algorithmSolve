#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��. 
// ��Ʈ��ŷ �����̴�. ���� Ǯ���� ������ ����ϰ�
// ���������� ���ĵǾ� ����ؾ��ϱ� ������ 1 ~ K���� ���� ������ �ϳ��� ������ �����鼭
// �� ���� 6���� �Ǿ����� ���� ������ ������ ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[13];
bool check[13];
int K;
const int LAST_NUM = 6;

// ���� ���õ� ������ ����ϴ� �Լ�. ���͸� ����ص� ������ bool �迭�� ������ ����ؾ� �ϱ⿡
// �̷��� bool �迭���� �̿��Ͽ� �����ص� �ɵ��ϴ�.
void ShowAnswer()
{
    for (int i = 0; i < K; ++i)
        if (check[i])
            cout << board[i] << ' ';
    cout << '\n';
}

// ��Ʈ��ŷ �Լ�. ����Ͽ��� ���������� ���ĵǾ�� �ϱ⿡ ���������� �ϳ��� ������ ������,
// �� 6���� ���������� ���� �������� ����Ѵ�.
void BackTrack(int idx, int num)
{
    if (idx == LAST_NUM)
    {
        ShowAnswer();
        return;
    }

    for (int i = num + 1; i < K; ++i)
        if (!check[i])
        {
            check[i] = true;
            BackTrack(idx + 1, i);
            check[i] = false;
        }
}

void MakeAnswer()
{
    while (true)
    {
        cin >> K;
        if (K == 0)
            break;
        memset(check, false, sizeof(check));
        for (int i = 0; i < K; ++i)
            cin >> board[i];
        BackTrack(0, -1);
        cout << '\n';
    }
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Init();
    MakeAnswer();
    return 0;
}