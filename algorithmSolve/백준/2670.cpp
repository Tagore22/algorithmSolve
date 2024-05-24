#include <iostream>

using namespace std;

// 풀이.
// 처음에는 주먹구구식으로 풀었다. 최대 10000개의 소수가 입력되며 모든 경우를 구해도 10000 * 10000으로 인해 1억밖에 되지
// 않기 때문이다. 아래와 같은 비슷한 풀이를 생각 못한건 아니지만 섬세함이 약간 부족했다. 결과적으로 현재값과 새로운값을 곱해서
// 1이 넘는다면 수가 점점 커지기에 둘을 곱하고, 그렇지 않다면 작아지기 때문에 현재값을 교체하고 넘어간다. 또한, 소수 n째자리까지만
// 출력하는 새로운 방식을 도입했는데 precision()이 아닌 printf()을 사용한 것이다. 기존보다 더 간편하긴하다. 잘 알아둘것.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double cur, next, answer = 0;
    int N;
    cin >> N >> cur;
    for (int i = 1; i < N; ++i)
    {
        cin >> next;
        if (cur > 1)
            cur *= next;
        else
            cur = next;
        answer = max(answer, cur);
    }
    printf("%.3lf", answer);
    return 0;
}