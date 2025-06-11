#include <iostream>

using namespace std;

// 풀이.
// 처음에는 주먹구구식으로 백트래킹을 사용하여 모든 문자열들을 만들어서 확인해가며 구현했다.
// 당연히 메모리 초과가 나왔다. 그 이후 각 문자에서 얻을 수 있는 경우는 최소 1, 최대 3임을
// 이용하여 구현하였으나 한가지 실수가 나왔다. 기존의 로직은 이러했다.

// 모든 문자들을 순회하며 idx번째의 앞뒤 문자들과 비교하여 다르다면 경우의 수 cur을 1씩 증가시킴

// 이 로직의 오류점은 예를 들어 aba일 경우 발생한다. idx가 1일때 각각 앞, 뒤인 문자 a는 모두
// idx번째 문자인 b와 다르지만 정작 앞, 뒤 문자끼리 동일하여 경우의 수가 3이 아님에도 계산에서는
// 3이 되는 것이다. 따라서 앞, 뒤 문자끼리도 같은지 확인을 해주어야 했다. 이 때 배열값이 벗어나는
// 것을 방지하기 위해 idx +- 1 계산을 if문에 넣었었는데 위 방식대로 구현하자니 if문이 너무
// 지저분하여 배열의 맨 앞과 뒤는 따로 for문에서 제외하고 for문 자체의 범위값을 줄였다.
// 또한, 문자열의 길이가 1일 경우를 대비하여 따로 if문을 구현하였다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    const int MOD = 1000000007;
    string str;

    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> str;
        long long answer = 1;
        // 이 다음에 나올 if문은 문자열의 길이가 1일 경우 오류를 발생하게 된다.
        // 따라서 따로 출력을 해야한다.
        if (str.size() == 1)
        {
            cout << "Case #" << iter + 1 << ": " << answer << '\n';
            continue;
        }
        // 맨 앞과 뒤는 배열값을 벗어나는지 확인을 해야하지만 상술한대로 if문이 너무
        // 더러워지므로 따로 빼내어 구현하였다.
        if (str[0] != str[1])
            answer *= 2;
        if (str[str.size() - 2] != str[str.size() - 1])
            answer *= 2;
        for (int i = 1; i < str.size() - 1; ++i)
        {
            int cur = 1;
            if (str[i - 1] != str[i])
                ++cur;
            if (str[i] != str[i + 1] && str[i - 1] != str[i + 1])
                ++cur;
            answer = answer * cur % MOD;
        }
        cout << "Case #" << iter + 1 << ": " << answer << '\n';
    }
    return 0;
}