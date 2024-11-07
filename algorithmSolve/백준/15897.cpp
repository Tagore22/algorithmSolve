#include <iostream>

using namespace std;

// 풀이.
// 문제를 요약하자면 N이 주어질때 N을 1 ~ N으로 나누고 나머지가 존재할시 1을 더한 총값을 출력하는 문제다.
// 하지만 그냥 for문으로 순회하면 10억 이상의 연산량이 나와서 시간초과가 난다. 결과적으로 수학적 계산을
// 응용하여 순회하지 않고 총값을 구해야하는데 이런 수학적 접근은 나에게 있어서 너무 어려웠다. 구글링을 해보니
// 조화수열이라던가 이런저런것들이 나왔다. 수학을 더 공부해야하나...

int main()
{
    int n;
    cin >> n;

    long long answer = n;
    n -= 1;
    int num = 1;
    while (n / num > 100000)
    {
        answer += num * (n / num - n / (num + 1));
        ++num;
    }
    for (int i = 1; i <= n / num; ++i)
        answer += n / i;
    cout << answer << '\n';
    return 0;
}