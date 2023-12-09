#include <iostream>

using namespace std;

// 풀이.
// 어제 풀었던 문제랑 비슷하게 최대공약수를 구하는 문제다. 각 가로수들의 위치가 주어질때
// 모든 가로수들 사이의 거리를 동일하게끔 만들기 위해 최소한으로 추가해야하는 가로수들의 수를 구해야한다.
// 모든 가로수들 사이의 거리는 공약수로 구할수 있는데 가로수를 최소한으로 추가하기 위해서는 최대 공약수를
// 찾아야 한다. 이 거리를 구한후 현재 거리 / 최대 공약수 - 1을 하면 각 가로수들 사이에 추가되는 수를 구할수
// 있으며 이 수들의 총합을 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[100000];
int N;

// 최대 공약수를 구하는 함수.
int GDC(int lhs, int rhs)
{
    if (rhs == 0)
        return lhs;
    return GDC(rhs, lhs % rhs);
}

void MakeAnswer()
{
    // 최초의 거리를 위해 0번, 1번 원소값은 미리 빼놓는다.
    int here = board[0], next = board[1];
    int dist = next - here;
    here = next;
    // 이후 모든 가로수들을 순회하며 각 가로수들 사이 거리의 최대공약수를 찾는다.
    for (int i = 2; i < N; ++i)
    {
        next = board[i];
        dist = GDC(dist, next - here);
        here = next;
    }
    int answer = 0;
    // 위 상술하였듯 추가해야 하는 가로수를 구하는 점화식은
    // 각 가로수들의 사이 거리 / 최대 공약수 - 1이다.
    for (int i = 1; i < N; ++i)
        answer += (board[i] - board[i - 1]) / dist - 1;

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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