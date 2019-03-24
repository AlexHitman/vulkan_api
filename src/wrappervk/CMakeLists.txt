set(SOURCES wrappervk.cpp)
set(HEADERS wrappervk.h)

add_library(wrappervk ${SOURCES} ${HEADERS})

target_include_directories (wrappervk PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
