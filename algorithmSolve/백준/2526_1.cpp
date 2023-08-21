#include <iostream>

using namespace std;

// 2526번의 좀더 최적화된 풀이.
// board배열을 bool타입이 아닌 int타입으로 바꾸면 등장 여부뿐만 아니라 등장 순서까지
// 한번에 알아낼수 있다. 

// 자세한 설명은 주석으로 남긴다.

// 기존 bool 배열에서 int 배열로 변경되었다. 위 상술한대로 등장 여부뿐만 아니라 등장 순서까지
// 한번에 저장할수 있다.
int board[97] = { 0 };
int N, P;

void MakeAnswer()
{
    // 현 등장 순서를 저장하는 count 변수. 
    int count = 1;
    board[N] = count;
    int cur = N;
    while (true)
    {
        cur = cur * N % P;
        // 이미 등장한 수가 다시 등장할 경우, 모든 등장 횟수 - 현재 수의 등장 순서 + 1로 답을 구한다.
        if (board[cur] != 0)
        {
            cout << count - board[cur] + 1 << '\n';
            return;
        }
        board[cur] = ++count;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> P;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}