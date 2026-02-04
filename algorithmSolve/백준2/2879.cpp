#include <iostream>

using namespace std;

// 풀이.
// 별의 별 로직이 다 떠올랐으나 간단하게 생각하면 된다. 어렵게 접근하지말자.
// 현재 원소값들을 before, 맞춰야 하는 원소값들을 after라고 명명했을 때 
// 순회하며 before값을 after로 맞추면 된다. 수를 증가시키거나 감소시켜서 맞출 수
// 있는데, 다만 현재 i번째 원소를 증가시킨다고 할 때 그 이후에 수도 똑같이 증가시켜야
// 하는 경우가 있기에 i번째부터 시작하는 두번째 순회를 사용하여 그룹을 묶어 명령의 수를
// 최소화시킬 수 있다.

// 자세한 설명은 주석으로 남긴다.

int N;
int before[1000], after[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> before[i];
    for (int i = 0; i < N; ++i)
        cin >> after[i];

    int answer = 0;
    // 모든 원소들의 값을 맞추어야 하기에 첫번째 순회가 존재한다.
    for (int i = 0; i < N; ++i)
    {
        // 현재 원소를 after값으로 맞출 때까지 반복한다.
        while (before[i] != after[i])
        {
            // 현재 값을 증가시켜야 하는가?
            bool isupper = after[i] > before[i];
            int to = i;
            // i번째 이후에 그룹화할 수 있는 연속된 원소들이 있는지 두번째 순회가 일어난다.
            for (int j = i; j < N; ++j)
            {
                // 이미 값이 맞추어져 있거나, 증가 혹은 감소가 맞지 않다면 범위를 계산하고
                // 반복문을 탈출한다.
                if (after[j] == before[j] || after[j] > before[j] != isupper)
                {
                    to = j - 1;
                    break;
                }
                ++to;
            }
            int cur = isupper ? 1 : -1;
            // 그룹화된 연속된 원소들의 값들을 갱신한다.
            for (int j = i; j <= to; ++j)
                before[j] += cur;
            // 그룹화되었기에 단 한번의 명령어로 취급한다.
            ++answer;
        }
    }
    cout << answer << '\n';
    return 0;
}