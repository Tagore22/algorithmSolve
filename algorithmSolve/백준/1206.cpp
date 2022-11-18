#include <iostream>
#include <string>

//넘모 화가 났던 문제다. 거의 하루종일 이 문제만 잡고 있었다. ㅠㅠ
//이 문제의 포인트라고 생각한건 당연하겠지만, 총 점수와 인원수는 무조건 정수라는 것이다. 처음엔 (총점수) % (인원수) = (평균점수)를
//역으로 풀려고 했는데, 도무지 답이 나오질 않았다. 알고보니 부동소수점 오차 때문이었고, 코드에서 double의 연산 자체를 없애야했다.
//또한, 입력 역시 소수점을 없애기 위해 double로 받지 않고 string으로 받아서 소수점 밑자리만 다시 int로 변환하였다.

//풀이
//최대 소수점은 3자리이기에 최대 인원은 1000명으로 잡아도 무방하다. 또한, 최대 점수는 한명이 0~10점을 줄수 있기에 10000점이다.
//이걸 이용해서 1명부터 최대 1000명까지, 1점부터 인원 * 10까지 순회를 하며 입력받은 int 배열들과 비교한다.

//p.s 고작 실버인데 오랜만에 너무 힘들었다...
//부동소수점 연산에 주의하라는 종만님의 글귀가 자꾸 눈에 선하다..

using namespace std;

int board[50];
int N;

void MakeAnswer()
{
    for (int i = 1; i <= 1000; ++i)
    {
        int find_num = 0;
        for (int j = 0; j < N; ++j)
        {
            for (int iter = 0; iter <= i * 10; ++iter)
                if (iter * 1000 / i == board[j])
                {
                    ++find_num;
                    break;
                }
        }
        if (find_num == N)
        {
            cout << i << '\n';
            break;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        board[i] = stoi(str.substr(str.find('.') + 1));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}