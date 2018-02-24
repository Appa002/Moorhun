# Moorhun
Small example made for my "Simple2D" game engine

# Code explanation
To execute any code one has to create Game Objects. In this example these are "Camera", "Background", "Lives", "LivesText", "Moorhun".
The code for which is in the folder "GameObjects".

I this folder you will also find a file called "0.lua". This is the map, it defines which GameObjects exist. The Engine loads every Game Object by first looking at 0.lua and then looking for a folder with the same name as the Game Object.
A Game Object can have any name, except "Camera" it's special.
More to this later.
When you look inside a folder for a GameObject for instance "Moorhun", you will find a few files. (The Path to Moorhun's Game Object is "GameObjects/Moorhun").

+--------------------------------------------------------------------------------+
| Name:         | Function:                                  | Reguired?      |
| "cfg.lua"     | Defines the Name of the GameObject         | Yes            |
| "sprite.png"  | Sprite autoloaded by the engine            | No             |
| "index.cpp"   | Gets Compiled to "extenal.so" which is     |                |
          autoloaded by the engine and contains the logic    | Yes            |
+---------------------------------------------------------------------------------+
 
In the Game Object "Moorhun" you will also find "hit.png", this is a sprite which gets manually loaded when you click on the Moorhun.
Look at Moorhun's index.cpp file to see how a Game Object is build.


If a GameObject with the name "Camera" exists the Engine will use its position to transform all other objects. This means when you move the camera you can move around the game world.

To Execute anything you have to have the engine executable in the same level as youre "0.lua" file and your Game Objects.
