#include <iostream>
#include <cmath>

using namespace std;

// Ǯ��.
// ���̰� ��� �������� �ּ� �ð��� �ִ� �ð��� ���ϴ� ������.
// �ּҽð��� �״�� �������� ��� �������� ���ε� �ִ� �ð��� ������ ���� �ʾҴ�.
// ������ ������ ���� �ֵ�Ȥ�̾���, �����ϴ� ���� ���߾���.

// �ִ� �ð��� �� ������ ���̰� ���� �ݴ������� �������� �ð��� �ִ밪�̾���.

int T, N, L, cur;

void MakeAnswer()
{
    int from, to, mid;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N >> L;
        from = N;
        to = 0;
        mid = 0;
        int pivot = N / 2;
        for (int i = 0; i < L; ++i)
        {
            cin >> cur;
            from = min(from, cur);
            to = max(to, cur);
            mid = abs(mid - pivot) > abs(cur - pivot) ? cur : mid;
        }
        mid = mid - 0 > N - mid ? N - mid : mid;
        cout << mid << ' ';
        int answer = N - from < to ? to : N - from;
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