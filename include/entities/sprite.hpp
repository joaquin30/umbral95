#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "entity.hpp"

class Sprite : public Entity {
protected:
    float2 vel;
    float e_vel, angle, ang_vel;
    std::vector<float2> points;

public:
    Sprite(float2);
    virtual ~Sprite();
    virtual void move_forward();
    virtual void move_backwards();
    virtual void rotate_right();
    virtual void rotate_left();
    virtual void draw(Term::Renderer&) override;
};

#endif
