#include <iostream>
#include <cmath>

using namespace std;

//풀이
//링크안에 있는 경우의 수는 최대 3개인데 1. 좌측 원안에 존재할경우 2. 중앙 직사각형에 존재할 경우 3. 우측 원안에 존재할경우이다.
//다만 원과 직사각형의 중간에 존재한다해도 후술할 조건문에서 모두 검사할수 있기에 상관하지 않는다.
//각 원의 중심과 반지름, 원으로부터의 거리를 미리 계산해놓고 if조건문에서 원과의 거리가 반지름보다 적거나, 직사각형의 범위 안에 존재한다면
//그 선수는 링크안에 존재하기에 answer의 값을 1씩 올린다. 그렇게 모든 선수들의 배열을 순회하여 마지막 answer값을 출력하면 된다.
//다만, 거리를 구할때 제곱근값으로 인한 오차가 있을수 있으므로 그냥 제곱근은 구하지 않고, 반지름값을 제곱하여 비교한다.

pair<int, int> board[50]; //first가 y가 아닌 x임에 주의할것.
int W, H, X, Y, P;

bool InLink(int x, int y)
{
    if (X <= x && x <= X + W && Y <= y && y <= Y + H)
        return true;
    else
        return false;
}

void MakeAnswer()
{
    int rad = H / 2;
    int rad_pow = pow(rad, 2);
    pair<int, int> first_circle = make_pair(X, Y + rad);
    pair<int, int> second_circle = make_pair(X + W, Y + rad);

    int answer = 0;
    for (int i = 0; i < P; ++i)
    {
        int first_dist = pow(board[i].first - first_circle.first, 2) + pow(board[i].second - first_circle.second, 2);
        int second_dist = pow(board[i].first - second_circle.first, 2) + pow(board[i].second - second_circle.second, 2);

        if (first_dist <= rad_pow || second_dist <= rad_pow || InLink(board[i].first, board[i].second))
            ++answer;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> W >> H >> X >> Y >> P;
    for (int i = 0; i < P; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}