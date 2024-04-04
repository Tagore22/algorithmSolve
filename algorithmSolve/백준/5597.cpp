#include <iostream>

using namespace std;

// 1 ~ 30 범위의 수들중 입력받은 28개에 포함되지 않는 수를 찾는 문제다.
// int 배열을 초기화할때 {0, } 로 전부 0으로 초기화가 가능했는데
// bool 역시 {false, }로 모두 초기화가 가능했다. 예전에는 cstring을 include해서
// memset()을 사용하였는데 이제 그럴 필요가 없는것 같다.

int main()
{
    bool board[31] = { false, };
    for (int iter = 0; iter < 28; ++iter)
    {
        int num;
        cin >> num;
        board[num] = true;
    }
    for (int iter = 1; iter < 31; ++iter)
        if (!board[iter])
            cout << iter << '\n';
    return 0;
}