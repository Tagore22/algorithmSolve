#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

//풀이
//단순한 정렬 문제다. 비교 조건은 등장 빈도수, 등장 순서 2가지인데 등장 빈도수를 비교할때 등장 하는 최대값이 10억이기에 이것을
//모두 배열로 담아낼수가 없어 map을 사용해야 했다. 또한, 상술하였듯이 빈도수가 같을때 대신 비교해야할 등장순서까지 포함해야했으므로
//map<int, pair<int,int>>를 사용해야한다. 나머지는 평범한 비교 함수 하나를 구현하는것 뿐이다.

int board[1000];
map<int, pair<int, int>> check; //각각 수, 등장 순서에 대한 우선순위, 등장 빈도수.
int N, C;

bool SortFunc(int a, int b)
{
    if (check[a].second > check[b].second) //빈도수 자체가 차이난다면 바로 비교가능.
        return true;
    else if (check[a].second == check[b].second) //빈도수가 같다면 우선순위를 비교한다.
        return check[a].first > check[b].first;
    else
        return false;
}

void MakeAnswer()
{
    sort(board, board + N, SortFunc);
    for (int i = 0; i < N; ++i)
        cout << board[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> C;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        if (check[board[i]].first == 0)
            check[board[i]].first = N - i;
        ++check[board[i]].second;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}