#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <memory>

#include "player.h"
#include "badge.h"
#include "manager.h"
#include "balance.h"
#include "goalkeeper.h"
#include "ext/random.hpp"
#ifndef OOP_PACK_H
#define OOP_PACK_H

using Random = effolkronium::random_static;

class pack{
    int price;
    int nrOfPlayers;
    int nrOfBadges;
    int nrOfManagers;
    std::vector<std::shared_ptr<player>> players;
    std::vector<badge> badges;
    std::vector<manager> managers;

public:
//    int getPrice() const {return price; }
//    int getnrOfItems() const {return price; }
    const std::vector<std::shared_ptr <player>>& getPlayers() const;
    const std::vector<badge>& getBadges() const;
    const std::vector<manager>& getManagers() const;

    int getPrice() const;

    int getNrOfPlayers() const;

    int getNrOfBadges() const;

    int getNrOfManagers() const;

    pack(int price_, int nrOfPlayers_, int nrOfBadges_, int nrOfManagers_, const std::vector<std::shared_ptr <player>>& players_, const std::vector<badge>& badges_,
         const std::vector<manager>& managers_);

//    pack(pack& other) : price{other.price}, nrOfItems{other.nrOfItems}, players{other.players},
//                                                  badges{other.badges}, managers{other.managers} {
//
//        std::cout << "constructor de copiere pack\n";
//    }

    friend std::ostream& operator<<(std::ostream& os, const pack& pack);

    //metoda deschidere pachet
    bool open(balance &blnc, std::vector<std::shared_ptr<player>> poolPl, std::vector<badge> poolBdg, std::vector<manager> poolMngr);

    void clearPack();

    void popPlayer(int i);
    void popBadge(int i);
    void popManager(int i);

};


#endif //OOP_PACK_H
