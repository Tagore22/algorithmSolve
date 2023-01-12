#include <iostream>

using namespace std;

//풀이
//실제로 배열의 중심에서 시작해서 상하좌우로 n번씩 이동하며 풀었다. 다만 이동하는 횟수 n은 첫번째 이동인 오른쪽으로의 이동에서 1 작게 이동해야한다.
//또한 이동횟수 n은 실제로 풀어보면 알겠지만 2부터 2씩 증가해서 N보다 작아야한다. 나머지는 단순히 상술한 내용을 구현하면 된다.

int board[999][999];
int N, find_num;

void MakeAnswer()
{
    pair<int, int> cur = make_pair(N / 2, N / 2); //시작부분임에 동시에 배열의 중심.
    pair<int, int> answer = cur; //찾아야 하는 좌표의 초기화.
    int num = 0; //좌표에 들어가는 내용값.
    board[cur.first][cur.second] = ++num;
    if (num == find_num) //이 부분이 조금 꺼림직했으나 내용값이 변할때마다 늘 이 조건문이 들어가야했다. 다른 풀이로 하지 않는다면 어쩔수가 없다.
        answer = make_pair(cur.first, cur.second);

    for (int i = 2; i < N; i += 2)
    {
        board[--cur.first][cur.second] = ++num; //초기 위로 한칸 이동.
        if (num == find_num)
            answer = make_pair(cur.first, cur.second);
        for (int j = 0; j < i - 1; ++j) //오른쪽으로 이동. n이 1 작다.
        {
            board[cur.first][++cur.second] = ++num;
            if (num == find_num)
                answer = make_pair(cur.first, cur.second);
        }
        for (int j = 0; j < i; ++j) //아래로 이동.
        {
            board[++cur.first][cur.second] = ++num;
            if (num == find_num)
                answer = make_pair(cur.first, cur.second);
        }
        for (int j = 0; j < i; ++j) //왼쪽으로 이동
        {
            board[cur.first][--cur.second] = ++num;
            if (num == find_num)
                answer = make_pair(cur.first, cur.second);
        }
        for (int j = 0; j < i; ++j) //위로 이동.
        {
            board[--cur.first][cur.second] = ++num;
            if (num == find_num)
                answer = make_pair(cur.first, cur.second);
        }
    }

    for (int i = 0; i < N; ++i) //배열을 순회하며 내용값을 출력.
    {
        for (int j = 0; j < N; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }

    cout << answer.first + 1 << ' ' << answer.second + 1 << '\n'; //좌표값 출력.
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> find_num;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}