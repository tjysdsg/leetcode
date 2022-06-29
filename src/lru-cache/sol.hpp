// https://leetcode.cn/problems/lru-cache/

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
#include <unordered_map>

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;

struct Node {
    Node *next;
    Node *prev;
    int key;
    int val;
};

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        auto q = _m.find(key);
        if (q != _m.end()) {
            move_node_to_front(q->second);
            assert(key == _head->key);
            return _head->val;
        }
        return -1;
    }

    void put(int key, int value) {
        Node *n = nullptr;

        if (!_head) {
            n = _head = new Node;
            n->prev = n;
            n->next = n;
            n->val = value;
            ++_size;
        } else {
            auto q = _m.find(key);
            if (q != _m.end()) {
                n = q->second;
                move_node_to_front(n);
                n->val = value;
            } else if (_size < _capacity) {
                n = new Node;
                n->prev = n->next = nullptr;
                n->val = value;
                move_node_to_front(n);
                ++_size;
            } else {
                n = _head->prev;
                _m.erase(n->key); // eviction
                n->val = value;
                move_node_to_front(n);
            }
        }

        assert(n);
        n->key = key;
        _m[key] = n;
    }

private:
    void move_node_to_front(Node *n) {
        if (_head == n) return;
        { // first remove the node
            Node *prev = n->prev;
            Node *next = n->next;
            if (prev)
                prev->next = next;
            if (next)
                next->prev = prev;
        }

        assert(_head);
        Node *prev = _head->prev;
        assert(prev);
        prev->next = n;
        n->prev = prev;
        _head->prev = n;
        n->next = _head;

        _head = n;
    }

private:
    unordered_map<int, Node *> _m{};
    Node *_head = nullptr;
    int _size = 0;
    int _capacity = 0;
};
