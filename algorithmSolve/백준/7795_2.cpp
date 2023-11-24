#include <iostream>
#include <algorithm>

using namespace std;

// 이진 탐색을 직접 구현할줄 알아야 한다.
// 2가지가 있는데 최대 100번을 사용하는 것과 두 포인터가 어긋나지 않을 동안 하는 하이리스크 하이리턴 방법이다.
// 둘다 할줄 알아야 한다. for문은 딱히 설정을 건드릴일이 없어서 범위를 건드려야 하고, while문은 건드리는게 많은 대신
// 범위를 건드릴 필요가 없다. 이렇게 생각하자.

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