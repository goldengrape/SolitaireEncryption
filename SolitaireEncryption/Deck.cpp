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

Deck::Deck(){
    seq.reserve(54);
    for(int i=1;i<=54;i++){
        Card c(i);
        seq.push_back(c);
    }
}

