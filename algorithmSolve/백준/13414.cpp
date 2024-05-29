#include <iostream>
#include <unordered_map>

using namespace std;

// 풀이.
// 문제에서는 먼저 입력을 모두 받고 중복을 지운후 맨앞부터 K개를 출력하라고 했으나
// 이러면 최대 L개를 두번 순회해야했다. 그래서 머리를 굴리기로 했는데 처음 L개를 입력받을때
// 현재 학번이 몇번 등장했는지를 pair<>를 이용하여 따로 저장했다. 그 이후 한번더 L번을 순회하며
// 현재 학번이 마지막으로 등장했을때 출력을 하게끔 구현했다. 놀랍게도 이 문제는 26퍼센트짜리였다.
// 또한 속도가 증가하나 궁금해서 pair<>를 string이 아닌 int로 바꾸었는데 아예 답이 안나왔다.
// 왜인지 모르겠다.

// P.S 예시에도 주어지듯 학번이 0으로 시작하는 것들이 있다. 이럴 경우 앞의 0이 무시되어 틀리게 된다.

// 자세한 설명은 주석으로 남긴다.

pair<string, int> board[500000];
unordered_map<string, int> check;
int K, L;

void MakeAnswer()
{
    // unordered_map과 연계하여 현재 학번의 등장횟수까지 저장한다.
    for (int i = 0; i < L; ++i)
    {
        cin >> board[i].first;
        board[i].second = check[board[i].first] + 1;
        ++check[board[i].first];
    }
    // 한번더 최대 L번 순회하며 현재 학번이 마지막으로 등장한 때라면 그 학번을 출력한다.
    for (int i = 0; i < L; ++i)
    {
        if (board[i].second == check[board[i].first])
        {
            cout << board[i].first << '\n';
            --K;
        }
        if (K == 0)
            break;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K >> L;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}