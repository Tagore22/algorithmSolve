#include <iostream>

using namespace std;

// 풀이.
// 문제를 제대로 안읽어서 한참 헤맨 문제다. 초콜릿의 크기는 2의 제곱수이다.
// 따라서 대략적으로 100만을 넘는 2의 제곱수부터 초기 초콜릿의 크기를
// 2로 나누어가며 현재 크기의 초콜릿이 K개의 초콜릿을 만들 수 있는지 확인
// 하면 된다.

int K;
pair<int, int> answer;

void DivineChoco(int mid)
{
    int sum = 0, idx = 0;
    // 이미 초콜릿의 크기가 K라면 나눌 필요도 없다.
    if (mid == K)
    {
        answer = make_pair(mid, idx);
        return;
    }
    int cur = mid;
    while (cur > 1)
    {
        cur /= 2;
        ++idx;
        // 현재 나눈 초콜릿의 크기를 더했을 때 K보다 커진다면
        // 더하지 않는다.
        sum = sum + cur > K ? sum : sum + cur;
        if (sum == K)
        {
            answer = make_pair(mid, idx);
            return;
        }
    }
}

int main()
{
    cin >> K;
    // 2의 29제곱으로 구현했지만 실제로는 100만에서 가까운 20제곱으로 해도
    // 상관없다.
    int to = (1 << 30);
    // 2씩 나누어가며 K를 만들 수 있는지 확인한다.
    for (int i = 0; i < 30; ++i)
    {
        DivineChoco(to);
        to /= 2;
    }
    cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}