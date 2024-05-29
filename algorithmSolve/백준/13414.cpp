#include <iostream>
#include <unordered_map>

using namespace std;

// Ǯ��.
// ���������� ���� �Է��� ��� �ް� �ߺ��� ������ �Ǿպ��� K���� ����϶�� ������
// �̷��� �ִ� L���� �ι� ��ȸ�ؾ��ߴ�. �׷��� �Ӹ��� ������� �ߴµ� ó�� L���� �Է¹�����
// ���� �й��� ��� �����ߴ����� pair<>�� �̿��Ͽ� ���� �����ߴ�. �� ���� �ѹ��� L���� ��ȸ�ϸ�
// ���� �й��� ���������� ���������� ����� �ϰԲ� �����ߴ�. ����Ե� �� ������ 26�ۼ�Ʈ¥������.
// ���� �ӵ��� �����ϳ� �ñ��ؼ� pair<>�� string�� �ƴ� int�� �ٲپ��µ� �ƿ� ���� �ȳ��Դ�.
// ������ �𸣰ڴ�.

// P.S ���ÿ��� �־����� �й��� 0���� �����ϴ� �͵��� �ִ�. �̷� ��� ���� 0�� ���õǾ� Ʋ���� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

pair<string, int> board[500000];
unordered_map<string, int> check;
int K, L;

void MakeAnswer()
{
    // unordered_map�� �����Ͽ� ���� �й��� ����Ƚ������ �����Ѵ�.
    for (int i = 0; i < L; ++i)
    {
        cin >> board[i].first;
        board[i].second = check[board[i].first] + 1;
        ++check[board[i].first];
    }
    // �ѹ��� �ִ� L�� ��ȸ�ϸ� ���� �й��� ���������� ������ ����� �� �й��� ����Ѵ�.
    for (int i = 0; i < L; ++i)
    {
        if (board[i].second == check[board[i].first])
        {
            cout << board[i].first << '\n';
            --K;
        }
        if (K == 0)
            break;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K >> L;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}