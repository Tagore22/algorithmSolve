#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

// Ǯ��.
// �������� �̿��� �������� ��������.
// ó���� ������ ��̱⿡ ���� ��ð����� Ǯ����. �ǹ� �����ε� ��..
// ����Ǯ���� ū Ʋ�� ������ ����.

// 1. 0 ~ N - 1���� ��ȸ�Ѵ�.
// 2. ���� ������ ���� �������� visit �迭�� �̿��� �����Ѵ�. ���� ���簪�� que�� ����ִ´�.
// 3. ���� K���� �� ���� �����Ͽ��ٸ� ���� ���� ������ ������ ������ ������ answer�� ���Ѵ�.
// 4. que�� ��ȸ�ϸ� �ϳ��� ���� ������ ����Ƚ���� �ٿ��ش�. �̹��� �������� K���� �� ���� ������ ����� Ż���Ѵ�.
// 5. N - 1���� �ݺ��ϸ� �ִ밪 answer�� ����Ѵ�.

// ������ �ʹ� ��ư� �����ߴ��� ����. �ֽô��� �ʹ� ���� �İ��� �������� ������ ȭ�� ������.

// �ڼ��� ������ �ּ����� �����.

queue<int> que;
int board[200000];
int visit[100001];
int N, K;

// erase�� K������ �� ���� �����Ͽ����� que�� �����ϴ� �Լ�.
void RenewQueue(int erase)
{
    // que�� �� �պ��� �ϳ��� ���� �ٿ�����
    // �̹��� ������ ���� erase��� Ż���Ѵ�.
    while (true)
    {
        int here = que.front();
        que.pop();
        --visit[here];
        if (here == erase)
            break;
    }
}

void MakeAnswer()
{
    memset(visit, 0, sizeof(visit));
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        // 0 ~ N - 1���� ��ȸ�ϸ� ������� que�� ����ְ�
        // ����Ƚ���� ������ ������.
        int here = board[i];
        que.push(here);
        ++visit[here];
        // ����� here�� K���� �� ���� �����Ͽ��ٸ� ���±����� ������ ������ answer�� ���ϰ�
        // que�� ���� here�� �����Ҷ����� ���Ž�Ų��.
        if (visit[here] > K)
        {
            int compose = que.size() - 1;
            answer = max(answer, compose);
            RenewQueue(here);
        }
    }
    int compose = que.size();
    answer = max(answer, compose);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}