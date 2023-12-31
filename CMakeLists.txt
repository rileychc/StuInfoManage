cmake_minimum_required(VERSION 3.5)

project(
  StuInfoManage
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

aux_source_directory(./include myHeader)
# aux_source_directory(./src DIR_SRCS)
include_directories(./include /opt/homebrew/opt/mysql-client/include/mysql)
set(myLIBRARY_PATH /opt/homebrew/opt/mysql-client/lib/)
find_library(mylib mysqlclient ${myLIBRARY_PATH})
link_libraries(${mylib}) # 链接静态库

set(PROJECT_SOURCES
    ./include/mainwindow.h
    ./include/BaseCtl.h
    ./include/Punishment.h
    ./include/Reward.h
    ./include/Department.h
    ./include/Change.h
    ./include/Class.h
    ./include/Student.h
    main.cpp
    ./src/mainwindow.cpp
    ./src/slot_delete.cpp
    ./src/slot_input.cpp
    ./src/slot_query.cpp
    ./src/slot_update.cpp
    ./src/BaseCtl.cpp
    ./src/insertctl.cpp
    ./include/mainwindow.ui)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(StuInfoManage MANUAL_FINALIZATION ${PROJECT_SOURCES}
  )
  # Define target properties for Android with Qt 6 as: set_property(TARGET
  # StuInfoManage APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
  # ${CMAKE_CURRENT_SOURCE_DIR}/android) For more information, see
  # https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
  if(ANDROID)
    add_library(StuInfoManage SHARED ${PROJECT_SOURCES})
    # Define properties for Android with Qt 5 after find_package() calls as:
    # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
  else()
    add_executable(StuInfoManage ${PROJECT_SOURCES})
  endif()
endif()

target_link_libraries(StuInfoManage PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1. If
# you are developing for iOS or macOS you should consider setting an explicit,
# fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.StuInfoManage)
endif()
set_target_properties(
  StuInfoManage
  PROPERTIES ${BUNDLE_ID_OPTION} MACOSX_BUNDLE_BUNDLE_VERSION
             ${PROJECT_VERSION} MACOSX_BUNDLE_SHORT_VERSION_STRING
             ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR} MACOSX_BUNDLE
             TRUE WIN32_EXECUTABLE
             TRUE)

include(GNUInstallDirs)
install(
  TARGETS StuInfoManage
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(StuInfoManage)
endif()
