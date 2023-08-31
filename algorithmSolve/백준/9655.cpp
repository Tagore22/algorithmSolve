#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 게임이론 문제다. 즉 양쪽이 서로 최선을 다할때 원하는 결과를 얻는 문제다.
// 익숙치 않은 분야여서 좀 긴장했는데 수월했다. 사실상 백트래킹이랑 비슷했다.
// 3개 이상이라면 3개를 빼고 그렇지 않다면 1개씩 빼나간다. 그리고
// 이 너머값의 반전값을 반환하면 된다.

// 자세한 설명은 주석으로 남긴다.

int dp[1000][2];
int N;

// 현재 너머 다음 사람이 실패하여 0을 반환했을때 나는 성공하게 된다.
// 그러므로 이 너머값의 반전값을 출력하면 된다.
bool BackTrack(int num, bool isSk)
{
    if (num <= 0)
        return 0;

    int& ans = dp[num][isSk];
    if (ans != -1)
        return ans;

    ans = 0;
    //  num이 3이상일 경우.
    if (num >= 3)
        ans |= !BackTrack(num - 3, !isSk);

    ans = !BackTrack(num - 1, !isSk);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    int answer = BackTrack(N, true);
    if (answer)
        cout << "SK" << '\n';
    else
        cout << "CY" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}