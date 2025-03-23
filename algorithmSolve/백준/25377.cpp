#include <iostream>

using namespace std;

// 풀이.
// 쉽다고 무시했다가 -1이 나오는 경우를 구현안해서 한번 틀렸다.
// 조금 더 신중하자.

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