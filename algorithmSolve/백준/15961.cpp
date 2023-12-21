#include <iostream>

using namespace std;

// Ǯ��.
// �־��� ȸ���ʹ���� �������� K���� ������ ������ �ִ� �ʹ������� �ִ븦 ����ϴ� �����̴�.
// ��� �ʹ���� �������� ���� ������ �������͸� �̿��ؼ� �����Ѱ� �����Ҽ� �ִ�.
// �ٸ� �Ǽ� �ϳ��� �ؼ� �� 10�� ��̴µ� �̴� �ļ��Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int board[3000000], sushi[3001];
int N, D, K, C;

void MakeAnswer()
{
    // �������� ������ �ִ� �ʹ�� 0��°���� K���� �ʹ��� �̸� Ȯ���Ͽ� ������ answer��
    // �ʱ�ȭ�Ѵ�.
    sushi[C] = 1;
    int answer = 1;
    for (int iter = 0; iter < K; ++iter)
    {
        int here = board[iter];
        // ���� �ʹ��� 0�� ���� ���¶�� �������� 1 �����Ѵ�.
        if (sushi[here] == 0)
            ++answer;
        // here��° �ʹ��� ���´�.
        ++sushi[here];
    }
    // ���� ���� ��ȣ�� ���� ���� ��ȣ, ���� �ִ� ������ �ʱ�ȭ�Ѵ�.
    // �� ���Ĵ� ���� �����ϴ�.
    int idx_b = K, cur = answer, idx_f = 0;
    for (int iter = 1; iter < N; ++iter)
    {
        int here = board[idx_b];
        // ���� ���� �ʹ��� ó�� ���� ���¶�� �������� 1 �����Ѵ�.
        if (sushi[here] == 0)
            ++cur;
        // here��° �ʹ��� ���´�.
        ++sushi[here];
        int prev = board[idx_f];
        // prev��° �ʹ��� ���´�.
        --sushi[prev];
        // ���� ���� �ʹ��� ������ 0���� �ȴٸ� �������� 1 �����Ѵ�.
        if (sushi[prev] == 0)
            --cur;
        // ���� �������� ������ answer�� ���Ͽ� answer�� �����Ѵ�.
        answer = max(answer, cur);
        // ���� ��ȣ�� ���� ��ȣ�� 1�� �����Ѵ�.
        // �ٸ� ���� ��ȣ�� ������ �迭�� �ѹ��� ���� ó������ �ǵ��ư��� ������
        // �̿� ���� ó���� ���ش�.
        ++idx_f;
        idx_b = idx_b + 1 == N ? 0 : idx_b + 1;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> D >> K >> C;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}