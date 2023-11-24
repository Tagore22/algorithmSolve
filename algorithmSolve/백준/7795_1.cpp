#include <iostream>
#include <algorithm>

using namespace std;

// 7795���� �� ���� Ǯ��.
// ���� for������ �ִ� 4����� ������ �� �׽�Ʈ ���̽����� ������� �ʰ�
// lower_bound()�� �̿��Ͽ� �̺� Ž���� �����Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int A[20000], B[20000];
int T, N, M;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N >> M;
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        for (int i = 0; i < M; ++i)
            cin >> B[i];

        sort(B, B + M);
        int answer = 0;
        // A�� ��ȸ�Ѵ�.
        for (int i = 0; i < N; ++i)
            // ���� for���� ������� �ʰ� lower_bound()�� �̿��Ͽ� A�� ���ų� �� ū �ε����� ���Ѵ�.
            answer += lower_bound(B, B + M, A[i]) - B;

        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}