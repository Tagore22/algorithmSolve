#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 처음에는 이진법 -> 십진법으로 치환하여 값을 구한 후, 다시 이진법으로 치환하는 로직으로 구현했는데
// 문제를 자세히 보니 이진법의 길이가 최대 80까지 주어졌기에 십진법으로의 치환은 불가능했다.

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    while (str1.size() != str2.size())
    {
        if (str1.size() > str2.size())
            str2 = "0" + str2;
        else
            str1 = "0" + str1;
    }
    int plus = 0;
    string answer = "";
    for (int i = str1.size() - 1; i >= 0; --i)
    {
        int first = stoi(str1.substr(i, 1));
        int second = stoi(str2.substr(i, 1));
        int cur = first + second + plus;
        plus = cur >= 2 ? 1 : 0;
        answer = to_string(cur % 2) + answer;
    }
    answer = plus == 1 ? "1" + answer : answer;
    while (answer != "0" && answer[0] == '0')
        answer.erase(0, 1);
    cout << answer << '\n';
    return 0;
}