#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 각 문자를 변환시키는 문제이다.
// 큰틀은 다음과 같다.

// 1. 현재 문자가 알파벳일때에만 해당 된다.
// 2. 현재 문자를 13칸 뒤로(값을 증가) 이동시킨다.
// 3. 만약 범위값을 넘어섰다면 최대값 + 1로 나누고 최소값을 더해준다.

// 이것을 문자열의 모든 문자에 대입시키면 된다. 다만 한가지 주의해야할점은
// 문자에 13을 더했을때 char의 최대값 127을 벗어날수 있다는 점이다.
// 따라서 따로 int값 변수를 생성해 값을 복사하여 게산후 문자에 다시 대입시켜야한다.

// 자세한 설명은 주석으로 남긴다.

string str;

// 모든 문자들을 순회하며 변환시키는 함수.
void MakeAnswer()
{
    for (int i = 0; i < str.size(); ++i)
    {
        // 해당 문자가 소문자일때
        if ('a' <= str[i] && str[i] <= 'z')
        {
            // 상술하였듯 str[i]에 13을 증가시키면 127을 벗어날 가능성이 존재하기에
            // 따로 int값 변수를 생성하여 값을 복사후 계산한다.
            int cur = str[i];
            cur += 13;
            // 13을 증가시킨 결과, 최대값보다 커졌다면 최대값 + 1로 나눈 후 최소값을 더해준다.
            str[i] = cur > 122 ? cur % 123 + 97 : cur;
        }
        // 해당 문자가 대문자일때
        // 나머지는 위와 비슷하다.
        else if ('A' <= str[i] && str[i] <= 'Z')
        {
            int cur = str[i];
            cur += 13;
            str[i] = cur > 90 ? cur % 91 + 65 : cur;
        }
    }

    cout << str << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getline(cin, str);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}