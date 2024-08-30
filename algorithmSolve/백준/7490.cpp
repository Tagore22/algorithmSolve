#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 기본에 충실한 귀찮으면서 복잡한 문제였다. 아마도 문자열에서 정수로의 변환같은걸 확인하고자 하는
// 문제였던듯 싶다. 원리 자체는 그리 어렵지 않다. 대입할수 있는 모든 부호들을 대입하여 N까지 도달하였을때
// 점화식의 값이 0이면 점화식을 출력하는 것이다. 다만, 사전 정렬순으로 출력해야 하기 때문에 공백, +, - 순으로
// 대입해야한다. 또한, 각 점화식을 계산하는것이 매우 복잡했다. 후... 한번에 맞아서 다행이다.

// 자세한 설명은 주석으로 남긴다.

int T, N;

// 현재 점화식의 계산을 하는 함수.
bool IsZero(string str)
{
    int first = 0, second = 0, sum = 0;
    char sign;
    bool isfind = false;
    // 모든 문자들을 순회한다.
    for (int i = 0; i < str.size(); ++i)
    {
        // 현재 문자가 부호일때.
        if (str[i] == '+' || str[i] == '-')
        {
            // 첫번째로 만난 부호라면 부호를 기억하고 isfind로 그 다음 부호는
            // 두번째로 만난 것을 갱신한다.
            if (!isfind)
            {
                isfind = true;
                sign = str[i];
            }
            // 두번째로 만난 부호라면 이전값들을 계산하고 넘어가야 한다.
            else
            {
                // 이전 부호에 의해 계산값이 바뀐다.
                if (sign == '+')
                    sum = first + second;
                else
                    sum = first - second;
                // 여태까지의 총합이 첫번째 값이 된다.
                first = sum;
                // 두번째값은 0으로 초기화해준다.
                second = 0;
                // 부호의 갱신.
                sign = str[i];
            }
        }
        // 현재 문자가 공백이라면 무시한다. 어차피 연속으로 숫자를 만날경우 알아서
        // 이어지게 구현되었기 때문이다.
        else if (str[i] == ' ')
        {
            continue;
        }
        else
        {
            // 아직 부호를 만나지 못했을 경우 첫번째 값을 변경한다.
            if (!isfind)
            {
                first *= 10;
                // 여기 이 부분도 중요했다. stoi()로 char값을 변경했을때 아스키값이 반환되었다.
                first += stoi(to_string(str[i])) - 48;
            }
            // 부호를 만났을 경우 두번째 값을 변경한다.
            else
            {
                second *= 10;
                second += stoi(to_string(str[i])) - 48;
            }
        }
    }
    // 주먹구구식으로 풀어봤을 때에도 알수 있지만 맨 마지막에는 first, second, 부호만 결정된채
    // 최종 sum값은 계산되지 않은채로 끝나게 된다. 따라서 맨 마지막에 한번 더 계산한다.
    if (!isfind)
        return false;
    if (sign == '+')
        sum = first + second;
    else
        sum = first - second;
    return sum == 0;
}

// 모든 경우를 대입해보는 함수.
void FindAnswer(int idx, string str)
{
    // idx가 맨 마지막에 도달했을 경우 점화식의 값을 계산해본다.
    if (idx == N)
    {
        if (IsZero(str))
            cout << str << '\n';
        return;
    }

    // 상술하였듯 사전 정렬순으로 출력해야하기 때문에 공백, +, - 순으로 대입해본다.
    FindAnswer(idx + 1, str + " " + to_string(idx + 1));
    FindAnswer(idx + 1, str + "+" + to_string(idx + 1));
    FindAnswer(idx + 1, str + "-" + to_string(idx + 1));
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;

        FindAnswer(1, "1");
        cout << '\n';
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