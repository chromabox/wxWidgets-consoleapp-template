cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(wxBUILD_SHARED OFF)
set(DEFAULT_BUILD_TYPE "Release")
set(CMAKE_C_FLAGS_DEBUG "-g3 -Og")
set(CMAKE_C_FLAGS_RELEASE "-g -O2")

set(wxUSE_GUI OFF)

# must be
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)


project(wx_console_app)

find_package(wxWidgets COMPONENTS base xml net)

if(wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

set(INC_DIRS
  include
)

set(SRC_FILES
  src/appmain.cpp
)


add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${INC_DIRS})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
add_compile_definitions(wxUSE_GUI=0)

target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
