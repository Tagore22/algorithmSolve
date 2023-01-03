#include <iostream>
#include <algorithm>

using namespace std;

//풀이
//가장 많은 이득을 남기는 방법은 당연하게도 가장 비싼 가격을 내는 손님들에게 파는 방법이다.
//그러므로, 가격을 정렬하면 되는데 한가지 생각해야할것은 계란이 손님의 수보다 적을때이다.
//이럴 경우 모든 손님에게 계란은 파는 선택지는 없기에 최대의 이익을 얻기 위해 M - N번째 손님부터 팔아야 한다는 것이다.
//다만, 계란이 손님보다 많을 경우는 모든 손님에게 팔수 있으므로 제외된다.
//따라서, M - N이 0보다 클 경우는 M - N부터, 그렇지 않을 경우 0부터 정렬된 배열을 순회하며 현 가격 *  팔수 있는 계란의 수를 갱신해
//가면 되지만, 마지막으로 한가지 생각해야할 경우는 대표적으로 마지막 손님의 경우일때다. 마지막 손님보다 더 큰 가격을 제시하는 손님이
//없기에 이럴 경우 마지막 손님 * 1의 이득밖에 보지 못하기에 결과적으로 현 가격 * 팔수 있는 계란의 수 즉,
//board[i] * (M - i)를 하여 그 처리를 해주어야만 최대값을 얻을 수 있다.

int board[1000];
int N, M;

void MakeAnswer()
{
    sort(board, board + M);

    pair<int, int> answer = make_pair(0, 0);
    int from = M - N > 0 ? M - N : 0; // 계란보다 손님이 많을 경우 배열을 굳이 0부터 돌지 않아도 된다.

    for (int i = from; i < M; ++i)
        if (answer.second < board[i] * (M - i))
            answer = make_pair(board[i], board[i] * (M - i)); // 남은 손님이 계란의 수보다 적을 경우를 처리해줘야 한다.

    cout << answer.first << ' ' << answer.second << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}