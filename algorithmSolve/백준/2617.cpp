#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// �׷��� ħ���ϰ� �����ߴ��� �ݹ� Ǯ����. �ٸ� �Ѱ��� ���̾��� �Ǽ��� 11���� ���ȴ�.
// ó������ �׷����� ������� �ʰ� �ܼ� ��Ģ�������� Ǯ�� ������ ���������� ��ġ�� �κ��� �����߱⿡
// �Ұ����ߴ�. ���� ���� ������ �迭�� ���ſ� �迭�� �غ��Ͽ� DFS()�� ���� ���� �������� ������ �͵�,
// ���ſ� �͵��� ���� ����Ͽ� �װ��� N / 2 + 1������ ũ�ų� ���ٸ� �� ������ ����� ���԰� �߰��� �ɼ�
// ���� ���� ����ߴ�. ��Ʈ���� �÷��̵� �ͼ��� �־���.

// �ڼ��� ������ �ּ����� �����.

vector<int> l[100], h[100];
bool visit[100];
int N, M, num;

// �� ������ �����θ� �̵��ϴ� DFS �Լ�.
void CalLow(int idx)
{
    // ���� ��ġ�� �����߱⿡ num���� ������Ű�� �湮���θ� �����Ѵ�.
    ++num;
    visit[idx] = true;

    // �� ������ �迭����� ���ҵ�� �̵��Ѵ�. �ٸ� �̹� �湮�Ѱ��� �����Ѵ�.
    for (auto& a : l[idx])
    {
        if (!visit[a])
            CalLow(a);
    }
}

// �� ���ſ� �����θ� �̵��ϴ� DFS �Լ�.
void CalHeavy(int idx)
{
    // ���� ��ġ�� �����߱⿡ num���� ������Ű�� �湮���θ� �����Ѵ�.
    ++num;
    visit[idx] = true;

    // �� ���ſ� �迭����� ���ҵ�� �̵��Ѵ�. �ٸ� �̹� �湮�Ѱ��� �����Ѵ�.
    for (auto& a : h[idx])
    {
        if (!visit[a])
            // ����� �Ǽ��� �����. ������ �ϴٰ� CalHeavy�� �ƴ� CalLow()�� �����ߴ�;
            CalHeavy(a);
    }
}

void MakeAnswer()
{
    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        // ��� �湮 ���θ� �����Ѵ�.
        for (int j = 1; j <= N; ++j)
            visit[j] = false;
        // ���� ���������� num�� �����ϱ� ������ �ʱ�ȭ���� 0�� �ƴ� -1�̿����Ѵ�.
        num = -1;
        // DFS��ȸ�� �Ѵ�.
        CalLow(i);
        // �����Ҽ� �ִ� ������ ���� N / 2 + 1������ ���ٸ� ���԰� �߽��� �ɼ�����.
        if (num >= N / 2 + 1)
            ++answer;
        // ���ſ��ʵ� ���Ѵ�.
        for (int j = 1; j <= N; ++j)
            visit[j] = false;
        num = -1;
        CalHeavy(i);
        if (num >= N / 2 + 1)
            ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        l[a].push_back(b);
        h[b].push_back(a);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}