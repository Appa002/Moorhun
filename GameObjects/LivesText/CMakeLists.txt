cmake_minimum_required(VERSION 3.0)
project(LivesText)

set(CMAKE_CXX_STANDARD 11)

ADD_COMPILE_OPTIONS()

add_library(LivesText SHARED index.cpp ../../Simple2DSource/header/Simple2D.h
        ../../Simple2DSource/header/Behavior.h
        ../../Simple2DSource/src/Simple2D.cpp ../../Simple2DSource/header/types.h
        ../../Simple2DSource/src/GameObject.cpp ../../Simple2DSource/header/singleton.h
        ../../Simple2DSource/header/Engine.h ../../Simple2DSource/src/Map.cpp ../../Simple2DSource/header/Map.h
        ../../Simple2DSource/header/GameObject.h ../../Simple2DSource/header/Utils.h ../../Simple2DSource/header/ExternalCodeLoadingWrapper.h
        ../../Simple2DSource/src/MapManager.cpp ../../Simple2DSource/header/MapManager.h ../../Simple2DSource/header/types.h)

set_target_properties(LivesText PROPERTIES PREFIX "")
set_target_properties(LivesText PROPERTIES OUTPUT_NAME "external")
