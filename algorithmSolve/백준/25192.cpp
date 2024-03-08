#include <iostream>
#include <unordered_map>

using namespace std;

// Ǯ��.
// ���ڿ����� �Է¹޾� �̹� �Է¹޾Ҵ� ���ڿ����� Ȯ���ϴ� ������.
// ó������ set�̳� map�� ��µ� unordered_map�� �־���. ���� �����̳ʴ� ���� �Ⱦ���
// �ؾ������ �� ����. ���Ӱ� ���͵� �ִµ� if������ ���� board.clear()�� �־���.
// �׷��� �ݺ��ڸ� �̿��Ͽ� ó���� ���� ������ �ѱ� board.erase()�� �� ������. ������ �ᱹ ��ã������
// �ϴ� �˾Ƶ���.

// �ڼ��� ������ �ּ����� �����.


// ������ ���� �ʴ� map. �ؾ������ ����.
unordered_map<string, bool> board;
int N;

void MakeAnswer()
{
    string cur;
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> cur;
        // ���ο� �������� �����Ѵٸ� �� ������ ��ϵ��� ����������.
        if (cur == "ENTER")
        {
            // ����Ͽ��� clear()���� ��� ������ �ѱ� erase()�� �ξ� �� ������.
            board.erase(board.begin(), board.end());
        }
        // �׷��� �ʴٸ� cur�� �̹� �����ϴ��� Ȯ���ϰ� �����ٸ� ������ answer�� 1 ������Ű��
        // map�� �߰��Ѵ�.
        else
        {
            if (!board[cur])
            {
                ++answer;
                board[cur] = true;
            }
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}