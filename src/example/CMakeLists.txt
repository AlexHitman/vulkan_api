set (SOURCES main.cpp)

add_executable (example ${SOURCES})

target_link_libraries (example LINK_PUBLIC wrappervk)
