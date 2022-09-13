#include <iostream>
#include <map>

using namespace std;

//N은 최대 40이므로 시간복잡도는 2의 40제곱이 되어 시간내에 다 풀수가 없다.
//그래서 수열을 절반으로 나누어 2의 20제곱 * 2로 걸리는 시간을 줄인다.
//중요한 부분은 아래 주석처리 된 곳인데 부분수열이라 함은 최소 한개의 원소를 가지고 있어야 한다.
//하지만 초기값이 0이기에 S가 0일때 왼쪽 부분 수열과 오른쪽 부분 수열에서 각각 아무 원소도 더하지 않을때
//또한 포합되기에 이 부분을 빼줘야 한다.

map<int, int> sum_list;
int board[40];
int N, S;
long long answer = 0;

void LeftSide(int idx, int sum)
{
    if (idx == N / 2)
    {
        answer += sum_list[S - sum];
        return;
    }
    LeftSide(idx + 1, sum);
    LeftSide(idx + 1, sum + board[idx]);
}

void RightSide(int idx, int sum)
{
    if (idx == N)
    {
        ++sum_list[sum];
        return;
    }
    RightSide(idx + 1, sum);
    RightSide(idx + 1, sum + board[idx]);
}

void MakeAnswer()
{
    RightSide(N / 2, 0);
    LeftSide(0, 0);
    answer = S == 0 ? answer - 1 : answer; //S가 0이며 LeftSide, RightSide에서 각각 아무 원소도 더하지 않았을때 sum_list[0]에 1이 추가된 상태 
    cout << answer << '\n';                //그러나 부분 수열은 최대 한개이상의 원소를 지녀야 함으로 포함되어서는 안된다.
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}