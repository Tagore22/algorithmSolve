#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 자세히 보면 굉장히 쉬운 문제이다. 구하고자 하는 수는 4와 7로만 구성되어있기 때문에 
// 매번 뒤에 4 혹은 7을 추가해주면 된다. 또한, B의 최대값이 10억이기 때문에 모든 경우를
// 구하는 때에도 2의 9제곱만큼밖에 되지 않기에 시간도 충분하다.

vector<int> answer;
int A, B;

void BackTrack(long long sum)
{
    if (sum >= B)
        return;

    long long now = (sum * 10) + 4;
    if (A <= now && now <= B)
        answer.push_back(now);
    BackTrack(now);

    now = (sum * 10) + 7;
    if (A <= now && now <= B)
        answer.push_back(now);
    BackTrack(now);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> A >> B;
    BackTrack(0);
    cout << answer.size() << '\n';
    return 0;
}