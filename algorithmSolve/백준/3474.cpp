#include <iostream>

using namespace std;

// 풀이.
// 규칙을 파악하는 문제였다. 주어지는 수 num에서 5가 증가할때마다 0의 개수는 1씩 증가했는데
// 24에서 25가 될때 1개가 아닌 2개가 늘어났다. 마찬가지로 124에서 125가 될때 1개가 아닌 2개가
// 늘어났다. 결과적으로 num보다 작거나 같은 모든 5의 배수의 값들을 더한값이 정답이었다.

int T;

void MakeAnswer()
{
    int num;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> num;
        int piv = 5, answer = 0;
        while (piv <= num)
        {
            answer += num / piv;
            piv *= 5;
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