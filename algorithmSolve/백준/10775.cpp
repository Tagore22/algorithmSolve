#include <iostream>

using namespace std;

// 풀이.
// 처음에는 2중 for문을 이용해서 풀려고 했으나, 이상하게 너무 쉬웠다.
// 다시 생각해보니 G와 P가 최대 10만으로 2중 for문을 쓰면 연산량이 100억을 넘어가서 풀수 없었다.
// 한참을 생각해도 풀이가 생각이 안나서 힌트를 봤는데 유니언 파인드가 있었다.
// 유니언 파인드는 본래 2개의 배척적인 무리를 구현하기 위해 사용했는데 이번엔 좀 달랐다.
// 이번 문제에서는 두개의 무리로 나누지는 않았으나 하나의 무리를 모두 엮는데 사용되었다.

// 예를 들어 예시가 4, 3, 2, 2, 1이었다고 치자.
// 도킹할수 있는 최대 번호부터 도킹되어야 최대로 도킹될수 있기에 맨뒤부터 붙여보면
// 2, 1번에 도킹한후 3번째 비행기를 도킹할수 없어 최대값은 2가 나온다.
// 이 때 각각 1번째 ~2까지 도킹되는 비행기는 2번 게이트에 도킹되어 ~2 비행기들은 최대 1번 게이트에
// 도킹될수 있다. 이정보들을 모두 묶여주어야 하는데 이때 바로 유니언 파인드가 사용된다.(Merge 함수).

// 자세한 설명은 주석을 참고할것.
// 자료가 묶이는게 중요하다. merge()를 잘 볼것. 2, 2, 1을 예시로 들어볼것.

int board[100000], dock[100001];
int G, P; // 게이트와 비행기수.

void BoardInit()
{
    // 각 비행기들이 도킹될수 있는 값들의 초기화.
    for (int i = 1; i <= G; ++i)
        dock[i] = i;
}

// 각 비행기들이 도킹될수 있는 최대값들을 반환하는 함수.
int find(int rhs)
{
    if (dock[rhs] == rhs)
        return rhs;
    return dock[rhs] = find(dock[rhs]);
}


// ~N 비행기가 도킹될수 있는 최대 번호를 묶는 함수.
void merge(int rhs, int lhs)
{
    rhs = find(rhs), lhs = find(lhs);

    dock[rhs] = lhs;
}

void MakeAnswer()
{
    BoardInit();

    int answer = 0, cur;
    for (int i = 0; i < P; ++i)
    {
        cur = find(board[i]);
        if (cur == 0)
            break;

        merge(cur, cur - 1);
        ++answer;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> G >> P;
    for (int i = 0; i < P; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}