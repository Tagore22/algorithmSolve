#include <iostream>

using namespace std;

// 풀이.
// 사실 처음에 이 풀이를 먼저 시도했는데 틀렸기에
// 이전에 나왔던 주먹구구식의 풀이가 나왔다.
// 조합을 구할때 ccc가 주어지면 26 * 25 * 24 = 15,600인줄 알았는데
// 2글자 초과가 아닌 2글자가 중복되는걸 막는 문제였다. 즉 aba같은 형식이 가능하기에
// 26 * 25 * 25가 되어 16,250개가 나와야 한다. 문제를 잘보자;;

// 자세한 설명은 주석으로 남긴다.

string str;

int main()
{
    cin >> str;

    int answer = 1, c = 26, d = 10;
    for (int i = 0; i < str.size(); ++i)
    {
        // 현재가 문자일때 
        if (str[i] == 'c')
            // 맨 처음이 아니며 이전과 같을 경우 중복을 막기 위해 1만큼 빼고 곱해준다.
            // 그렇지 않으면 그대로 곱해준다.
            answer = i != 0 && str[i - 1] == 'c' ? answer * (c - 1) : answer * c;
        // 현재가 숫자일때 
        else
            // 맨 처음이 아니며 이전과 같을 경우 중복을 막기 위해 1만큼 빼고 곱해준다.
            // 그렇지 않으면 그대로 곱해준다.
            answer = i != 0 && str[i - 1] == 'd' ? answer * (d - 1) : answer * d;
    }

    cout << answer << '\n';
    return 0;
}