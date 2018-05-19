#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void WriteRight(tree *Pin);

struct tree
{
    int value;
    tree *right = nullptr;
    tree *left = nullptr;
    tree(void)  {}
    tree(int value) : value(value), right(nullptr), left(nullptr) {}
};

void    build_tree(tree *Pin, int num)
{
    if(Pin->value < num && Pin->right != nullptr)
        build_tree(Pin->right, num);
    else if(Pin->value > num && Pin->left != nullptr)
        build_tree(Pin->left, num);
    else if(Pin->value < num && Pin->right == nullptr)
        Pin->right = new tree(num);
    else if(Pin->value > num && Pin->left == nullptr)
        Pin->left = new tree(num);
}

void WriteLeft(tree *Pin)
{
    if(Pin->left != nullptr)
        WriteLeft(Pin->left);
    if(Pin->right != nullptr)
        WriteRight(Pin->right);
    cout << Pin->value << endl;
}

void WriteRight(tree *Pin)
{
    if(Pin->left != nullptr)
        WriteLeft(Pin->left);
    if(Pin->right != nullptr)
        WriteRight(Pin->right);
        cout << Pin->value  << endl;
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    int strength = 4200000;
    int x;
    tree *Pin = new tree();
    
    int i = 0;
    for (i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        if(i == 0)
            Pin->value = Pi;
        else
            build_tree(Pin, Pi);
    }
}