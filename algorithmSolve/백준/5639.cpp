#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> board;

vector<int> DivideVec(const vector<int>& vec, int from, int to)
{
    return vector<int>(vec.begin() + from, vec.begin() + to);
}

void calcul(const vector<int>& vec)
{
    if (vec.empty())
        return;
    int root = vec[0];
    int left = distance(vec.begin(), upper_bound(vec.begin(), vec.end(), root));
    calcul(DivideVec(vec, 1, left));
    calcul(DivideVec(vec, left, vec.size()));
    cout << root << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x;
    while (cin >> x)
    {
        board.push_back(x);
    }
    calcul(board);
    return 0;
}