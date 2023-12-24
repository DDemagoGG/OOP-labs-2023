#pragma once
#include "npc.h"

class Bear : public NPC {
    public:
        Bear(const int &x, const int &y);

        virtual int accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<NPC>& attacker) override;
};

class VisitorBear: public Visitor {
    public: 
        bool visit(std::shared_ptr<Orc> defender) override;
        bool visit(std::shared_ptr<Bear> defender) override;
        bool visit(std::shared_ptr<Squirrel> defender) override;
};

class BearFactory : public Factory {
    public:
        std::shared_ptr<NPC> create(int x, int y) override;
        std::shared_ptr<NPC> create(std::istream &is) override;
        std::shared_ptr<NPC> create(std::ifstream &ifs) override;
};