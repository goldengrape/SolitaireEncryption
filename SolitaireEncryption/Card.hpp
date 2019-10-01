//
//  Card.hpp
//  SolitaireEncryption
//
//  Created by GoldenGrape on 2019/10/1.
//  Copyright © 2019 goldengrape. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>
using namespace std;

// 一张扑克牌
class Deck;
class Card{
    friend Deck;
public:
    Card();
    Card(string suite, int number);
    Card(int value);
    Card(const Card &other);
    int get_value();
    void output();

private:
    // 扑克牌的数值, 从1-54
    // 按照草花->方块->红桃->黑桃->小王->大王的顺序
    int value;
    // club/ diamond/ heart/ spade/ joker A/ joker B
    string suite;
    // 1-13,
    // for joker 1,2;
    int number;
};

#endif /* Card_hpp */
