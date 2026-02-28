#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long result = 1; // 시작은 1층

    while (N--)
    {
        int A, B;
        cin >> A >> B;

        long long move = B - A;

        // 0층을 지나가는 경우 보정
        if ((long long)A * B < 0)
        {
            if (move > 0)
                move -= 1;
            else
                move += 1;
        }

        result += move;
    }

    // 최종 위치가 0 이하라면 0층이 없으므로 한 칸 더 보정
    if (result <= 0)
        result -= 1;

    cout << result << '\n';

    return 0;
}