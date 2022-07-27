cmake_minimum_required(VERSION 3.5)
project(FreeRTOSMinGW)

file(GLOB FreeRTOSSrc FreeRTOS/*.c FreeRTOS/include/*.h FreeRTOS/portable/*.c
     FreeRTOS/portable/*.h)

set(SOURCE_FILES main.c ${FreeRTOSSrc})
include_directories(. FreeRTOS/include FreeRTOS/portable)
add_executable(tasks ${SOURCE_FILES})
target_link_libraries(tasks WinMM.lib)

# learning event groups
add_executable(event_groups main_event_group.c ${FreeRTOSSrc})
target_link_libraries(event_groups WinMM.lib)

# learning timers
add_executable(timers main_timers.c ${FreeRTOSSrc})
target_link_libraries(timers WinMM.lib)
