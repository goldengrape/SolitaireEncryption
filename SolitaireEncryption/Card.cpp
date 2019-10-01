//
//  Card.cpp
//  SolitaireEncryption
//
//  Created by GoldenGrape on 2019/10/1.
//  Copyright © 2019 goldengrape. All rights reserved.
//

#include "Card.hpp"
#include <string>
#include <iostream>
using namespace std;

Card::Card():value(1),suite("club"),number(1){};

Card::Card(string s, int n):suite(s), number(n){
    // club/ diamond/ heart/ spade/ joker A/ joker B
    if (s=="club"){
        value=13*0+n;
    } else if (s=="diamond"){
        value=13*1+n;
    } else if (s=="heart"){
        value=13*2+n;
    } else if (s=="spade"){
        value=13*3+n;
    } else if (s=="joker"){
        value=13*4+n;
    }
}

Card::Card(int value):value(value){
    int v=value-1;
    number = v % 13 +1;
    int s= v/13;
    if (s==0) {
        suite="club";
    }else if (s==1) {
        suite="diamond";
    }else if (s==2) {
        suite="heart";
    }else if (s==3) {
        suite="spade";
    }else if (s==4) {
        suite="joker";
    }
}


Card::Card(const Card &c):value(c.value),suite(c.suite),number(c.number){};

int Card::get_value(){
    return value;
}
void Card::output(){
    cout << suite << " " <<number << "=" << value<<",";
}
