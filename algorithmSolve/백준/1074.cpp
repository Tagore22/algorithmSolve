#include <iostream>
#include <cmath>

//평범한 분할정복 문제이다. 주어진 장판을 4등분해나가며 기저사례에 해당될 경우 약간의 브루트포스로 답을 출력한다.
//이 문제를 풀기 위해선 2가지 값이 필요한데
//1. 현재 y축값 혹은 x축값을 2로 나눈 값 div
//2. 그 div의 제곱값 mul
//이 2가지가 필요하다. 각 좌표값을 div로 나눈 나머지값은 장판을 4등분 하였을때 새로운 좌표값이고, 각 좌표값을 div로 나눈 값은
//현재 장판에서 구할수 있는 순번의 수(총 순번에 더해져감)이다. 즉, 현재 장판에서 구할수 있는 순번을 더하고 4등분하여 다음 장판으로
//넘어가는 재귀를 이용하여 기저사례인 y축값 혹은 x축값이 2일때 마지막 값들을 추가하여 총 순번을 구한다.

using namespace std;

int N, r, c;
int answer = 0;

//순회 순서가 왼쪽 상단, 우측 상단, 왼쪽 하단, 우측 하단이기에 x값을 나눈 값에는 mul만을 곱하지만
//y값을 나눈 값에는 mul * 2를 해줘야한다.

void MakeAnswer(int side_size, int y, int x)
{
    if (side_size == 2)
    {
        answer += y * 2;
        answer += x * 1;
        cout << answer << '\n';
        return;
    }

    int div = side_size / 2;
    int mul = div * div;
    int next_y = y % div;
    answer += y / div * mul * 2; //순회 순서에 의해 2를 추가로 곱해줌.
    int next_x = x % div;
    answer += x / div * mul;

    MakeAnswer(side_size / 2, next_y, next_x);
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> r >> c;
}

int main()
{
    Input();
    MakeAnswer(pow(2, N), r, c);
    return 0;
}