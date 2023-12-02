#include <iostream>

using namespace std;

// 풀이.
// 주어지는 7개의 자연수들중 홀수들의 합과 가장 작은 홀수를 출력하되, 홀수가 존재하지 않는다면 -1을 출력한다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    int answer = 0, min_num = 100;
    // 7개의 자연수를 입력받는다.
    for (int i = 0; i < 7; ++i)
    {
        int num;
        cin >> num;
        // 홀수라면
        if (num % 2 == 1)
        {
            // 최소값을 갱신하고 더한다.
            min_num = min(min_num, num);
            answer += num;
        }
    }

    // 총합이 0이 아니라면 즉, 한번이라도 홀수가 존재했다면 총합과 최소값을 출력한다.
    if (answer != 0)
        cout << answer << '\n' << min_num << '\n';
    // 총합이 0이라면 즉, 한번이라도 홀수가 존재하지 않았다면 -1을 출력한다.
    else
        cout << -1 << '\n';
    return 0;
}