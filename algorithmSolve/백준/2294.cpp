#include <iostream>

using namespace std;

// Ǯ��.
// ����� DP������. ������ �ݾװ� �� �ݾ��� �־����� �ش� �ݾ��� ����� �ִ� �������� �ּҰ��� ���ϸ� �ȴ�.
// �� ������ �ݾ��� ������ 1���� �ּҰ��̹Ƿ� 1�� �ʱ�ȭ�� �ϰ� �������� MAX_NUM���� �ʱ�ȭ�� �Ѵ�.
// ���� 1���� K���� �����ϸ� ���� �ݾ׿��� ����Ҽ� �ִ� �������� ���Ͽ� �������� �ּҰ��� �����Ѵ�.

int coin[100], answer[10001];
int N, K;
const int MAX_NUM = 987654321;

void MakeAnswer()
{
    // ��� �ݾ��� �ʱⰪ�� �ִ밪.
    for (int i = 0; i <= K; ++i)
        answer[i] = MAX_NUM;

    // �� ������ �ݾ��� �� �״�� �ϳ��� �������� ���Ҽ� �ֱ⿡ 1�� �ʱ�ȭ�Ѵ�.
    for (int i = 0; i < N; ++i)
        if (coin[i] <= K)
            answer[coin[i]] = 1;

    // 1���� K���� ��ȸ�ϸ� �������� ���Ѵ�. 0���� Ŀ���ϴ� ������ ���̰� 0�϶����� ���� ������ �ʿ䰡 ���⿡
    // ���ɸ� ��ƸԴ´�.
    for (int i = 1; i <= K; ++i)
        for (int j = 0; j < N; ++j)
            if (i - coin[j] > 0)
                answer[i] = min(answer[i - coin[j]] + 1, answer[i]);

    cout << (answer[K] != MAX_NUM ? answer[K] : -1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> coin[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}