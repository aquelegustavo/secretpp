cmake_minimum_required(VERSION 3.5)

project(secretpp LANGUAGES CXX)
project("./src")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(secretpp SHARED

  )
else()
  add_executable(secretpp

      # Main
      src/main.cpp

      # Widgets

          # App widget
          src/secretpp.cpp
          src/secretpp.h
          src/secretpp.ui

          # HomePage widget
          src/pages/home/home.cpp
          src/pages/home/home.h
          src/pages/home/home.ui

      # Bibliotecas

          # DB
          src/lib/db/db.h
          src/lib/db/db.cpp

          # Bcrypt
          src/lib/bcrypt/bcrypt.h
          src/lib/bcrypt/bcrypt.cpp

          # Json
          # Biblioteca exportada como .hpp
    )
endif()

target_link_libraries(secretpp PRIVATE Qt5::Widgets)
