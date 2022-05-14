#include <iostream>
#include <vector>

using namespace std;

class uni
{
private:
    vector<int> parents;
    vector<int> d;
public:
    uni(int num);
    int findParents(int num);
    void fusion(int a, int b);
    void isBro(int a, int b);
};

uni::uni(int num) : parents(num + 1, 0), d(num + 1, 0)
{
    for (int i = 0; i <= num; ++i)
        parents[i] = i;
}

int uni::findParents(int num)
{
    if (parents[num] == num)
        return num;
    return parents[num] = findParents(parents[num]);
}

void uni::fusion(int a, int b)// b를 a에 결속시킨다.
{
    a = findParents(a);
    b = findParents(b);

    if (a == b)
        return;

    if (d[a] < d[b])
        swap(a, b);

    parents[b] = a;
    if (d[a] == d[b])
        ++d[a];
}

void uni::isBro(int a, int b)
{
    if (findParents(a) == findParents(b))
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    uni UF(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
            UF.fusion(b, c);
        else
            UF.isBro(b, c);
    }
    return 0;
}