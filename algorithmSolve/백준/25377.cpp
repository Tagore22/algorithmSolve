#include <iostream>

using namespace std;

// Ǯ��.
// ���ٰ� �����ߴٰ� -1�� ������ ��츦 �������ؼ� �ѹ� Ʋ�ȴ�.
// ���� �� ��������.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, answer = 1001;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (a <= b)
            answer = min(answer, b);
    }
    answer = answer == 1001 ? -1 : answer;
    cout << answer << '\n';
    return 0;
}