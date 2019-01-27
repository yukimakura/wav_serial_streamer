# CMakeのバージョンを設定
cmake_minimum_required(VERSION 3.5)
# プロジェクト名と使用する言語を設定
project(wav_serial_streamer CXX)
set (CMAKE_CXX_STANDARD 11)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED system thread)


if(Boost_FOUND)
    message(STATUS "!!! BOOST FOUND !!!")
else()
    message(STATUS "!!! BOOST NOT FOUND !!!")
endif()

# a.outという実行ファイルをmain.cppとhello.cppから作成
add_executable(wav_serial_streamer main.cpp wave.cpp)
include_directories(${Boost_INCLUDE_DIR})

target_link_libraries(wav_serial_streamer ${Boost_LIBRARIES})