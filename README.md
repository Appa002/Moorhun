# Moorhun
Small example made for my "Simple2D" game engine

# Code explanation
To execute any code one has to create Game Objects. In this example these are "Camera", "Background", "Lives", "LivesText" and "Moorhun".
The code for which is in the folder "GameObjects".

In this folder you will also find a file called "0.lua"; this is the map, it defines which GameObjects exist. The Engine loads every Game Object by first looking at 0.lua and then looking for a folder with the same name as the Game Object.
A Game Object can have any name except "Camera"; it's special.
More on this later.
If you where to look inside a folder for a GameObject, for instance "Moorhun", you will find a few files. (The Path to Moorhun's Game Object is "GameObjects/Moorhun").

| Name:         | Function:                                  | Reguired?      |
| ------------  | ------------------------------------------ | ------------   |
| "cfg.lua"     | Defines the Name of the GameObject         | Yes            |
| "sprite.png"  | Sprite autoloaded by the engine            | No             |
| "index.cpp"   | Gets Compiled to "extenal.so" which is autoloaded by the engine and contains the logic | Yes|
| "hit.png"     | Sprite for when the moorhun gets hit i.e. clicked on. | No |
| "CMakeLists.txt"| Contains cmake rules for compiling this gameobject. | Kinda |
 
You may use any build system you want, the CMakeLists file is completly setup for building; use that as guidance.

Look at Moorhun's index.cpp file to see how a Game Object is build, it conatins comments explaining game object code in general.

### GameoObjects called "Camera"
If a gameobject called Camera exists, then the Engine will use the camera gameobject position to transform all other objects. This means when you move the camera gameobject you can move around the game world. (You see the world "through" the camera).

To Execute anything you have to have the engine executable in the same directory as youre "0.lua" file and your Game Objects.
