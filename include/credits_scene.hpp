#ifndef CREDITS_SCENE_HPP
#define CREDITS_SCENE_HPP

#include "scene.hpp"

struct CreditsScene : public Scene {
    CreditsScene(int, int);
    state manage_events(int, float) override;
};

#endif //CREDITS_SCENE_HPP
