#include <iostream>

using namespace std;

// 풀이.
// 콤마가 추가된 a와 b를 입력받아 a + b를 출력하는 문제다.
// 따라서 int로 입력받지 않고 string으로 입력받은후 a와 b를 뽑아내야하는데
// 모두 1자리수임이 문제에서 제시됨으로 어렵게 생각할것 없이 0번째, 2번째 원소를
// '0'만큼 제거하여 더하면 된다.

// 자세한 설명은 주석으로 남긴다.

int T;

int main()
{
    cin >> T;
    string str;
    for (int iter = 0; iter < T; ++iter)
    {
        // 문자열을 입력받아 각각 a와 b를 뽑아낸다.
        cin >> str;
        int a = str[0] - '0';
        int b = str[2] - '0';

        // a + b 출력.
        cout << a + b << '\n';
    }
}