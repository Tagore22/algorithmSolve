#include <iostream>

using namespace std;

//풀이
//초기 맥박에서 시작하여 운동시 증가하는 맥박과의 합이 최대 맥박보다 작다면 운동을 하여 맥박을 올리고, 최대 맥박보다 크다면 휴식을 해서 맥박을 감소시킨다. 다만, 최소
//맥박보다 작아지면 안되기에 max함수로 최대값을 구해야한다. 또한, 애시당초 운동이 불가능한 경우가 있는데, 최소 맥박과 최대 맥박의 차이가 운동시 증가하는 맥박보다 작은
//경우이다. 이런 경우는 -1을 출력한다. 

int N, m, M, T, R;

void MakeAnswer()
{
    if (M - m < T) //애시당초 운동이 불가능 할경우. 즉 초기 맥박과 최대 맥박의 차이가 운동할시 증가하는 맥박보다 작은 경우.
    {
        cout << -1 << '\n';
        return;
    }

    int answer = 0, cur = m, ex = 0;
    while (ex < N)
    {
        if (cur + T > M) //휴식을 해야하는 경우.
        {
            cur = max(cur - R, m);
        }
        else //운동을 해도 되는 경우.
        {
            cur += T;
            ++ex;
        }
        ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> m >> M >> T >> R;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}