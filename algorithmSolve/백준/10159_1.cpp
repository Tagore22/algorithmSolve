#include <iostream>

using namespace std;

// 10159���� �÷��̵� �ͼ� Ǯ�̹�.
// ó������ �÷��̵� �˰��� ��ü�� ���÷����� ��� ������Ѿ� ������ �������� �ʾҴ�.
// �˰��� �����ѵ�, �־��� ������� �̿��Ͽ� �� ���ǵ��� ���� ���������� �ľ��ϸ� �ȴ�.
// ������ �����ϴٸ� �񱳰� �����ϴٴ� ���̱� �����̴�.
// �ٸ�, ���ſ��� ���ϴ� ���� �������� ���ϴ� ��� 2������ ������ �ľ��ؾ��Ѵ�.
// ������ ������ 2���� ��찡 ������ �׷����� �����Ǳ� ������ ���� ã���� ����.

// �ڼ��� ������ �ּ����� �����.

bool heavy[101][101], light[101][101];
int N, M;

void Floyd()
{
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
            {
                // ����ϰ� 2���� boolŸ�� ���Ϳ����� �� |= ������ ���� �ʾҴ�.
                heavy[i][j] |= heavy[i][k] & heavy[k][j];
                light[i][j] |= light[i][k] & light[k][j];
            }
}

void MakeAnswer()
{
    Floyd();
    int answer;
    for (int iter = 1; iter <= N; ++iter)
    {
        answer = 0;
        for (int i = 1; i <= N; ++i)
        {
            if (heavy[iter][i])
                ++answer;
            if (light[iter][i])
                ++answer;
        }

        cout << N - answer - 1 << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        light[from][to] = true;
        heavy[to][from] = true;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}