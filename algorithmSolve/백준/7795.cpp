#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// A�� �� ���Һ��� B�� ���ҵ��� �ڽź��� ���� ������ ���� ���ϸ� �Ǵ� ������.
// �ָԱ����� Ǯ��.

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

        // ����ġ�⸦ ���� ����.
        sort(B, B + M);
        int answer = 0;
        // A�� ��ȸ�Ѵ�.
        for (int i = 0; i < N; ++i)
            // B�� ��ȸ�Ѵ�.
            for (int j = 0; j < M; ++j)
            {
                // A�� ũ�ٸ� ������ answer�� 1�� �����ϰ� ��� ��ȸ�Ѵ�.
                if (A[i] > B[j])
                    ++answer;
                // ���� A�� ���ų� �۴ٸ� ���Ŀ� ���� �� �ڴ� ������ A�� �۾����Ƿ� Ż��.
                else
                    break;
            }
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