#include "../../Simple2DSource/header/Simple2D.h"

using namespace Simple2D;
class LivesText : public Behavior{
public:
    Vec3* position = nullptr;

    void init() override {
        position = new Vec3(-0.7f, 0.7f, 0.0f);
        addAttribute<Vec3>("position", position);
        addAttribute<Vec3>("scale", new Vec3((float)1/8, (float)1/8, (float)1/8));
    }

    void setup() override {

    }

    void update() override {

    }
};

REGISTER_GAME_OBJECT(LivesText)