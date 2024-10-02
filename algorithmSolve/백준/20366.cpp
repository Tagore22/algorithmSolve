#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 뭐랄까... 다 풀었는데 실수를 했달까.. ㅎㅎ.. 문제의 핵심은 최대 600개의 원소중 서로 다른 4개를
// 골라서 2개씩 더해 그 합의 차이가 최소값인 경우를 출력하는 것이다. 하지만 모든 경우를 둘러보기에는
// 600의 4제곱이기에 절대로 불가능했다. 따라서 미리 2개씩 고르는 경우들을 계산한후 그 값들에서 조건을
// 만족하는 것을 다시 2개를 찾기로 했다. 미리 2개씩 고르는 경우는 600의 2제곱이므로 36만밖에 되지 않는다.
// 그 이후 앞서 계산한 최대 36만개의 원소를 순회하며 인접한 원소가 서로 다른 눈덩이를 골랐을 경우 그 차이값의
// 최소값을 구한다. 정렬된 상태이기에 인접한 값과의 차이가 제일 작기 때문이다. 좋은 로직이었지만 하술할
// 한가지 크나큰 실수로 인해 한시간은 헤맨것 같다. 그래도 정답율이 30퍼에 육박하고 나 스스로 풀었기에 괜찮다.

// 자세한 설명은 주석으로 남긴다.

struct snow
{
    int first;
    int second;
    int sum;
};

vector<snow> sums;
int board[600];
int N;

// 두 눈덩이를 비교하여 정렬하기 위한 함수. 높이값을 기준으로 함.
bool SortFunc(const snow& l, const snow& r)
{
    if (l.sum != r.sum)
        return l.sum < r.sum;
    else if (l.first != r.first)
        return l.first < r.first;
    else
        return l.second < r.second;
}

void MakeAnswer()
{
    // 모든 원소들을 순회하며 2개를 골라 미리 계산한다.
    // 기존에는 윗덩이가 아랫덩이보다 작아야 하는 조건이 있었으나,
    // 생각해보면 필요없다. 아무거나 큰것이 아래에 있고 작은것이 위에 있으면 되기 때문에
    // 중복된 계산만 아니라면 필요가 없다.
    for (int i = 0; i < N - 1; ++i)
        for (int j = i + 1; j < N; ++j)
            sums.push_back(snow{ i, j, cur });

    sort(sums.begin(), sums.end(), SortFunc);
    // answer는 원래 987654321이었다. 거의 습관과도 같이 987654321로 초기화했는데 이게 바로
    // 상술한 치명적인 실수다. 주어진 값의 최대값은 10억으로 두 원소값의 합이 20억일 경우가 있다.
    // 그리고 다른 합이 10일 경우도 있을 것이다. 이때 두 수의 차이는 19억을 뛰어넘는데 이럴 경우
    // answer가 더 작다보니 검출이 되지 않는 것이다. 바로 이 부분이 문제였다.
    int answer = 2000000001;
    // 모든 2개씩 만들어진 총합을 순회한다.
    for (int i = 0; i < sums.size() - 1; ++i)
    {
        // 인접한 값과 서로 다른 2개의 눈덩이를 고른 상태라면 가능한 경우이므로 최소값 answer를 갱신한다.
        if (sums[i].first == sums[i + 1].first || sums[i].first == sums[i + 1].second ||
            sums[i].second == sums[i + 1].first || sums[i].second == sums[i + 1].second)
            continue;
        answer = min(answer, sums[i + 1].sum - sums[i].sum);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}