#include <iostream>

//브론즈 난이도 문제인데 생각할게 많아 꽤나 애먹었던 문제. 하나하나 차근히 풀어가자.

//풀이
//주어진 시간 num을 각 시간을 초 단위로 변환하여 나누어 증가시켜나간다. 다만 23 59 59 1 같은 경우처럼 초의 증가가 시의 증가까지 여파가 미치는
//경우도 생각해야하고, 단순히 for문으로 시까지 증가시킬뿐 아니라, 현재 시간대에서 1이 증가했을때 최대값(ex 24, 60 등)을 초과해야 다음으로
//넘어가는 반복문을 구현해야한다.

using namespace std;

int times[3];
int div_num[3] = { 24, 60, 60 };
int num;

void MakeAnswer()
{
    int idx = 60 * 60;
    for (int i = 0; i < 3; ++i)
    {
        int plus = num / idx;
        num %= idx;
        if (i > 0 && times[i] + plus >= div_num[i])
            for (int j = i - 1; j >= 0; --j)
            {
                ++times[j];
                if (times[j] >= div_num[j])
                    times[j] %= div_num[j];
                else
                    break;
            }
        times[i] = (times[i] + plus) % div_num[i];
        idx /= 60;
    }

    for (int i = 0; i < 3; ++i)
        cout << times[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 3; ++i)
        cin >> times[i];
    cin >> num;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}