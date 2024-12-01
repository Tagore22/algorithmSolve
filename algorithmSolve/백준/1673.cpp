#include <iostream>

using namespace std;

// 풀이.
// 브2치고는 난이도가 있었는지 정답율이 30퍼가 안되었다. 쿠폰 n과 쿠폰으로 모을수 있는 도장수 k가 있을때
// 단순히 보면 그냥 n / k를 하면 되는것처럼 보이지만 실제로는 그렇지 않다. 예를 들어 10, 3을 보면 답은
// 3같지만 3번을 시켰을때 얻을 수 있는 도장 3개로 쿠폰을 하나 더 만들수 있기 때문이다. 이렇게 쿠폰의 수는
// 치킨을 시켰을때 얻은 도장들끼리 모아 만든 쿠폰의 수가 추가되어야 하기 때문에 점화식은 이러하다.

// answer += n / k;
// n = n / k + n % k;

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        int answer = n;
        while (n >= k)
        {
            answer += n / k;
            n = n / k + n % k;
        }
        cout << answer << '\n';
    }
    return 0;
}