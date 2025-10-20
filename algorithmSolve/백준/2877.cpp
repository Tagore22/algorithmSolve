#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 그리 어려운 문제는 아닌데 K번째 찾기류의 문제를 푼지 오래된 까닭에 
// 조금 헤맸다. 로직은 다음과 같다.

// 1. 누적합을 이용하여 주어지는 K번째 수가 몇자리인지 idx값을 찾는다.
// 2. idx - 1번째 누적합을 K에서 제외하여 idx번째에서 만들 수 있는 수의 절반을
// 넘겼다면 현재 자리는 7이고 그렇지 않다면 4이다.
// 3. 현재 자리가 7이라면 idx번째에서 만들 수 있는 수의 절반을 제외한다.
// 4. 1번으로 되돌아간다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    int K;
    cin >> K;

    int cur = 1, sum = 0;
    vector<int> num(1, 0), sums(1, 0);
    while (true)
    {
        cur *= 2;
        // 처음에는 K가 최대 10억이기에 누적합을 구할 때 최대 10억까지만 구하면 되는줄
        // 알았으나 10억번째 수의 누적합은 당연히 10억개를 훨씬 넘어선다. 따라서
        // 대략 20억개까지의 누적합을 지닌 수들까지 전부 계산한다. 후술하겠으나
        // 이 풀이에서는 누적합을 이용하여 자리수를 계산하기 때문이다.
        // 아니면 if문의 내용을 다시 sum + cur > 10억으로 두되, while문의 맨 마지막에
        // 배치하는 것도 좋을 듯 싶다.
        if (sum + cur > 2000000000)
            break;
        sum += cur;
        num.push_back(cur);
        sums.push_back(sum);
    }
    // K번째 수가 몇개의 총합을 지닌지를 이용해서 몇자리인지를 구한다.
    int idx = lower_bound(sums.begin(), sums.end(), K) - sums.begin();
    string answer = "";
    K -= sums[idx - 1];
    // idx자리만큼 반복한다. 다만 0에서 시작하지 않고 idx부터 0으로 줄어듬에
    // 주의해야한다. 말 그대로 idx는 자리수를 뜻하기 때문이다.
    for (int i = idx; i > 0; --i)
    {
        if (K > num[i] / 2)
        {
            answer += '7';
            // 현재 자리가 7이라는 것은 4에서 시작하여 최소 num[idx]개를 지나며
            // 7까지 왔다는 것이기에 K에서 제외후 다음으로 넘어간다.
            K -= num[i] / 2;
        }
        else
        {
            answer += '4';
        }
    }
    cout << answer << '\n';
    return 0;
}