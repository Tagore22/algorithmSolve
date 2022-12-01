#include <iostream>

using namespace std;

//풀이
//입력 받는 수는 0 혹은 1으로 2개뿐이기에 따로 배열을 만들어 저장할 필요 없이 변수 2개만 있으면 각 상황을 기록할수 있다. 이후 4개의 수를 저장받고 도개걸윷모 5개의
//상태중 하나에 맞는 것을 출력하면 되는데 등과 배는 더해서 4가 나와야 하므로 둘중 하나만 확인해도 상태를 알수 있다.

char board[5] = { 'E', 'A', 'B', 'C', 'D' };

void MakeAnswer()
{
    int one, zero, num;
    for (int i = 0; i < 3; ++i)
    {
        one = zero = 0;
        for (int j = 0; j < 4; ++j)
        {
            cin >> num;
            if (num == 0)
                ++zero;
            else
                ++one;
        }
        cout << board[zero] << '\n';
    }
}

int main()
{
    MakeAnswer();
}