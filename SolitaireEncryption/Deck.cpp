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
                seq.insert(seq.begin()+1, c);
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


void Deck::tri_cut(int posA, int posB, string type="triple"){
    vector<Card> seq_first(seq.cbegin(),seq.cbegin()+posA-1+1);
    vector<Card> seq_middle(seq.cbegin()+posA,seq.cbegin()+posB+1);
    vector<Card> seq_last(seq.cbegin()+posB+1,seq.cend());
    
    seq.clear();
    seq.reserve(54);
    
    if (type=="triple"){
        seq.insert(seq.end(), seq_last.begin(), seq_last.end() );
        seq.insert(seq.end(), seq_middle.begin(),seq_middle.end() );
        seq.insert(seq.end(), seq_first.begin(), seq_first.end() );
    } else if (type=="count"){
        seq.insert(seq.end(), seq_middle.begin(),seq_middle.end() );
        seq.insert(seq.end(), seq_first.begin(), seq_first.end() );
        seq.insert(seq.end(), seq_last.begin(), seq_last.end() );
    }
    
}



void Deck::triple_cut(){
    // 三重切牌:
    // 将1-(posA-1) / posA-posB / (posB+1)-last 转换成
    // posB-last/ posA-posB/ 1-(posA-1)

    int posA=-1, posB=-1;
    for(int i=0;i<54;i++){
        if (seq[i].value>=53){
            if (posA<0) {
                posA=i;
            } else{
                posB=i;
            }
        }
    }
    
    tri_cut(posA, posB, "triple");
//
//    vector<Card> seq_first(seq.cbegin(),seq.cbegin()+posA-1+1);
//    vector<Card> seq_middle(seq.cbegin()+posA,seq.cbegin()+posB+1);
//    vector<Card> seq_last(seq.cbegin()+posB+1,seq.cend());
//
//    seq.clear();
//    seq.reserve(54);
//    seq.insert(seq.end(), seq_last.begin(), seq_last.end() );
//    seq.insert(seq.end(), seq_middle.begin(),seq_middle.end() );
//    seq.insert(seq.end(), seq_first.begin(), seq_first.end() );
}

void Deck::count_cut(int pos){
    // 数字切牌:
    // 将1-(pos-1)/ pos-(last-1)/ last, 转换成
    // pos-(last-1)/ 1-(pos-1)/ last
    tri_cut(pos, 52, "count");
}

