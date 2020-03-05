#include<iostream>

using namespace std;

#include"btreeUtil.h" // std is being used inside this header file

using namespace bTreeUtil;

/*
Problem Statement:
	Find the sum of all left leaves in a given binary tree.


   3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/

int main() {
    
    cout << "Enter Size of Tree" << endl;
    cin >> size; // Part of Namespace bTreeUtil

    createOneChildTree();
}

