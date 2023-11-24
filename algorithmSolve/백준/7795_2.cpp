#include <iostream>
#include <algorithm>

using namespace std;

// ���� Ž���� ���� �������� �˾ƾ� �Ѵ�.
// 2������ �ִµ� �ִ� 100���� ����ϴ� �Ͱ� �� �����Ͱ� ��߳��� ���� ���� �ϴ� ���̸���ũ ���̸��� ����̴�.
// �Ѵ� ���� �˾ƾ� �Ѵ�. for���� ���� ������ �ǵ帱���� ��� ������ �ǵ���� �ϰ�, while���� �ǵ帮�°� ���� ���
// ������ �ǵ帱 �ʿ䰡 ����. �̷��� ��������.

int A[20000], B[20000];
int T, N, M;

int CalSmallA(int idx)
{
    int from = -1, to = M;

    for (int i = 0; i < 100; ++i)
    {
        int mid = (from + to) / 2;

        if (A[idx] > B[mid])
            from = mid;
        else
            to = mid;
    }
    return from + 1;
}

int CalSmallB(int idx)
{
    int from = 0, to = M - 1;

    while (from <= to)
    {
        int mid = (from + to) / 2;

        if (A[idx] > B[mid])
            from = mid + 1;
        else
            to = mid - 1;
    }
    return from;
}

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
        for (int i = 0; i < N; ++i)
            answer += CalSmallB(i);

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