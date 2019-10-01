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
}

void test_deck(){
    Deck d;
}


int main(int argc, const char * argv[]) {
    test_card();
    test_deck();
    return 0;
}
