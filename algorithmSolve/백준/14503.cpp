#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��
// DFS�������� �ణ �ٸ����� �߰��� �����̴�.
// �������� �־��� û�ұ��� �ൿ ����� �ٽ� ���캸��.

// 1. ���� ��ġ�� û�ҵ��� ���� ���̶�� û���Ѵ�.
// 2. ���� 4���� ���� �ݽð� �������� 90����ŭ ȸ���ϰ� �ٶ󺸴� ������ ĭ�� û�ҵ��� ���� ��ĭ�̶�� �����Ͽ� 1���� �ݺ��Ѵ�.
// 3. �α� 4ĭ ��� û�Ұ� �� ��ĭ�̰ų� ���̶� ���ư��� ���ٸ� ���� �ٶ󺸰� �ִ� ���⿡�� �ڷ� ��ĭ �����Ѵ�. �̶� ��ĭ�� ���
// ���� �����Ҽ� ������, �ڰ� ���̶�� û�ұ�� �۵��� �����Ѵ�.

// ��, ����ϰ� �¿���ϸ� �����̴� DFS�� �����ϵ�, 4���� ��� ���ư��� ���ٸ� ���� ���⿡�� �ڸ� Ȯ���ϰ� ��ĭ�̶�� ���� �ƴ϶��
// �����ϸ� �ȴ�. �ٸ� ��¿������ �湮�Ͽ��� ���� �ٽ� �湮�ϴ� ��찡 �ֱ⿡ bool Ÿ�� �迭�� �湮�� ���θ� �����Ͽ� ���� �ߺ�����
// �ʰ� �����ؾ��Ѵ�.


// û�ұ��� �� ��ǥ�� ������ ��� ����ü.
struct cleaner
{
    int y;
    int x;
    int dir;
};

int board[50][50];
bool check[50][50];
int rot[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
cleaner from;
int N, M, answer = 0;
bool isend = false;


// DFS �Լ�. ���� ����� û�ұ��� �ൿ�� �����Ǿ� �ִ�.
void DFS(cleaner cur)
{

    // �ڰ� ���̿��� �����Ҽ� ���⿡ ����� ��Ȳ. �ƹ��͵� ���� �ʰ� �����Ѵ�.
    if (isend)
        return;

    // �����ϴ� ��� ��¿�� ���� �湮�� ���� �ٽ� �湮�ϰ� �ȴ�. �� ��� ���� �ߺ��ɼ��� �ֱ⿡ if ���ǹ����� ������ �����Ѵ�.
    if (!check[cur.y][cur.x])
    {
        check[cur.y][cur.x] = true;
        ++answer;
    }

    // ���� û�ұ��� ��ǥ�� ������ ��� ����. DFS��ȸ�� ������ �ٽ� �̰����� �ݹ�Ǿ����� û�ұ��� ���¸� �������Ѿ� �ϴµ�,
    // ������ ũ�⵵ ũ�� �ʰ� int ���� 3���� ����ֱ⿡ �׳� �׶��׶����� ���� �����Ͽ� ó���Ͽ���.
    cleaner next;

    // ��ġ��ǥ�� �׶��׶����� ���� �������� ���⸸ŭ�� �̸� �ʱ�ȭ�Ǿ� ��� ���Ͽ����Ѵ�.
    next.dir = cur.dir;
    for (int i = 0; i < 4; ++i)
    {
        next.dir = next.dir - 1 >= 0 ? next.dir - 1 : 3;
        next.y = cur.y + rot[next.dir][0];
        next.x = cur.x + rot[next.dir][1];

        if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || check[next.y][next.x] ||
            board[next.y][next.x] == 1)
            continue;

        DFS(next);
    }

    // 4������ ��ȸ ���� ������ ���̻� ���ư��� ���⿡ �����ϰų� �����Ѵ�. -1�� ���Ͽ� ���� ������ �ݴ뿡 �ش��ϴ�
    // ���� ��ǥ�� ���ϰ� �ڰ� ���̶�� �����ϰ�, ��ĭ�̶�� �����Ѵ�.
    next.y = rot[next.dir][0] * -1 + cur.y;
    next.x = rot[next.dir][1] * -1 + cur.x;
    if (board[next.y][next.x] != 1)
        DFS(next);
    else
        isend = true;
}

void MakeAnswer()
{
    DFS(from);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, false, sizeof(check));

    cin >> N >> M;
    cin >> from.y >> from.x >> from.dir;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}