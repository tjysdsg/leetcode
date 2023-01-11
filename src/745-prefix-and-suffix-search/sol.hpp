// https://leetcode.cn/problems/prefix-and-suffix-search/

#pragma once

#include "common.h"

struct Trie {
    // key = "<prefix letter> <suffix letter>" where '#' means placeholders
    // for example, word = 'abcdefg', prefix = 'abc', suffix = '#fg'
    unordered_map<string, Trie *> children{};
    int word_index = 0;
};

class WordFilter {
private:
    Trie *_root = nullptr;

public:
    WordFilter(vector<string> &words) {
        _root = new Trie;

        for (int word_index = 0; word_index < words.size(); ++word_index) {
            string word = words[word_index];
            int len = word.length();

            Trie *curr = _root;
            for (int i = 0; i < len; ++i) {
                Trie *tmp = curr;
                for (int j = i; j < len; ++j) {
                    string key({word[j], '#'});
                    if (tmp->children.find(key) == tmp->children.end())
                        tmp->children[key] = new Trie;

                    tmp = tmp->children[key];
                    tmp->word_index = word_index; // only keep the largest
                }

                tmp = curr;
                for (int j = i; j < len; ++j) {
                    string key({'#', word[len - j - 1]});
                    if (tmp->children.find(key) == tmp->children.end())
                        tmp->children[key] = new Trie;

                    tmp = tmp->children[key];
                    tmp->word_index = word_index; // only keep the largest
                }

                string key({word[i], word[len - i - 1]});
                if (curr->children.find(key) == curr->children.end())
                    curr->children[key] = new Trie;

                curr = curr->children[key];
                curr->word_index = word_index; // only keep the largest
            }
        }
    }

    int f(string pref, string suff) {
        int len1 = pref.length();
        int len2 = suff.length();
        int len = std::max(len1, len2);

        Trie *curr = _root;
        for (int i = 0; i < len; ++i) {
            char prefix = '#';
            char suffix = '#';
            if (i < len1) prefix = pref[i];
            if (i < len2) suffix = suff[len2 - i - 1];

            string key({prefix, suffix});
            auto it = curr->children.find(key);
            if (it == curr->children.end())
                return -1;

            curr = it->second;
        }

        return curr->word_index;
    }
};
