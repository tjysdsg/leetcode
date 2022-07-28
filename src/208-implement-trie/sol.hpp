// https://leetcode.cn/problems/implement-trie-prefix-tree/

#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include <queue>

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;
using std::queue;


class Trie {
private:
    bool is_end = false;
    Trie *next[26]{};

public:
    void insert(string word) {
        Trie *prev = this;
        for (char c: word) {
            int i = c - 'a';
            Trie *t = prev->next[i];
            if (!t) {
                prev->next[i] = new Trie();
            }

            prev = prev->next[i];
        }
        prev->is_end = true;
    }

    bool search(string word) {
        Trie *n = this;
        for (char c: word) {
            int i = c - 'a';
            if (!n->next[i]) {
                return false;
            }
            n = n->next[i];
        }

        return n->is_end;
    }

    bool startsWith(string prefix) {
        Trie *t = this;
        for (char c: prefix) {
            int i = c - 'a';
            if (!t->next[i]) {
                return false;
            }
            t = t->next[i];
        }
        return true;
    }
};
