// 5.Program to depict command line arguments to compute fabonicci number of nth term.
#include <iostream>
using namespace std;
int fibonachi(int n)
{
    if (n <= 1)
        return n;
    return fibonachi(n - 1) + fibonachi(n - 2);
}
int main(int argc, char **argv)
{
    cout << argc
         << " arguments are entered :"
         << "\n";
    for (int i = 0; i < argc; ++i)
        cout << " " << i + 1 << " : " << argv[i] << "\n";

    int f = atoi(argv[1]);
    cout << "Fibonachi term is : " << fibonachi(f) << "\n";
    return 0;
}
