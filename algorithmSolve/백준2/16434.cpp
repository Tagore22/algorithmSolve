#include <iostream>

using namespace std;

// 풀이.
// 본래는 이분 탐색 문제지만 나는 그냥 N번을 순회하면서 풀 수 있을 것 같았다.
// 여러번 삽질을 했지만 결과적으로는 한번에 받는 최대 대미지량 + 1이 정답이 된다.
// 따라서 N번을 순회하며 매번 대미지량을 계산해 나가면 된다. 다만 max()나 min()일때
// long long 정수를 넣어야했는데 아무 생각없이 static_cast<>()를 사용하고 있었다.
// 굳이 그럴 필요없이 LL을 추가해주면 된다. 다시한번 깨달았다.

// 자세한 설명은 주석으로 남긴다.

long long n, atk, t, a, h;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> atk;
    long long answer = 1, damage = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> t >> a >> h;
        // 공격을 받을 때. 현재 방에서의 대미지를 구해서 기존의 최대 대미지와
        // 비교해본다.
        if (t == 1)
        {
            long long cur = (h % atk == 0) ? h / atk - 1 : h / atk;
            cur *= a;
            damage += cur;
            answer = max(answer, damage + 1);
        }
        // 포션을 찾았을 때. 현재 대미지량을 줄이고 공격력을 높인다.
        else
        {
            atk += a;
            damage = max(0LL, damage - h);
        }
    }
    cout << answer << '\n';
    return 0;
}