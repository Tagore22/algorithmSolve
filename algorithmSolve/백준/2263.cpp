#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> In;
vector<int> Post;

void PreOrder(int Inbeg, int Inend, int Postbeg, int Postend)
{
    if (Inbeg > Inend || Postbeg > Postend)
        return;
    int root = Post[Postend];
    cout << root << ' ';
    int RootIdx = distance(In.begin(), find(In.begin(), In.end(), root));
    PreOrder(Inbeg, RootIdx - 1, Postbeg, Postbeg + (RootIdx - Inbeg) - 1);
    PreOrder(RootIdx + 1, Inend, Postbeg + (RootIdx - Inbeg), Postend - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    In.assign(n, 0);
    Post.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> In[i];
    for (int i = 0; i < n; ++i)
        cin >> Post[i];
    PreOrder(0, n - 1, 0, n - 1);
    cout << '\n';
    return 0;
}