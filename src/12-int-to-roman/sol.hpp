// https://leetcode.cn/problems/integer-to-roman/

#pragma once

#include "common.h"

class Solution {
public:
    string intToRoman(int num) {
        string ret = "";

        if (num / 1000) {
            ret += string(num / 1000, 'M');
            num %= 1000;
        }
        if (num >= 900) {
            ret += "CM";
            num -= 900;
        }

        if (num / 500) {
            ret += string(num / 500, 'D');
            num %= 500;
        }
        if (num >= 400) {
            ret += "CD";
            num -= 400;
        }

        if (num / 100) {
            ret += string(num / 100, 'C');
            num %= 100;
        }
        if (num >= 90) {
            ret += "XC";
            num -= 90;
        }

        if (num / 50) {
            ret += string(num / 50, 'L');
            num %= 50;
        }
        if (num >= 40) {
            ret += "XL";
            num -= 40;
        }

        if (num / 10) {
            ret += string(num / 10, 'X');
            num %= 10;
        }
        if (num >= 9) {
            ret += "IX";
            num -= 9;
        }

        if (num / 5) {
            ret += string(num / 5, 'V');
            num %= 5;
        }
        if (num >= 4) {
            ret += "IV";
            num -= 4;
        }

        ret += string(num, 'I');
        return ret;
    }
};
