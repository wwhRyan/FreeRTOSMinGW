cmake_minimum_required(VERSION 3.3)
project(protocol)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB FreeRTOSSrc
FreeRTOS/*.c
FreeRTOS/include/*.h
FreeRTOS/portable/*.c
FreeRTOS/portable/*.h
)


set(SOURCE_FILES main.c ${FreeRTOSSrc})
include_directories(. FreeRTOS/include FreeRTOS/portable)


add_executable(protocol ${SOURCE_FILES})


# find_library(LIBWMM WinMM)    # for windows 10, which does not having visual studio.
target_link_libraries(protocol WinMM.lib)

#learning event groups
add_executable(event_groups main_event_group.c ${FreeRTOSSrc})
target_link_libraries(event_groups WinMM.lib)