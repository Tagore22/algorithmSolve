#include <iostream>

using namespace std;

// Ǯ��.
// ó������ ������ �� �������� �ʾҴ�. ������ �������� ���� ���̽�ũ���� ���� 3������
// ��Ȯ�ϰ� ������ ������ �������̾���, �װ��� �̿��ؾ��ߴ�. ��������� �ָԱ���������
// Ǯ����ߴ�. �Ұ����� ���յ��� bool �迭�� �����س��� �� ���ý� Ȯ���Ѵ�. 
// ����Ѵ�� 3������ �־����⿡ 3�� for���� �̿��Ͽ���.

bool HatePair[201][201] = { false, };
int N, M;

void MakeAnswer()
{
    int answer = 0;
    for (int i = 1; i <= N - 2; ++i)
    {
        for (int j = i + 1; j <= N - 1; ++j)
        {
            if (HatePair[i][j])
                continue;
            for (int z = j + 1; z <= N; ++z)
            {
                if (HatePair[j][z] || HatePair[i][z])
                    continue;
                ++answer;
            }
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int first, second;
        cin >> first >> second;
        HatePair[first][second] = true;
        HatePair[second][first] = true;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}