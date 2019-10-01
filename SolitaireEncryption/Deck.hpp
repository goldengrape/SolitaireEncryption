//
//  Deck.hpp
//  SolitaireEncryption
//
//  Created by GoldenGrape on 2019/10/1.
//  Copyright © 2019 goldengrape. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <vector>
#include "Card.hpp"

// 一副牌
class Deck{
public:
    Deck(vector<Card> &s):seq(s){};
    Deck(vector<int>);
    Deck();
    Deck(const Deck &d): seq(d.seq){};
    
    // 将某牌下移一张
    void move_one_down(Card &);
    // 将某牌下移两张
    void move_two_down(Card &);
    
    // 三重切牌:
    // 将1-(posA-1) / posA-posB / posB-last 转换成
    // posB-last/ posA-posB/ 1-(posA-1)
    void triple_cut();
    
    // 数字切牌:
    // 将1-(pos-1)/ pos-(last-1)/ last, 转换成
    // pos-(last-1)/ 1-(pos-1)/ last
    void count_cut(int pos);
    
    // 获得第pos张牌
    Card& get_card(int pos);
    
private:
    vector<Card> seq;
    
};


#endif /* Deck_hpp */
