#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

// 2295번의 다른 풀이. bitset을 사용하여 속도는 확실히 빨라졌지만 메모리가 많이 늘어났다.
// 오늘은 배울것도 많은 날인데 bitset은 거의 존재조자 까먹고 있었다. 한마디로 표현하자면
// bit의 배열이다. 템플릿 매개변수는 최대로 표현하고자 하는 정수의 값이다. 이것을 배열처럼
// array[]안에 값으로 구현한다. 자세한 것은 STL책을 521p부터 살펴보자.

int board[1000];
// 상술한 bitset값. 
bitset<200000001> sum;
int N;
const int MAXNUM = 200000000;

// a, b, c의 합인 d가 배열안에 존재해야함.
// 즉 a + b를 구해놓은후 배열안의 어떠한 두 수 y - x가 
// a + b와 같다면 y가 가장 큰수가 된다.

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            // 배열의 원소값은 최대 2억을 넘지 않는걸 이용한 가지치기.
            if (board[i] + board[j] <= MAXNUM)
                sum[board[i] + board[j]] = 1; // 합의 값을 비트 1로 바꾸어 존재를 표시한다.

    sort(board, board + N);

    for (int i = N - 1; i >= 0; --i)
        for (int j = i; j >= 0; --j)
            if (sum[board[i] - board[j]] == 1)
            {
                cout << board[i] << '\n';
                return;
            }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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