#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 최초의 정수 혹은 소수이후에 최대 3개의 연산자가 주어지는데 1 ~ 3개중 랜덤이기에 아예 한줄 자체를 다 입력받기 위해서
// getline()을 사용하여야 했다. 그 이후 맨 처음 수를 float로 캐스팅하여 나머지 연산자를 처리했다.
// 오히려 C언어로 사용하는 것이 더 간단하고 가독성 좋은 코딩이 될지도 모르겠다.

// P.S getline()에는 거의 왠만해선 cin.ignore()가 따라왔는데 이번에도 그랬다. 하지만 한가지 실수가 있었는데
// cin.ignore()를 더 깊게 이해하는 계기가 되었다. cin.ignore()는 매개변수가 존재하지 않을시 버퍼의 내용물 1개를 지우는 함수다.
// 다만 이미 버퍼가 지워졌을 경우에는 그 이후 들어오는 입력값의 맨 첫번째값을 지우는 예약 형식이 된다. 그래서 cin.ignore()를
// 첫번째 for문에 존재하는 getline()위에 구현하면 그 후에 입력받는 값의 맨 첫번째값이 지워진채로 입력되는 것이었다.
// 잘 알아두자.

string str;
int T;

void MakeAnswer()
{
    cout.precision(2);
    cout << fixed;
    cin.ignore();
    for (int iter = 0; iter < T; ++iter)
    {
        getline(cin, str);
        int pivot = 0;
        for (int i = 0; i < str.size(); ++i)
            if (str[i] == ' ')
            {
                pivot = i;
                break;
            }
        float answer = stof(str.substr(0, pivot));
        for (int i = pivot + 1; i < str.size(); ++i)
        {
            if (str[i] == '@')
                answer *= 3;
            else if (str[i] == '%')
                answer += 5;
            else if (str[i] == '#')
                answer -= 7;
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}