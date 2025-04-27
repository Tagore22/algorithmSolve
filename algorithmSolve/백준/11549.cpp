#include <iostream>

using namespace std; 

int main()
{
    int T, answer = 0;
    cin >> T;
    for (int i = 0; i < 5; ++i)
    {
        int num;
        cin >> num;
        if (num == T)
            ++answer;
    }
    cout << answer << '\n';
    return 0;
}