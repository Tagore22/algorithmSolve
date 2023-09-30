#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ����� ������ �ƴѵ� �߸� �����ؼ� 2���̳� ��� ������.
// ó������ ������������ �̵��Ұ� ���� �̵� ������ ������ �����۵��� ���Ϸ��� ������,
// ���� �������� �̵��Ͽ� ������ �������� �ұ��ϰ� ������ �߸� �о �Ѱܼ� Ʋ�Ȱ�
// �ι�°�� DFS�� �̿��߱� ������ �ѹ� ������ ������ �� ������ �����Ҽ� �������� �����ؼ� Ʋ�ȴ�.
// ��������δ� �÷��̵� �ͼ��̳� ���ͽ�Ʈ�� �̿��ؼ� � ������ �ּ����� ���̷� �̵��Ͽ�����
// �����Ҽ� �ִٸ� �� ������ �������� ȹ���Ҽ� �ִ� ������ ���� �� �����۵��� ������ ��� ���Ͽ� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

vector<vector<int>> way;
int item[101];
int N, M, R, answer = 0;

// �÷��̵� �ͼ� �Լ�.
void Floyd()
{
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                // i���� j���� ���� ���̸� k�� ���� �̵��ϴ� ���� ���Ͽ� ������.
                way[i][j] = min(way[i][j], way[i][k] + way[k][j]);
}

void MakeAnswer()
{
    Floyd();

    // 1 ~ N�� ������ ��� ��ȸ�Ͽ� ���� ���� �����ۼ��� ã�´�.
    for (int i = 1; i <= N; ++i)
    {
        int ans = 0;
        // 1 ~ N������ �ּ����� ���̷� �̵��Ͽ����� �������� ���� ������ �����ۼ��� ��� ���Ѵ�.
        for (int j = 1; j <= N; ++j)
            if (way[i][j] <= M)
                ans += item[j];

        answer = max(answer, ans);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;
    // ȹ�� ������ �ִ� 15�̱� ������ �� �̻��� 16���� �ʱ�ȭ�ϸ� �ȴ�.
    for (int i = 1; i <= N; ++i)
        cin >> item[i];
    way.resize(N + 1, vector<int>(N + 1, 16));
    // i���� i�� �̵��� �����ϳ� �̷��� ��찡 �־����� �ʱ⿡ ���� �ʱ�ȭ�ؾ��Ѵ�.
    for (int i = 1; i <= N; ++i)
        way[i][i] = 0;
    int from, to, len;
    for (int i = 0; i < R; ++i)
    {
        cin >> from >> to >> len;
        // ��������� �̵��� �������� �������� ��������.
        way[from][to] = len;
        way[to][from] = len;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}