#include <iostream>
#include <queue>
#include <set>

using namespace std;

// Ǯ��.
// ����� �ʾҴµ� �Ѱ��� ���������� �ִ� ��������. ��������� BFS ��ȸ�� �ϸ� ������ ������.
// �ٸ� a�� b�� �ִ밪�� 10���̶� 10�� * 10���� �ϸ� 100������ �ð��ʰ��� �޸��ʰ��� �Ͼ�� ������
// �ٸ� ����� ã�ƾ��Ѵ�. ������ ������� ���� a�� ��ä��ų� a�� 0���� ����ų�, b�� ��ä��ų� b�� ����
// �����̴�. ���� ������ 100���� ��� ��������� �ʴ´�. ��������� �迭�� �ƴ� map�̳� set���� ���� �����̳ʸ�
// ����ؾ� �ߴ�. �ٸ� �ξ� �� ���� Ǯ�̵� �ִµ� �װ� ������ �𸣰ڰ� ���� �ǵ��� �ƴѰ� ���⵵ �ϰ�.

// �ڼ��� ������ �ּ����� �����.

int a, b, c, d;

// ��� ��츦 Ȯ���ϴ� BFS ��ȯ �Լ�.
void BFS()
{
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    // �迭�� ����Ҽ� ���� ���� �����̳ʸ� ����ؾ��Ѵ�.
    set<pair<int, int>> visit;
    visit.insert(make_pair(0, 0));
    int answer = -1;

    while (!que.empty())
    {
        int qsize = que.size();
        ++answer;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            if (y == c && x == d)
            {
                cout << answer << '\n';
                return;
            }

            // a ó��.
            if (visit.find(make_pair(a, x)) == visit.end())
            {
                que.push(make_pair(a, x));
                visit.insert(make_pair(a, x));
            }
            if (visit.find(make_pair(0, x)) == visit.end())
            {
                que.push(make_pair(0, x));
                visit.insert(make_pair(0, x));
            }
            int ny = b - x >= y ? 0 : y - b + x;
            int nx = b - x >= y ? y + x : b;
            if (visit.find(make_pair(ny, nx)) == visit.end())
            {
                que.push(make_pair(ny, nx));
                visit.insert(make_pair(ny, nx));
            }
            // b ó��.
            if (visit.find(make_pair(y, b)) == visit.end())
            {
                que.push(make_pair(y, b));
                visit.insert(make_pair(y, b));
            }
            if (visit.find(make_pair(y, 0)) == visit.end())
            {
                que.push(make_pair(y, 0));
                visit.insert(make_pair(y, 0));
            }
            ny = a - y >= x ? y + x : a;
            nx = a - y >= x ? 0 : x - a + y;
            if (visit.find(make_pair(ny, nx)) == visit.end())
            {
                que.push(make_pair(ny, nx));
                visit.insert(make_pair(ny, nx));
            }
        }
    }
    cout << -1 << '\n';
}

void MakeAnswer()
{
    BFS();
}

int main()
{
    cin >> a >> b >> c >> d;
    MakeAnswer();
    return 0;
}