#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// DP라고 분류되어 있지만 사실상 LIS에 해당하는 문제이다.
// 배열을 정렬할때 필요한 최소한의 수를 구하는 것은 이미 LIS에 유명하기 때문인다.
// 다만 예전에 풀어봤음에도 불구하고 기억이 안나 결국 찾아봤다.
// 잊지 말자. 정렬의 원소값 - LIS이다.

// 자세한 설명은 주석으로 남긴다.

vector<int> board;
int N;

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
    {
        int now;
        cin >> now;

        // 현재 원소값이 board의 가장 큰값(기준값)보다 크거나 board가 비었다면 그냥 삽입한다.
        if (board.empty() || board.back() < now)
            board.push_back(now);
        // 그렇지 않다면 현재 위치값을 찾아내어 덮어쓴다.
        else
            *lower_bound(board.begin(), board.end(), now) = now;
    }

    cout << N - board.size() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}