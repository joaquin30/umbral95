#ifndef ORB_HPP
#define ORB_HPP

#include "entity.hpp"

class Orb : public Entity {
public:
    Orb(float2);
    void set_pos(float, float);
    void draw(Term::Renderer&) override;
};

#endif
