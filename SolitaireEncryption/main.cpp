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
    Card c1(1), c2(39),c3("joker",1), c4("heart", 13);
    c1.output();
    c2.output();
    c3.output();
    c4.output();
    cout << endl;
}


int main(int argc, const char * argv[]) {
    test_card();
    
    return 0;
}
