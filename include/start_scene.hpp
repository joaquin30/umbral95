#ifndef START_SCENE_HPP
#define START_SCENE_HPP

#include "scene.hpp"

class StartScene : public Scene {
    const int SCREEN_WIDTH, SCREEN_HEIGHT;
public:
    StartScene(int, int);
    state manage_events(int, float) override;
};

#endif //START_SCENE_HPP
