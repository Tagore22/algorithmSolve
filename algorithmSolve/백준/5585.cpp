#include <iostream>

using namespace std;

// 풀이.
// 가장 적은 매수의 거스름돈을 만든다는건 최대한 큰 지폐를 많이 써야한다는 것이다.
// 즉 가장 큰 지폐부터 내림차순으로 내려가되 각 상황에서 집을수 있는 가장 많은 매수를 집어나가면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[6] = { 500, 100, 50, 10, 5, 1 };
int money;

void MakeAnswer()
{
    // 원래 지불해야할 금액과 지불한 1000엔을 이용해
    // 거스름돈을 구한다.
    cin >> money;
    money = 1000 - money;
    int answer = 0;

    // 모든 지폐를 내림차순으로 순회하되, 각 상황에서 집을수 있는 가장 큰수를
    // 집어나간다.
    for (int i = 0; i < 6; ++i)
    {
        int cur = money / board[i];
        answer += cur;
        money -= cur * board[i];
    }
    cout << answer << '\n';
}

int main()
{
    MakeAnswer();
    return 0;
}