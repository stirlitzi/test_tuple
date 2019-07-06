cmake_minimum_required(VERSION 3.2)
project(tuple VERSION)

set(CMAKE_CXX_STANDARD 17)

add_executable(tuple_cli main.cpp)


set_target_properties(tuple_cli PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )


install(TARGETS tuple_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
