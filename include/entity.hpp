#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "renderer.hpp"

class Entity {
protected:
    float2 pos;

public:
    Entity(float2 p) : pos{p} {}
    virtual ~Entity() {}
    float2 get_pos() { return pos; }
    virtual void draw(Term::Renderer&) = 0;
};

#endif
