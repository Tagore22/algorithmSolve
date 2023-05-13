#include <iostream>

using namespace std;

// 풀이.
// 오랜만에 내가 제일 싫어하는 기하학 문제다.
// 이 문제는 과거에 풀었던 CCW를 기반으로 하고 있다.
// 어떠한 선분에서 다른 선분의 두 점을 CCW했을때의 곱이 음수거나 0이라면 두 선분은 교차한다.
// 다만 아래의 예시와 같이

// ㅡ ㅣ 

// ㅡ에서 ㅣ의 두 점을 CCW했을때의 곱은 음수지만 실제로 두 선분은 교차하지 않는다.
// 그렇기 때문에 하나의 선분에서만 검사하지 않고 다른 선분에서도 검사를 해봐야한다.
// 각 검사의 결과가 first와 second라고 할때 모든 경우는 다음과 같다.

// 1. first == second == 0
// 즉 두 선분에서 다른 선분을 CCW했을때 모두 0인 경우이다.
// 이럴때에는 2가지 경우로 다시 나누어지는데 
// 1-1. 두 선분이 겹쳐질때 : 문제에서 겹쳐지는 경우도 교차로 포함한다고 했으니 1을 출력한다.
// 1-2. 두 선분이 떨어져있을때(ex ㅡ ㅡ ) : 0을 출력한다.

// 2. first > 0 || second > 0
// first 혹은 second 둘중 하나라도 1이 되었다는건 한쪽에서 CCW값이 1, 1 혹은 -1, -1이 나와서
// 둘을 곱해 1이 되었다는 뜻인데 이건 어떤 선분 A에서 B를 CCW했을때 양쪽 점이 한곳에 몰려 있다는 뜻이기에
// 교차할수 없다.

// 3. 나머지 경우
// 위를 제외한 모든 경우 교차한다.

// 또한, 각 좌표의 값이 최대 100만에 달하기 때문에 int값을 벗어날수 있어
// long long 값을 사용해야한다.

// 자세한 설명은 주석으로 남긴다.

pair<long long, long long> board[4];

// CCW 구현 함수.
int CheckCCW(const pair<long long, long long>& a, const pair<long long, long long>& b, const pair<long long, long long>& c)
{
    long long result = (b.first - a.first) * (c.second - b.second) - (b.second - a.second)
        * (c.first - b.first);

    if (result > 0)
        return 1;
    else if (result < 0)
        return -1;
    else
        return 0;
}

int CalAnswer()
{
    // 위 상술하였듯 한쪽에서만 그 결과를 판단할수 없기에 두개의 선분 모두를 기준으로 삼아 CCW를 총 4번 호출한다.
    int first = CheckCCW(board[0], board[1], board[2]) * CheckCCW(board[0], board[1], board[3]);
    int second = CheckCCW(board[2], board[3], board[0]) * CheckCCW(board[2], board[3], board[1]);

    // 위 상술한 경우들.
    if (first == 0 && second == 0)
    {
        if (board[0] > board[1])
            swap(board[0], board[1]);
        if (board[2] > board[3])
            swap(board[2], board[3]);
        if (board[1] < board[2] || board[0] > board[3])
            return 0;
        else
            return 1;
    }
    else
    {
        if (first <= 0 && second <= 0)
            return 1;
        else
            return 0;
    }
}

void MakeAnswer()
{
    int answer = CalAnswer();

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}