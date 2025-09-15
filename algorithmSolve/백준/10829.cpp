#include <iostream>
#include <deque>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    deque<int> answer;
    while (N > 0)
    {
        answer.push_front(N % 2);
        N /= 2;
    }
    for (auto& num : answer)
        cout << num;
    cout << '\n';
    return 0;
}