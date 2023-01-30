#include <iostream>
#include <algorithm>

using namespace std;

//풀이
// 이 문제는 2가지 중요한 점이 있다.
// 1. 양수와 음수로 나누어 처리한다.
// 당연하게도 양수와 음수를 동시에 처리한다면 양쪽으로 왔다갔다 두번 처리해야함으로 나누어 처리해야 움직임을 최소화할수 있다.
// 
// 2. 한번에 M개의 책을 집을수 있을때 어떤 책을 집는가가 중요하다. 
// 책의 수 N이 M으로 나누어 떨어진다면 상관없으나, 그렇지 않은 경우도 있기 때문인데, 이러한 경우 현재 집을수 있는 가장 위치가 
// 먼 책을 집으면 된다. 만약 1, 2, 3, 4의 책이 있고, 3권의 책을 한번에 집을수 있다면 반드시 한권을 위해서 따로 움직여야 하는데
// 가장 가까운 1을 따로 움직인는 것이 가장 적게 움직이는 방법이기 때문이다.
// 
// 따라서, 책의 위치를 입력받아 정렬을 하여 양수와 음수로 나누어 처리해준다. 가장 왼쪽과 오른쪽이 절대값이 가장 큰수이므로 이곳부터
// 음수와 양수를 나누는 경계까지 순회하며 이동거리를 더해나간다. 그후 마지막에 가장 거리가 긴곳을 왕복이 아닌 편도로 두어
// 그 편도값을 빼버리고 출력하면 된다.

int board[50];
int N, M, boundary = 0;

void MakeAnswer()
{
    sort(board, board + N);

    int answer = 0;
    for (int i = 0; i < boundary; i += M) //수가 가장 큰 왼쪽부터 경계까지 순회한다.
        answer += abs(board[i] * 2);      //왕복값을 더하되 음수이므로 그 절대값을 더해준다.

    for (int i = N - 1; i >= boundary; i -= M)
        answer += board[i] * 2;

    answer -= max(abs(board[0]), board[N - 1]); //거리가 가장 긴곳을 편도로 두어 기존에 왕복값에서 편도값을 빼준다.

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        if (board[i] < 0)
            ++boundary;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}