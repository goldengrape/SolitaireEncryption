//
//  main.cpp
//  SolitaireEncryption
//
//  Created by GoldenGrape on 2019/10/1.
//  Copyright © 2019 goldengrape. All rights reserved.
//

#include <iostream>
#include "Deck.hpp"


void test_deck_output(Deck &d){
    vector<int> s={0,1,2,3,50,51,52,53};
    for (int i:s){
        cout << i <<":";
        d.get_card(i).output(); cout << endl;
    }
    cout << endl;
}

int get_output_card_value(Deck &d){
    Card joker_A("joker",1), joker_B(54), output_card;
    d.move_one_down(joker_A);
    d.move_two_down(joker_B);
    d.triple_cut();
    d.count_cut(d.get_card(53).get_value());
    output_card=d.get_card(
                           d.get_card(0).get_value()
                           );
    return output_card.get_value();
}

string encrypt(string message, Deck &d){
    string output;
    for (int i=0; i<message.size(); i++){
        char c=message[i];
        if (c!=' '){
            int delta=get_output_card_value(d);
            if (delta >=53){
                i--;
                continue;
            } else{
                    char x=((int)c-(int)'A'+delta) % 26 + (int)'A';
                    output += x;
            }
        }else {
            output +=' ';
        }
    }
    
    return output;
}

string decrypt(string message, Deck &d){
    string output;
    for (int i=0; i<message.size(); i++){
        char c=message[i];
        if (c!=' '){
            int delta=get_output_card_value(d);
            if (delta >=53){
                i--;
                continue;
            } else{
                    char x=((int)c-(int)'A' - (delta % 26)+26) % 26 + (int)'A';
                    output += x;
            }
        }else {
            output +=' ';
        }
    }
    
    return output;
}

void test_deck(){
    Deck d;
    for (int i=0; i<11;i++){
        cout << get_output_card_value(d)<< ",";
    }
    cout << endl;
}


int main(int argc, const char * argv[]) {
    Deck d;
    string en=encrypt("AAAAA AAAAA",d);
    cout << en << endl;
    Deck e;
    string de=decrypt(en, e);
    cout << de << endl;

    return 0;
}
