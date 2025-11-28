#include <iostream>

using namespace std;

int main()
{
    int N, W, H;
    cin >> N >> W >> H;
    int len = H * H + W * W;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        if (num * num > len)
            cout << "NE" << '\n';
        else
            cout << "DA" << '\n';
    }
    return 0;
}