#include <iostream>
#include <cmath>

using namespace std;

double D, H, W;

void MakeAnswer()
{
    double sqrt_num = sqrt((D * D) / (H * H + W * W));
    int answer_H = floor(H * sqrt_num);
    int answer_W = floor(W * sqrt_num);
    cout << answer_H << ' ' << answer_W << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> D >> H >> W;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}