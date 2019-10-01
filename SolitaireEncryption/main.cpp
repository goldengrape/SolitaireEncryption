//
//  main.cpp
//  SolitaireEncryption
//
//  Created by GoldenGrape on 2019/10/1.
//  Copyright © 2019 goldengrape. All rights reserved.
//

#include <iostream>
#include "Deck.hpp"

void test_card(){
    Card c1(1), c2(39),c3("joker",1), c4("heart", 13), c5, c6=c1;
    c1.output();    cout << endl;
    c2.output();    cout << endl;
    c3.output();    cout << endl;
    c4.output();    cout << endl;
    c5.output();    cout << endl;
    cout << "test done"<< endl;
}

void test_deck_output(Deck &d){
    vector<int> s={0,1,2,3,50,51,52,53};
    for (int i:s){
        cout << i <<":";
        d.get_card(i).output(); cout << endl;
    }
    cout << endl;
}
void test_deck(){
    Card joker_A("joker",1), joker_B(54);
    Deck d;
    cout << endl;
    d.move_one_down(joker_A);
    d.move_two_down(joker_B);
    test_deck_output(d);
    d.triple_cut(1,52);
    test_deck_output(d);

}


int main(int argc, const char * argv[]) {
//    test_card();
    
    test_deck();
    return 0;
}
