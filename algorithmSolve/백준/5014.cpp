#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// Ǯ��
// �Ʒ� �ּ��� ���� �׸��� �������� Ǯ�� ���� ���� ��Ȳ�� ����غ������� 85�ۼ�Ʈ���� �ڲ� Ʋ���°� ���� ���� ��ģ�Ű���.
// �ᱹ Ǯ�̴� BFS�� ���� ���� �Ʒ��� ���� �ִ� ��� ��츦 ���� �غ��°��̾���. ���� bool�� �迭�� ���� �ߺ��Ǵ� ����
// ��� �����ؾ��Ѵ�. 

int F, S, G, U, D;

// �ö󰡾� �ϴ� ��Ȳ�̶�� ģ��.
// 1. U�� 0�϶��� ���� �����Ҽ� ����.
// 2. �ö����� õ���� �մ´�.
// 2-1. �ѹ� D��ŭ �����ͼ� �ٽ� �ö󰣴�.
// 2-2. �׷��� D��ŭ �����ü��� ���ٸ� ����� �̿��ؾ��Ѵ�. Ȥ�� D�� 0�϶�
// 2-3. Ȥ�� D�� U�� ������ ������ �������� �ѵ� �Ǵٽ� ���� ������ ���� �Ǿ�
// �ݺ��Ǳ� ������ ����� �̿��ؾ��Ѵ�.

void BFS()
{
    bool check[1000001];
    memset(check, false, sizeof(check));
    check[S] = true;
    queue<pair<int, int>> que;
    que.push(make_pair(S, 0));

    while (!que.empty())
    {
        int cur = que.front().first;
        int cost = que.front().second;
        que.pop();

        if (cur == G)
        {
            cout << cost << '\n';
            return;
        }

        int there = cur + U;
        if (there <= F && !check[there])
        {
            check[there] = true;
            que.push(make_pair(there, cost + 1));
        }

        there = cur - D;
        if (there >= 1 && !check[there])
        {
            check[there] = true;
            que.push(make_pair(there, cost + 1));
        }
    }
    cout << "use the stairs" << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> F >> S >> G >> U >> D;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}