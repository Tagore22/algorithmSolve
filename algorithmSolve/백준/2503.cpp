#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// Ǯ��.
// ���״�� 3�ڸ����� �׶��� ���� ��Ʈ����ũ, ���� ���� �־����� ���������
// ������ �ɼ� �ִ� ����� ���� ����ϸ� �ȴ�.
// ��� �ٸ� 3�ڸ����̱⿡ ������ 123 ~ 987�̸�, ��� �ٸ� 3�ڸ������� �ϰ� 0�� �����ؼ��� �ȵȴ�.
// �� ����� �´� ������ ���� �ɷ����� �� ���� �־����� ��Ʈ����ũ, ���� ���Ͽ� ���������� ����
// ������ ���� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

bool board[988];
int N, cur, s, b;

// �ʱ⿡ ������ �ɷ����� �Լ�.
bool CheckWrong(int num)
{
    string str = to_string(num);

    // ��� �ٸ� ����� �̷���� �־�� �ϸ�, 0�� �����ؼ��� �ȵȴ�.
    if (str[0] == str[1] || str[0] == str[2] || str[1] == str[2]
        || str[0] == '0' || str[1] == '0' || str[2] == '0')
        return false;

    return true;
}

// ����� num�� �־����� �� cur�� ���ϴ� �Լ�.
bool ComposeNum(int num)
{
    int cur_s = 0, cur_b = 0;
    string from = to_string(cur);
    string to = to_string(num);

    // �� �ڸ������� ���Ѵ�.
    if (from[0] == to[0])
        ++cur_s;
    else if (from[0] == to[1] || from[0] == to[2])
        ++cur_b;

    if (from[1] == to[1])
        ++cur_s;
    else if (from[1] == to[0] || from[1] == to[2])
        ++cur_b;

    if (from[2] == to[2])
        ++cur_s;
    else if (from[2] == to[0] || from[2] == to[1])
        ++cur_b;

    // �־��� ��Ʈ����ũ, ���� ���� ���� ��Ʈ����ũ, ���� ���� ���Ͽ� ����Ѵ�.
    return cur_s == s && cur_b == b;
}

void MakeAnswer()
{
    memset(board, true, sizeof(board));
    // 123 ~ 987�� �ϴ� �ѹ� �ɷ�����.
    for (int i = 123; i <= 987; ++i)
    {
        if (!CheckWrong(i))
            board[i] = false;
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> cur >> s >> b;

        // 123 ~ 987�� ��ȸ�Ѵ�.
        for (int j = 123; j <= 987; ++j)
        {
            // �̹� �ɷ��� ����� �����Ѵ�.
            if (!board[j])
                continue;

            // ���� �־��� ��Ʈ����ũ, ���� ������ �񱳰���� �ٸ��ٸ� �ɷ�����.
            if (!ComposeNum(j))
                board[j] = false;
        }
    }

    int answer = 0;
    // ���������� ���� ������ ������ ����Ѵ�.
    for (int i = 123; i <= 987; ++i)
    {
        if (board[i])
            ++answer;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}