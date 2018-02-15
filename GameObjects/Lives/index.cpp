#include "../../Simple2DSource/header/Simple2D.h"
#include <functional>

using namespace Simple2D;
class Lives : public Behavior{
public:
    Vec3* position = nullptr;
    static unsigned int amountOfLiveObjects;
    unsigned int myId;

    void init() override {
        position = new Vec3(-0.5f, 0.7f, 0.0f);

        addAttribute<Vec3>("position", position);
        addAttribute<Vec3>("scale", new Vec3((float)1/20,(float)1/10, (float)1/10));
    }

    void setup() override {
        if(findGameObject("Camera")->behavior->getAttribute<bool>("halt"))
            return;

        myId = amountOfLiveObjects;
        if (amountOfLiveObjects < 2) {
            amountOfLiveObjects++;
            cloneGameObject(findGameObject(this), "Lives_" + std::to_string(amountOfLiveObjects));
        }
        if (myId != 0) {
            auto obj = findGameObject("Lives_" + std::to_string(myId - 1));
            obj->behavior->setAttribute<Vec3>("position", Vec3(position->x + 0.1f, position->y, position->z));
        }
    }
    void update() override {

    }
};

unsigned int Lives::amountOfLiveObjects = 0;

REGISTER_GAME_OBJECT(Lives)