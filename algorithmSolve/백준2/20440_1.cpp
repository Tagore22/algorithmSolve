#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 풀이.
// 정말 어려운 문제였다. 값 / 좌표 압축이라는 개념이었는데 좌표값이 너무 큰 경우에
// 사용되었다. 문제에서도 시간이 최대 21억이라는 큰 값이기 때문에 따로 배열을
// 만들 수 없는데 이 때, 따로 압축 배열을 만들고 이곳에 기존값들을 전부 집어넣어
// 마치 map 처럼 사용한다. 복잡한 내용이기에 주석을 좀 더 자세히 많이 달 듯하다.

// 자세한 설명은 주석으로 남긴다.

// 기존 입력값.
pair<int, int> board[1000000];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    // 압축 배열.
    vector<int> trans;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i].first >> board[i].second;
        // 압축 배열에 따로 값들을 넣는다.
        trans.push_back(board[i].first);
        trans.push_back(board[i].second);
    }
    // 2단 콤보인데 정렬 후, 중복을 지운다.
    sort(trans.begin(), trans.end());
    trans.erase(unique(trans.begin(), trans.end()), trans.end());
    // 최대 범위를 알기 위한 누적합 배열. 마치 차등 배열 트릭과 비슷하다.
    // 다만 문제에서 반열림 범위를 제시했기에 l, r이 있을 때 --[r + 1]이 아닌
    // --[r]이 되어야 한다.
    vector<int> sum(trans.size());
    for (int i = 0; i < N; ++i)
    {
        int from = board[i].first;
        int to = board[i].second;
        // 실제 위치값들을 찾아낸다.
        int fidx = lower_bound(trans.begin(), trans.end(), from) - trans.begin();
        int tidx = lower_bound(trans.begin(), trans.end(), to) - trans.begin();
        // 위에서 얻어낸 위치값들을 이용하여 차등 배열 트릭을 사용한다.
        ++sum[fidx];
        --sum[tidx];
    }
    int ans = sum[0];
    // 자세히 보면 기존값에서 차등 배열값을 더하는 내용이 없는데
    // 이는 차등 배열값의 초창기 값이 0이기 때문에 따로 더하지 않아도 상관없기 때문이다.
    for (int i = 1; i < sum.size(); ++i)
    {
        sum[i] += sum[i - 1];
        ans = max(ans, sum[i]);
    }
    bool isgreater = false;
    pair<int, int> answer = make_pair(-1, -1);
    for (int i = 0; i < sum.size(); ++i)
    {
        // 맨 처음 최대값에 도달한 위치가 바로 가장 왼쪽 범위의 시작이다.
        if (!isgreater && ans == sum[i])
        {
            answer.first = i;
            isgreater = true;
        }
        // 최대값을 만난 직후 가장 첫째로 최대값이 아닌 지역이 범위의 가장 오른쪽 부분이다.
        if (isgreater && sum[i] < ans)
        {
            answer.second = i;
            break;
        }
    }
    cout << ans << '\n';
    cout << trans[answer.first] << ' ' << trans[answer.second] << '\n';
    return 0;
}