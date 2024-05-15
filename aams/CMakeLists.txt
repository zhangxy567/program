cmake_minimum_required(VERSION 3.27)
project(aams)

set(CMAKE_CXX_STANDARD 17)

include_directories("C:\\Program Files\\MySQL\\MySQL Server 8.3\\include")
link_directories("C:\\Program Files\\MySQL\\MySQL Server 8.3\\lib")
link_libraries(libmysql)

add_executable(aams main.cpp
        basis.h
        func.h
        menu_func.cpp
        mysql_func.cpp
        etrdef.h
        another_func.cpp)

target_link_libraries(aams libmysql)