cmake_minimum_required(VERSION 3.10)
project(MiniHydro)

# Set policy
if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -march=native")

# Find Kokkos
set(Kokkos_DIR "./kokkos/build")
find_package(Kokkos REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB SOURCES "src/*.cpp")

add_executable(run.run ${SOURCES})

# Link Kokkos to your target
target_link_libraries(run.run m Kokkos::kokkos)