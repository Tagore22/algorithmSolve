#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

// Ǯ��.
// �������� ���ڸ������� P�� �����Ͽ� ���Ѱ��� ������϶� �ݺ����� �ʴ� ���ҵ��� ����
// ����ϴ� ������. ���� �׸����� ��ȭ���� �������� �ʾ� �ݺ��ϱ�� �Ͽ���.
// �ִ밪�� �Ƹ� 9999�� 5�� ��찡 �Ǿ� 25���� �� �ȵǴ� ���̴�.
// �� ���� ���� ���� �پ��� �þ�⸦ �ݺ��Ѵ�. �Ȱ��� ���� 2�� ������������
// �ݺ��� ���۵ǹǷ� �װ͸� Ȯ���ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

vector<int> board;
int visit[250000];
int A, P;

int main()
{
    cin >> A >> P;
    // ��� ������ ���� �湮���� �ʾ���.
    memset(visit, -1, sizeof(visit));
    // 0��°�� �湮��.
    visit[A] = 0;
    board.push_back(A);
    int idx = 1;
    while (true)
    {
        int prev = board.back();
        int here = 0;
        // ������� �������� �� �ڸ����� P�� �����Ͽ� ���Ѱ�.
        while (prev >= 1)
        {
            here += pow(prev % 10, P);
            prev /= 10;
        }
        // ���� ������� �̹� �湮���� �ִ� ����� �湮�ߴ� ������ ����Ѵ�.
        if (visit[here] != -1)
        {
            cout << visit[here] << '\n';
            break;
        }
        // ������� �湮���θ� �����ϰ� �������� �Ѿ��.
        visit[here] = idx;
        board.push_back(here);
        ++idx;
    }
    return 0;
}