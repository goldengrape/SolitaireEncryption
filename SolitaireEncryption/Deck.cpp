//
//  Deck.cpp
//  SolitaireEncryption
//
//  Created by GoldenGrape on 2019/10/1.
//  Copyright © 2019 goldengrape. All rights reserved.
//

#include "Deck.hpp"
#include <vector>
using namespace std;

Deck::Deck(vector<int> s){
    seq.clear();
    seq.reserve(54);
    for(int i:s){
        Card c(i);
        seq.push_back(c);
    }
}

Deck::Deck(){
    seq.clear();
    seq.reserve(54);
    for(int i=1;i<=54;i++){
        Card c(i);
        seq.push_back(c);
    }
}

Card& Deck::get_card(int pos){
    return seq[pos];
}

void Deck::move_one_down(Card &c){
    for(int i=0; i<54; i++){
        if (seq[i].value==c.value){
            if (i<54-1){
                seq[i]=seq[i+1];
                seq[i+1]=c;
                break;
            } else {
                seq.insert(seq.begin(), c);
                seq.erase(seq.begin()+i+1);
                break;
            }
        }
    }
}

void Deck::move_two_down(Card &c){
    move_one_down(c);
    move_one_down(c);
}

