#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 언젠가 풀었던 FizzBuzz의 업그레이드 문제다. 어떠한 수 i부터 3개가 연달아 주어지되,
// FizzBuzz식으로 변형된 문자열이 주어진다. 이때, 4번째 수의 번형된 문자열을 출력하는
// 문제인데 여러 문자열이 올 수 있는 경우, 아무거나 출력하라는 문구가 있기에 굉장히
// 복잡하게 생각하였으나 연달아 수가 아닌 문자열이 나올 경우는 존재하지 않기에
// 반드시 숫자는 하나 이상 나온다는 걸 생각해냈다. 따라서 3번을 입력받되, 수를 찾아
// 4번째 수를 알아내어 FizzBuzz식으로 변경후 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    string str;
    int num, idx; // 문자열이 아닌 수와 인덱스 값.
    for (int i = 0; i < 3; ++i)
    {
        cin >> str;
        // 3, 5, 15의 배수들이 문자열로 변경되기에 연달아 3개가
        // 절대로 나올 수 없다. 따라서 반드시 존재하는 수를 찾아내고
        // 인덱스 값을 저장해둔다.
        if ('0' <= str[0] && str[0] <= '9')
        {
            num = stoi(str);
            idx = i;
        }
    }
    // 마지막으로 찾아낸 수에서 3 - 인덱스값으로 4번째 값을 찾아낸다.
    num += 3 - idx;
    // FizzBuzz식으로 변경후 출력.
    if (num % 15 == 0)
        cout << "FizzBuzz" << '\n';
    else if (num % 3 == 0)
        cout << "Fizz" << '\n';
    else if (num % 5 == 0)
        cout << "Buzz" << '\n';
    else
        cout << num << '\n';
    return 0;
}