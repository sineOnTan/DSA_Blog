#include <bits/stdc++.h>
using namespace std;

// This has not been tested. Mainly a concept for
// https://codeforces.com/contest/2102/problem/D

struct dualMap {
    map<int,int> num_to_index;
    map<int,int> index_to_num;
    int length = 0;
    int shift = 0;

    void push_back (int num) {
        index_to_num[length] = num;
        num_to_index[num] = length;
        ++length;
    }

    void pop_back () {
        --length;
        num_to_index.erase(index_to_num[length]);
        index_to_num.erase(length);
    }

    void pop_front () {
        num_to_index.erase(index_to_num[shift]);
        index_to_num.erase(shift);
        ++shift;
    }

    int front() {
        return num_to_index[shift];
    }

    int back() {
        return num_to_index[length - 1];
    }

    int get_smallest() {
        return (*(num_to_index.begin())).first;
    }

    int get_largest() {
        return (*(num_to_index.rbegin())).first;
    }

    int size() {
        return length - shift;
    }

    void swap_indexes(int x, int y) {
        swap(index_to_num[x], index_to_num[y]);
        num_to_index[index_to_num[x]] = x;
        num_to_index[index_to_num[y]] = y;
    }

    void swap_nums(int x, int y) {
        swap(num_to_index[x], num_to_index[y]);
        index_to_num[index_to_num[x]] = x;
        index_to_num[index_to_num[y]] = y;
    }
};