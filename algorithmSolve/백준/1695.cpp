#include <iostream>
#include <cstring>

using namespace std;

//풀이
//처음에는 왼쪽으로만 혹은 오른쪽으로만 수를 추가하는 함수 2개를 만들어서 추가된 수가 적은쪽을
//출력하게끔 구현했었으나 전혀 답이 아니었다. 생각해보니 무조건 왼쪽 혹은 오른쪽이 아니라
//어느때에는 왼쪽, 어느때에는 오른쪽인 복합적인 경우가 존재했는데 이걸 간과했었다.
//그래서 2가지 경우를 모두 배낭형식으로 하기엔 N이 너무나도 컸기에 DP를 이용해야했다.

//따라서 시작점 from과 끝점 to를 0과 N-1로 두고, from과 to가 같거나 from이 더 커지는 때까지
//계속 순회를 한다. 이때 board[from]과 board[to]가 같다면 굳이 수를 추가하지 않아도 됨으로
//아무것도 하지 않고 from+1, to-1번째를 확인하면 되고, 둘이 다르다면 왼쪽 혹은 오른쪽에
//수를 추가하여 두 경우중 추가한 수가 더 적은쪽을 출력하면 된다.

int board[5000], cashe[5000][5000];
int N;

int AddElement(int from, int to)
{
    if (from >= to)
        return 0;

    int& ans = cashe[from][to];
    if (ans != -1)
        return ans;

    ans = 5000;

    //현재 양 끝인 board[from]과 board[to]를 비교한다.
    if (board[from] == board[to]) //두 값이 같은 경우. 아무것도 추가하지 않아도 됨으로 다음으로 넘어감.
        ans = AddElement(from + 1, to - 1);
    else                          //두 값이 다른 경우. 왼쪽 혹은 오른쪽에 추가하되 더 적은 수의 추가 되는 경우를 체크한다.
        ans = min(AddElement(from, to - 1) + 1, AddElement(from + 1, to) + 1);

    return ans;
}

void MakeAnswer()
{
    int answer = AddElement(0, N - 1);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}