#include <iostream>

using namespace std;

// Ǯ��.
// ó������ �־��� ���ڿ����� HD�� ���� ���� ���ڿ��� ���ϴ°����� �����߾���.
// �����δ� ��� ����� ������ HD�� ���� ���� ���ڿ��� ã�� ���̾���. ���������� ���� �ռ� ���ڿ���
// ã�ƾ� �ϱ� ������ 4���� ���ĺ��� ���������� �����ذ��鼭 Ǯ����Ѵ�. ������ ���� �����ѵ�,
// ��� ���ڿ����� �� ���ڵ��� ���� ���� ������ �����̸� ���������� ���� �ռ��� ���ڸ� �ϳ��� �̾ư���,
// �� ���ڿ� ���� ���� ������ ���� ���ذ��� �ȴ�. ������ map���� Ǯ�� �� ª�� Ǯ�� ���� �� ������
// map�� ���� ������ ���� �Ⱦ� ������ �η��ô�.

// �ڼ��� ������ �ּ����� �����.

string board[1000];
char alpha[4] = { 'A', 'C', 'G', 'T' };
int HD[4];
int N, M;

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

void MakeAnswer()
{
    pair<string, int> answer = make_pair("", 0);
    // ���ڿ��� ���̸�ŭ �ݺ��ϸ� �ϳ��� ���ڸ� ã�´�.
    for (int i = 0; i < M; ++i)
    {
        // �� ���ڵ��� ������ ���� ����ϴ� �迭�� �ʱ�ȭ.
        for (int j = 0; j < 4; ++j)
            HD[j] = 0;
        // �� ���ڿ��� i��° ���ڵ��� ��� Ȯ���غ���
        // ������ Ƚ������ �����Ѵ�. ����� ��ó�� map�� ����ص� �ȴ�.
        for (int j = 0; j < N; ++j)
        {
            if (board[j][i] == 'A')
                ++HD[0];
            else if (board[j][i] == 'C')
                ++HD[1];
            else if (board[j][i] == 'G')
                ++HD[2];
            else
                ++HD[3];
        }

        pair<int, int> maxHD = make_pair(0, HD[0]);
        // �� ���ڵ��� ��ȸ�ϸ� ����Ƚ���� ���� ����, ���������� �ռ� ���ڸ� ã�´�.
        for (int j = 1; j < 4; ++j)
            if (HD[j] > maxHD.second)
                maxHD = make_pair(j, HD[j]);

        // �� ���ڸ� ������ answer�� ���ڿ��� �߰��Ѵ�.
        answer.first += alpha[maxHD.first];

        // ��� ���ڿ��� i��° ���ڵ��� �ٽ� ��ȸ�ϸ� ������ ã�� ���ڿ� �ٸ� ���ڵ��� ����
        // ��� ���Ͽ� ���Ѵ�.
        for (int j = 0; j < N; ++j)
            if (board[j][i] != alpha[maxHD.first])
                ++answer.second;
    }
    cout << answer.first << '\n';
    cout << answer.second << '\n';
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}