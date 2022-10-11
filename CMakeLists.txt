cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(params-cpp
        VERSION 2019.1.0
        DESCRIPTION "Params c++ library"
        LANGUAGES CXX)


set (params_cpp_files
        src/parser.cpp
        src/key.cpp)

add_library(params-cpp ${params_cpp_files})

target_link_libraries(params-cpp
        PUBLIC
        ${CURL_LIBRARIES})

set_target_properties(params-cpp
        PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED On
        CXX_EXTENSIONS Off
        VERSION ${PROJECT_VERSION})

if(MSVC)
    target_compile_options(params-cpp PRIVATE /W4)
else(MSVC)
    target_compile_options(params-cpp PRIVATE -Wall -Wextra -pedantic)
endif(MSVC)

include_directories( include )

target_include_directories(params-cpp
        SYSTEM INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)



###
### TESTS
###
find_package(CatchTests CONFIG QUIET)

###
### LIBRARY INSTALLATION
###

#if (CMAKE_BUILD_TYPE MATCHES Release)
    export(TARGETS params-cpp FILE ParamsCppConfig.cmake)

    include(GNUInstallDirs)

    install(TARGETS params-cpp EXPORT Params-cppConfig
            ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
            LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
            RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})

    install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

    install(EXPORT Params-cppConfig
            DESTINATION ${CMAKE_INSTALL_DATADIR}/cmake/Params-cpp
            EXPORT_LINK_INTERFACE_LIBRARIES)

    export(TARGETS params-cpp FILE Params-cppConfig.cmake)

    install(CODE "FILE(APPEND ${CMAKE_INSTALL_FULL_DATADIR}/cmake/Params-cpp/Params-cppConfig.cmake \"find_package(CURL REQUIRED)\n\") ")
#endif()
