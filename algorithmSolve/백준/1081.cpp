#include <iostream>

using namespace std;

// 무척이나 어려운 문제였다. 특히나 수학적 접근을 요구로 하기에 더욱 그러지 않았나 싶다.
// 풀이 방식은 1의 자리부터 하나씩 올라가며 각 자리수에서 1 ~ 9의 등장횟수를 구하여
// 모두 더하는 것이다.

// 자세한 설명은 주석으로 남긴다.

// num의 각 자리수들의 총합을 반환하는 함수. 입력받는 수는
// 최대 20억으로 int로 해도 상관은 없으나 후술할 연산들에 의해
// int로 변환될 가능성이 존재하기에 long long으로 선언하였다.
long long CalSum(long long num)
{
    long long ans = 0;

    // for문안에 계산식이 생각보다 복잡했다. 유념할 것.
    for (long long i = 1; i <= num; i *= 10)
    {
        // 현재 자리수보다 큰 수들. 예를 들어 1234, 현재 10의 자리일때 12를 뜻함.
        long long upper = num / (i * 10);
        // 현재 자리수. 1234, 3을 뜻함.
        long long cur = num / i % 10;
        // 현재 자리수보다 작은 수들. 1234, 4를 뜻함.
        long long lower = num % i;

        // upper는 1234, 현재 10의 자리일때 1200을 의미하는데 10의 자리에서
        // 0 ~ 9는 모두 완전한 사이클이 가능하다. 그렇기에 0 ~ 9를 더한 45가
        // 각 자리수의 개수만큼 등장하고 이것이 upper개만큼 다시 존재한다.
        ans += upper * 45 * i;
        // 10의 자리인 3보다 작은 1 ~ 2는 1200 ~ 1229까지 다시 한번 완전한 사이클이
        // 가능하다. 마찬가지로 자리수의 개수만큼 등장한다.
        ans += i * (cur * (cur - 1) / 2);
        // 10의 자리인 3은 완전한 사이클이 불가능하며 그 lower의 개수만큼 등장한다.
        ans += cur * (lower + 1);
    }
    return ans;
}

int main()
{
    int L, U;
    cin >> L >> U;

    cout << CalSum(U) - CalSum(L - 1) << '\n';
    return 0;
}