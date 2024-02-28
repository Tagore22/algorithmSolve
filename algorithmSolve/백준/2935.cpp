#include <iostream>

using namespace std;

// 풀이.
// 주어지는 수가 최대 100자리이기 때문에 string을 써야했다. 또한, 같은 자리수의 두 수가 더하기 연산을 하게 되면
// 기존과는 다르게 2가 나와야하기 때문에 이부분도 주의해야했다. 

// 자세한 설명은 주석으로 남긴다.

int main()
{
    string a, b;
    char oper;
    cin >> a >> oper >> b;
    string answer;
    // 무조건 a를 더 긴 문자열로 한다.
    if (a.size() < b.size())
    {
        swap(a, b);
    }
    // 연산자가 더하기라면
    if (oper == '+')
    {
        // 두 문자열의 길이가 같다면 기존과는 다르게 2가 나오게 된다.
        // 따라서 맨 앞문자를 2로 만들고 그 이후 a의 나머지 문자열들을 복사한다.
        if (a.size() == b.size())
        {
            answer = "2";
            answer += a.substr(1);
        }
        // 두 문자열의 길이가 다르다면 a의 맨 앞부터 b의 길이 이전까지 붙여준후
        // 마지막으로 b를 덧붙인다.
        else
        {
            answer = a.substr(0, a.size() - b.size());
            answer += b;
        }
    }
    // 연산자가 곱하기이라면
    else
    {
        // 두 문자를 모두 덧붙이되, b의 1은 필요가 없다.
        answer = a;
        answer += b.substr(1);
    }
    cout << answer << '\n';
    return 0;
}