#ifndef ORB_HPP
#define ORB_HPP

#include "entity.hpp"

class Orb : public Entity {
public:
    Orb(float2);
    void draw(Term::Renderer&) override;
};

#endif
