#include <iostream>

using namespace std;

//각 자리의 좌표는 해당 수를 4로 나눈 값과 나머지값으로 구할수있다.
//y값 : 수를 4로 나눈 나머지값(다만 0일시에는 4로 바꿔줌)
//x값 : 수를 4로 나눈 값(다만 나머지값이 있을 경우 +1 해줌)

int from, to;

void MakeAnswer()
{
    int from_X = from / 4;
    from_X = from % 4 != 0 ? from_X + 1 : from_X;
    int to_X = to / 4;
    to_X = to % 4 != 0 ? to_X + 1 : to_X;

    int from_Y = from % 4 != 0 ? from % 4 : 4;
    int to_Y = to % 4 != 0 ? to % 4 : 4;

    int answer = abs(from_X - to_X) + abs(from_Y - to_Y);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> from >> to;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}