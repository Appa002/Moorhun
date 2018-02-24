#include "../../Simple2DSource/header/Simple2D.h"
#include "../../Simple2DSource/header/MapManager.h"
#include <stdlib.h>
#include <time.h>

/*
Moorhun GameObject
Explanation
The Logic in a GameObject is in a class of any name which extends Behavior.
A GameObject must implement the functions "init()", "update()", "setup()" and can implement "onRemoval()", "onEvent(SDL_Event& e)", "fixedUpdate()".

A GameObject can have Attributes these get registered by using the function addAttribute<class T>(std::string name, T* pointerToAttribute).
T must be the type of the Attribute. The Value of an Attribute is gotten by calling getAttribute<class T>(std::string name) T must be the type of the Attribute.
 If T is not the correct an error is thrown.

You can register any variable as an attribute but attributes with the name "position" or "scale" have special meaning
where "position" is the position of the gameObject on the screen.
(If the camera is at position 0,0 than -1, -1 is the lower left corner and 1,1 is the upper right corner).
Scale is the space a Game Object takes up on the screen
(If the camera is at position 0,0 a scale of 1,1 will take up the entire screen).

The Behavior of a Game Object is encapsulated in an object of class "gameObject" this class contains various methods (see docs).
You can get a other Game Object by its name using findGameObject(std::string name).
Or by the address of its Behavior using findGameObject(Behavior* address).

Therefor findGameObject(this) will return the instance of gameObject which encapsulates the behavior from which it is called.
This can be used to change the Sprite of a Game Object or to remove it.
 * */


using namespace Simple2D;
class Moorhun : public Behavior{
public:
    Vec3* scale = nullptr;
    Vec3* position = nullptr;
    Vec3* velocity = nullptr;
    double oldMXPos = 0;
    double oldMYPos = 0;
    bool hit = false;

    /*
     * Called once during the Engine loads the Map, not all GameObjects have been loaded at that point so findGameObject
     * is dangours and will most likely return a null pointer. Use this setup attributes
     * */
    void init() override {
        srand (time(NULL));
        float changedVel = rand() % 60 + 1;
        velocity = new Vec3((float)1/(84 + changedVel), (float)1/20, (float)0/1);
        scale = new Vec3((float)1/7, (float)1/7, (float)1/7);
        position = new Vec3(-1.0f, -1.0f, 0.0f);

        addAttribute<Vec3>("scale", scale);
        addAttribute<Vec3>("position", position);
    }

    /*
     * Called once after all GameObjects have been loaded.
     * Use this for further setup which depends on other gameObjects
     * */
    void setup() override {
    }

    /*
     * Called every frame. Put main logic here.
     * */
    void update() override{
        // Finds the GameObject called "Camera" and uses its behavior to check if the Attribute halt == true
        if(findGameObject("Camera")->behavior->getAttribute<bool>("halt"))
            return;

        // A Clone of Moorhun is constructed by the gameObject "Camera" called "ReferenceHuhn".
        // If this behavior belongs to it do not execute any logic.
        if(findGameObject(this)->name == "ReferenceHuhn")
            return;

        if(position->y < -1.0f){
            // This will remove the GameObject this behavior belongs to.
            // Note: the gameObject will be removed after all gameObjects
            // have updated. This means the Frame in which remove() is called in
            // will be fully rendered before anything gets removed.
            findGameObject(this)->remove();

            // If this Morrhun has been clicked on do not subtract a live of the players count.
            if(hit)
                return;

            // Gets the current amount of lives the player has by querying it from the
            // "Camera" object and then sets the same attribute to curLives - 1.
            int curLives = findGameObject("Camera")->behavior->getAttribute<int>("lives");
            findGameObject("Camera")->behavior->setAttribute<int>("lives", curLives - 1);
            return;

        }

        position->y += velocity->y;
        position->x += velocity->x;

        velocity->y -= (float)1/1100;
    }

    /*
     * Called for every event sdl detected.
     * */
    void onEvent(SDL_Event& e) override {
        // A Clone of Moorhun is constructed by the gameObject "Camera" called "ReferenceHuhn".
        // If this Behavior belongs to it don't deal with any events.
        if(findGameObject(this)->name == "ReferenceHuhn")
            return;

        if(e.type == SDL_MOUSEMOTION){
            // Gets the currently loaded Map from MapManager and from it the window size.
            double windowSizeX = MapManager::get()->getCurrentMap()->getWindowSizeX();
            double windowSizeY = MapManager::get()->getCurrentMap()->getWindowSizeY();
            // SDL provides the cords of the mouse in the amount of pixels from the upper left
            // corner. This transforms them to be like OpenGLs coordinate system. (and in which the position attribute functions)
            // Eg. 0,0 is the middle and -1,1 is the upper left corner.
            oldMXPos = 2 * (e.motion.x / windowSizeX) - 1.0f;
            oldMYPos = -2 * (e.motion.y / windowSizeY) + 1.0f;

        } else if(e.type == SDL_MOUSEBUTTONDOWN){
            if(position->x - scale->x  / 2 < oldMXPos &&
                    position->x + scale->x / 2 > oldMXPos &&
                    position->y - scale->y < oldMYPos &&
                    position->y + scale->y > oldMYPos){
                // Loads a different sprite for the Game Object this Behavior belongs to.
                findGameObject(this)->loadNewSprite("./Moorhun/hit.png");
                hit = true;
            }
        }
    }

    /*
     * Called when the GameObject is about to be destroyed use this to delete
     * any remaining Attributes to avoid memory leaks.
     * */
    void onRemoval() override {
        delete velocity;
        deleteAttribute<Vec3>("position");
        deleteAttribute<Vec3>("scale");
    }

};

REGISTER_GAME_OBJECT(Moorhun)