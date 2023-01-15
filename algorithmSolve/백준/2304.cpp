#include <iostream>
#include <algorithm>

using namespace std;

//푸는 방식이 꽤나 복잡한 문제였다. 왼쪽에서부터 진행하되, 다음 높이가 더 작으면 무시하고, 더 크다면 갱신하면 되었으나,
//가장 높은 높이에서 내려올때가 문제였다. 결국엔 왼쪽, 오른쪽에서 한번씩 순회하였는데 어차피 가장 큰점을 만난 이후 반복문에서
//바로 나오기 때문에 어차피 두 반복문의 연산값은 최대 N임을 증명할수 있기 때문이다.

//풀이
//위 상술하였듯 왼쪽에서 한번 오른쪽에서 한번 주어진 배열을 순회한다. 다만, 가장 높은 높이와의 연산이 끝난 이후, from이 최대 높이를
//가리키는 원소일때는 순회를 멈추어도 된다. 설령, 가장 높은 높이가 왼쪽과 오른쪽 중간 어디쯤인가에 2개가 있다고 해도 그 두 높이의 중간은
//어차피 무시되기 때문이다.

pair<int, int> board[1000];
int N, max_num = -1;

void MakeAnswer()
{
    sort(board, board + N);
    int from = 0, to; //이전 인덱스와 현재 인덱스.
    int answer = (board[N - 1].first - board[0].first + 1) * max_num; //최대값.
    for (int i = 1; i < N; ++i) //왼쪽부터 순회하되, 가장 높은 높이와의 연산이 끝난 이후(board[from].second == max_num)라면 반복문 탈출.
    {
        if (board[from].second == max_num) //가장 높은 높이와의 연산이 끝난 이후인가?
            break;

        to = i; //현재 인덱스의 갱신.

        if (board[from].second < board[to].second) //현재 가르키는 높이가 더 크다면 이전 부분을 지워준다.
        {
            answer -= (board[to].first - board[from].first) * (max_num - board[from].second);
            from = i; //현재 인덱스가 이전 인덱스(연산이 끝난)가 된다.
        }
    }

    from = N - 1;
    for (int i = N - 2; i >= 0; --i) //오른쪽 순회. 
    {
        if (board[from].second == max_num)
            break;

        to = i;

        if (board[from].second < board[to].second)
        {
            answer -= (board[from].first - board[to].first) * (max_num - board[from].second);
            from = i;
        }
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i].first >> board[i].second;
        max_num = max(max_num, board[i].second);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}