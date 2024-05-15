cmake_minimum_required(VERSION 3.27)
project(aamstest)

set(CMAKE_CXX_STANDARD 17)

include_directories("C:\\Program Files\\MySQL\\MySQL Server 8.3\\include")
link_directories("C:\\Program Files\\MySQL\\MySQL Server 8.3\\lib")
link_libraries(libmysql)

add_executable(aamstest main.cpp)

target_link_libraries(aamstest libmysql)