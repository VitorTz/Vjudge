# Definir a versão mínima do CMake necessária e o nome do projeto
cmake_minimum_required(VERSION 3.28)
project(VJudged)

# Definir a versão padrão do C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.hpp")
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
add_executable (${PROJECT_NAME} ${sources} ${headers})
