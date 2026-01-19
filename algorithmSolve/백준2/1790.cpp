#include <iostream>
#include <string>
using namespace std;

// 풀이.
// 30퍼답게 어렵다. 거의 다 짜냈는데 정신이 멀쩡하지 않아 작은 부분에서
// 균열이 일어난다. 나중에 다시 볼 것.

int CalPow(long long num)
{
    int ans = 0;
    while (num >= 10)
    {
        ++ans;
        num /= 10;
    }
    return ans + 1;
}

int main()
{
    int N, K;
    cin >> N >> K;

    if (K < 9 && K > N)
    {
        cout << -1 << '\n';
        exit(0);
    }
    long long len = 0, idx = 9, pow = 1;

    // 1. 각 자리수 그룹을 지나가며 K를 줄인다.
    while (true)
    {
        if (len > N)
        {
            cout << -1 << '\n';
            exit(0);
        }
        // 개선: > 를 >= 로 변경 (정확히 딱 맞을 때도 멈춰야 함)
        if (pow * idx >= K)
            break;
        K -= pow * idx;
        len += idx;
        idx *= 10;
        ++pow;
    }

    // 아래부터 완전히 새로 바꾼 부분
    // 원래: idx /= 9; 하고 이상한 while 돌림 → 완전히 틀림
    // 새로: 올바르게 현재 자리수(digit)와 시작 숫자 계산
    int digit = pow;                    // 현재 자리수 (1,2,3,...)
    long long start_num = 1;
    for (int i = 1; i < digit; i++) start_num *= 10;  // 1, 10, 100, ...

    // 남은 K를 digit으로 나눠서 몇 번째 숫자인지 구함
    long long numbers_to_skip = (K - 1) / digit;   // 0부터 시작해서 몇 개 건너뛸지
    long long target_num = start_num + numbers_to_skip;

    // target_num이 N을 넘으면 -1
    if (target_num > N) {
        cout << -1 << '\n';
        return 0;
    }

    // 해당 숫자의 몇 번째 자리인지
    int pos_in_num = (K - 1) % digit;   // 0부터 시작

    // 최종 정답 출력
    string str = to_string(target_num);
    cout << str[pos_in_num] << '\n';

    return 0;
}