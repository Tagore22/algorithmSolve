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

// P.S2 혹시나 미래의 까먹었을 나를 위해 조금더 자세하게 기술하고자 한다. cin 입력은 개행문자를 무시하고 입력받는다.
// 하지만 getline()은 개행문자까지 전부 입력받는다. 그래서 cin 이후 getline()을 사용하면 cin이 입력받지 않고 냅둔
// 개행문자를 getline()이 입력받기에 이때에는 cin.ignore()로 그 개행문자를 버려야한다. 하지만 이번 같은 경우 getline()이
// 반복되었다. 상술하였듯 getline()은 개행문자까지 전부 입력받기에 입력버퍼에는 남은것이 없다. 이 이후 만약 for문에 cin.ignore()가
// 존재하여 계속 비운다면 이미 입력버퍼는 텅빈 상태라 이 이후 들어오는 입력의 맨 첫번째를 무시하게 되었던 것이다.

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