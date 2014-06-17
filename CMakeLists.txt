cmake_minimum_required(VERSION 2.8)
project(pack)

set(bd ${CMAKE_CURRENT_LIST_DIR})
set(sd ${bd}/src)

include_directories(${sd})

add_library(pack ${sd}/pack.c)

install(TARGETS pack ARCHIVE DESTINATION lib)
install(FILES ${sd}/pack.h ARCHIVE DESTINATION include)