#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ��� ���� �����غ������� ���� �����غ��� �׸� ����� �ʾҴ�.
// ���� ū���� �������� ����Ҷ��� �ݴ��� �����ε� ū���� ���Ҷ��� ������ ������ ����.

// 1. ���۰��� 9�����̴�. �־��� ��ȣ�� ��ȸ�ϴµ� ���� ��ȸ���� 0�����̴�. '>' �� ���������� ���� ��� �پ���.
// 2. ó������ '>'�� �������� ���� string�� ����ִ´�.
// 3. ���簪�� ���� ū 9���� 0���� �� ���� �������� ����(false��) ���� ���� ū���̴�.
// 4. �ٽ� ���� ��ȸ���� + 1 ������ ���� ��ȸ�Ѵ�. �̰��� �ݺ��Ѵ�.

// �������� �� �ݴ��̴�. 

bool check[10];
char board[9];
string answer;
int K;

void CalMax()
{
    memset(check, false, sizeof(check));

    // ���簪. �Լ� �����س����� �Ѵ�.
    int now;

    // �־��� ��ȣ���� ��ȸ�Ѵ�.
    for (int i = 0; i < K; ++i)
    {
        // ���� ���� 9 ~ 0 �� �������� ����(false��) ���� ū ���̴�.
        for (int j = 9; j >= 0; --j)
            if (!check[j])
            {
                now = j;
                break;
            }

        // ���� ��ȸ������ ������ ��ȸ�ذ��� '>'�϶����� �� ���� �۾�������.
        int iter = i;
        while (board[iter] == '<' && iter < K)
        {
            ++iter;
            --now;
        }

        // ���簪�� �������� string�� ����ִ´�.
        check[now] = true;
        answer.push_back(now + '0');
    }

    // ���� �����غ��� �˰����� �������� �ѹ� �� ����־���Ѵ�.
    for (int j = 9; j >= 0; --j)
        if (!check[j])
        {
            now = j;
            break;
        }

    answer.push_back(now + '0');

    // �������� ����Ѵ�.
    cout << answer << '\n';
}


// �ִ밪�� ���ϴ� �Լ��� �ݴ��.
void CalMin()
{
    memset(check, false, sizeof(check));
    answer.clear();

    int now;
    for (int i = 0; i < K; ++i)
    {
        // 0 ~ 9 �� ���� �������� ���� ���� �������� ���簪�̴�.
        for (int j = 0; j < 10; ++j)
            if (!check[j])
            {
                now = j;
                break;
            }

        int iter = i;

        // ���� ��ȸ������ ���������� ��ȸ�ϸ� '<'�� ã�������� ���簪�� ��� Ŀ������.
        while (board[iter] == '>' && iter < K)
        {
            ++iter;
            ++now;
        }

        // ���� ���� �������� string�� ���Ѵ�.
        check[now] = true;
        answer.push_back(now + '0');
    }

    // �ִ밪�� �����ϰ� �����غ��� �������� �ѹ� �� �߰��ؾ��Ѵ�.
    for (int j = 0; j < 10; ++j)
        if (!check[j])
        {
            now = j;
            break;
        }

    answer.push_back(now + '0');

    // ������ ���.
    cout << answer << '\n';
}

void MakeAnswer()
{
    CalMax();
    CalMin();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K;
    for (int i = 0; i < K; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}