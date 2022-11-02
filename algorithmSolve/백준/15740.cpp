#include <iostream>
#include <string>

using namespace std;

//코드의 길이를 보면 알겠지만 생각해야 할 변수들이 많아 꽤나 애를 먹었던 문제이다. 단순히 두 수를 입력받아 더한 값을 출력하는 문제인데,
//중요한건 long long의 범위를 벗어나는 큰 수의 존재이다. 당연하게도 string 으로 풀어야 했는데, 두 수의 각자 부호값과 크기에 따라 여러가지
//경우의 수로 나누어주어야했다. 또한, 각 0으로 시작하는 경우에도 처리를 해주어야했으며, 0,0 같은 경우는 아예 0이었으므로 답 answer에서
//answer.size()-1까지는 0으로 시작한다면 무시하되, 마지막 answer[answer.size()-1]은 0일지라도 무조건 출력해야했다.

string A, B;

void MakeAnswer()
{
    bool minusA = A[0] == '-' ? true : false;
    bool minusB = B[0] == '-' ? true : false;
    A = minusA ? A.substr(1, A.size()) : A;
    B = minusB ? B.substr(1, B.size()) : B;

    if (A.size() > B.size())
        while (A.size() != B.size())
            B = '0' + B;

    else
        while (B.size() != A.size())
            A = '0' + A;

    string answer = "";
    if (minusA != minusB) //한쪽은 -, 한쪽은 +일때. 즉, 두 수를 빼야할때
    {
        if (A > B)
        {
            for (int i = A.size() - 1; i >= 0; --i)
            {
                int nowA = A[i] - '0';
                int nowB = B[i] - '0';
                if (A[i] < B[i])
                {
                    int idx = i - 1;
                    while (A[idx] == '0')
                    {
                        A[idx] = '9';
                        --idx;
                    }
                    --A[idx];
                    nowA += 10;
                }
                answer = to_string(nowA - nowB) + answer;
            }
            if (minusA)
                cout << '-';
        }
        else if (A < B)
        {
            for (int i = A.size() - 1; i >= 0; --i)
            {
                int nowA = A[i] - '0';
                int nowB = B[i] - '0';
                if (A[i] > B[i])
                {
                    int idx = i - 1;
                    while (B[idx] == '0')
                    {
                        B[idx] = '9';
                        --idx;
                    }
                    --B[idx];
                    nowB += 10;
                }
                answer = to_string(nowB - nowA) + answer;
            }
            if (minusB)
                cout << '-';
        }
        else
        {
            answer = "0";
        }
    }
    else // 두 수의 부호가 같을때
    {
        int sum = 0;
        for (int i = A.size() - 1; i >= 0; --i)
        {
            sum += (A[i] - '0') + (B[i] - '0');
            answer = to_string(sum % 10) + answer;

            sum = sum >= 10 ? 1 : 0;
        }
        answer = sum == 1 ? '1' + answer : answer; //가장 큰 자리수끼리의 덧셈이 10을 넘어가 새로운 자리수를 생성할때. 이걸 잊었었다. ㅠㅠ
        if (minusA)
            cout << '-';
    }

    bool zero = true;
    for (int i = 0; i < answer.size() - 1; ++i) //0으로 시작하는 경우는 무시해야 하는데 0,0일 경우 모두 무시되어 아무것도 출력되지 않는다.
    {                                           //마지막 자리수 전까지는 0으로 시작하는 경우를 무시하되, 마지막 자리수는 무조건 출력한다.
        if (zero && answer[i] == '0')
            continue;
        zero = false;
        cout << answer[i];
    }
    cout << answer[answer.size() - 1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}