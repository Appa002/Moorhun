cmake_minimum_required(VERSION 3.0)
project(CameraGameObject)

set(CMAKE_CXX_STANDARD 17)

ADD_COMPILE_OPTIONS()

add_library(CameraGameObject SHARED index.cpp ../../Simple2DSource/header/Simple2D.h
        ../../Simple2DSource/src/Simple2D.cpp ../../Simple2DSource/header/types.h
        ../../Simple2DSource/src/GameObject.cpp ../../Simple2DSource/header/singleton.h
        ../../Simple2DSource/header/Engine.h ../../Simple2DSource/src/Map.cpp ../../Simple2DSource/header/Map.h
        ../../Simple2DSource/header/GameObject.h ../../Simple2DSource/header/Utils.h ../../Simple2DSource/header/ExternalCodeLoadingWrapper.h
        ../../Simple2DSource/src/MapManager.cpp ../../Simple2DSource/header/MapManager.h ../../Simple2DSource/header/types.h)

set_target_properties(CameraGameObject PROPERTIES PREFIX "")
set_target_properties(CameraGameObject PROPERTIES OUTPUT_NAME "external")
