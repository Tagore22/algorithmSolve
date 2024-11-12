#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 23프로라는 정답율답게 어려운 문제였다. 처음에는 냅색풀이와 dp를 묶는 방법으로 구상하였으나
// dp배열이 5000, 10001로 매번 초기화하는 시간이 너무 많이들어갔다. 중복은 방지되었지만 말이다.
// 결국 재귀호출과 중복방지를 무시하고 속도를 올려야했다. 나에게는 꽤나 생소한 방식이었다. 
// 또한, 부동소수점에서 정수로의 캐스팅 역시 포함되어있었다. 이부분도 매우 중요했다. 잘 복기해두어야겠다.

// 자세한 설명은 주석으로 남긴다.

int n, intm;
float m;
int dp[10001];

void MakeAnswer()
{
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        // 부동소수점에서 정수로의 캐스팅. 0.29같은 경우는 부동소수점의 부정확함으로 인해
        // 0.2899999999999... 인 경우가 존재한다. 이때 단순히 100을 곱하면 28이 되기에
        // 이러한 손실을 방지하기 위해 적당한 값을 더해준다.
        intm = m * 100 + 0.5f;
        // 요즘은 memset()을 그다지 사용하지 않았는데 꽤나 유의미한 차이를 만들었다.
        memset(dp, 0, sizeof(dp));
        int cal;
        float cost;
        // 기존 재귀와는 다른 방식의 순회. i번째에서 10원을 까고 i + 1번째에서 0원을 까면
        // i + 2번째에서는 총 10원이 까진 상태에서 시작되며, i번째에서 0원을 까고
        // i + 1번째에서 10원을 까면 마찬가지로 i + 2번째에서는 10원을 까진 상태에서 시작한다.
        // 이러한 중복은 방지할수 없어도 상술한 초기화가 너무 많은 시간을 잡아먹어서 
        // 이렇게 풀어야했다. 아무래도 재귀방식이 시간을 꽤 많이 잡아먹는듯 하다. 왠만하면 피하자.
        for (int i = 0; i < n; ++i)
        {
            cin >> cal >> cost;
            int newcost = cost * 100 + 0.5f;

            for (int j = newcost; j <= intm; ++j)
                dp[j] = max(dp[j], dp[j - newcost] + cal);
        }
        cout << dp[intm] << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}