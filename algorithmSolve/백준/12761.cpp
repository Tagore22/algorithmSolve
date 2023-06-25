#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// Ǯ��.
// ����� ���� ������ ���� Ǯ�������� �̻��Ѱ� �ѱ������� �ð��� ��Ƹ��� �����̴�.
// �ϴ� �� ������ ū Ʋ�� ���� ������ ����.

// 1. ������ A, B�� ���� ��ġ N, ���� ���� M�� �־�����.
// 2. N���� �����Ͽ� �̵��Ҽ� �ִ� ��� 8������ ��� �����Ѵ�.
// 3. �����Ѱ��� 0���� ���ų� ũ�� 10������ �۰ų� ���ƾ��ϸ�, �ߺ� ������ ���� ���� ���� �湮���� ���� ���̿����Ѵ�.
// 4. ���� �����Ѱ��� ���� ���� M�̶�� ������ ����ŭ ����Ѵ�.

// ���� �Ѱ��� ��ģ �κ��� ������ ��ġ�� 10�� �̻��� ��쿴��. �ļ��� ���ǹ����� �߸�ó���Ǽ� visit �迭������ ó���� 
// ������ ���� �Ǿ� ����� �� ���� ������ �ʾҴ�.

// �ڼ��� ������ �ּ����� �����.

queue<int> que;
const int MAX_NUM = 100000;
bool visit[MAX_NUM + 1];
int A, B, N, M;

// ���� ��ġ�� ���� ������ �Ǻ��ϴ� �Լ�.
// ����Ͽ��� ������ 3�����̴�.

// 1. ���� �湮���� �������̿��� �Ѵ�.
// 2. 0���� ũ�ų� ���ƾ� �Ѵ�.
// 3. 10������ �۰ų� ���ƾ� �Ѵ�.
void Check(int now)
{
    // ����� ������ �����ҽ� que�� ����ִ´�(�װ����� �̵��Ѵ�).
    // �ٷ� �� ���ǹ����� �Ǽ��� �־��µ�, �ּ�ó���� ���� ���� ���ǹ��̾���. ��� ���� ������ ����̳�
    // now�� 10�� �̻��� ���϶� ù��° ���ǹ����� �������� �Ǿ� �ùٸ� ���� ����Ҽ� ������.
    // if (!visit[now] && now >= 0 && now <= MAX_NUM)
    if (now >= 0 && now <= MAX_NUM && !visit[now])
    {
        visit[now] = true;
        que.push(now);
    }
}

// 8���� �̵��� �����ϴ� �Լ�.
void Move(int here)
{
    // + 1.
    int now = here + 1;
    Check(now);

    // - 1.
    now = here - 1;
    Check(now);

    // A �����̷� ����.
    now = here + A;
    Check(now);

    // A �����̷� ����.
    now = here - A;
    Check(now);

    // B �����̷� ����.
    now = here + B;
    Check(now);

    // B �����̷� ����.
    now = here - B;
    Check(now);

    // A �����̷� ����.
    now = here * A;
    Check(now);

    // B �����̷� ����.
    now = here * B;
    Check(now);
}

// BFS���� �Լ�. que�� �뷮�� ���̱� ���� ���� que�� �� �ִ� ���Ҹ�ŭ�� �ݺ����� ��ȸ�ϴ� ������� �����Ͽ��µ�
// ���� �̷��� ���� �ʰ�, que�� pair<int, int> �������� �Ͽ��� ����� ����.
int BFS()
{
    que.push(N);
    visit[N] = true;
    int answer = -1;

    while (!que.empty())
    {
        ++answer;
        int Qsize = que.size();
        for (int iter = 0; iter < Qsize; ++iter)
        {
            int here = que.front();
            que.pop();

            if (here == M)
                return answer;

            // ���⼭ 8���� ����� ��� �غ��� que�� �ִ´�.
            Move(here);
        }
    }
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));

    // ���⼭ BFS.
    int answer = BFS();
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}