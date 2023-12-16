#include <iostream>
#include <set>

using namespace std;

// Ǯ��.
// ��������� �ڷḦ ������ �迭���� � �����͸� �߰��ϰ� ���ܽ�Ű�� ������.
// �ٸ� Ǯ�̵��� �ܼ��� ���͸� �̿��Ͽ� ������ ¥�� ���ݴ� ������ Ǯ���� ������
// ���� ������ ����� ���ĵ� �ǰ�, �߰� �� ������ ��� �Ǵ� ���� �����̳ʸ� ����ϴ� ���� ���ϴ�.
// Ư�� ���� map�� �ƴ� set�� ����ϴ°� �� �뷮�� ���� ó���Ұ͵� �پ ������.

// �ڼ��� ������ �ּ����� �����.

// ������ ���� ��, ������������ �����ؾ� �Ѵ�.
set<string, greater<>> board;
int N;

void MakeAnswer()
{
    string name, stat;
    for (int i = 0; i < N; ++i)
    {
        cin >> name >> stat;
        // ���� ���°� �߰���� �߰��Ѵ�.
        if (stat == "enter")
            board.insert(name);
        // �ƴ϶�� �����Ѵ�.
        else
            board.erase(name);
    }

    // ���� �����ִ� ��� �̸����� ����Ѵ�.
    for (auto iter : board)
        cout << iter << '\n';
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