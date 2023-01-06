cmake_minimum_required(VERSION 3.2)

option(PREPROC_CONFIG_INSTALL_LIBRARY "Whether to install the library or not"
       OFF)

option(WINDOWS_EXPORT_SYMBOLS "Whether to export symbols on Windows or not" OFF)

project(
  PREPROC_CONFIG
  VERSION 1.0.0
  DESCRIPTION "Common pre-processor definitions"
  HOMEPAGE_URL "https://github.com/vitimiti/preproc_config"
  LANGUAGES C CXX)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(
  ${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDE_DIR}>)

if(WIN32 AND WINDOWS_EXPORT_SYMBOLS)
  add_compile_definitions(WINDOWS_EXPORT_SYMBOLS)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

include(GNUInstallDirs)
if(PREPROC_INSTALL_LIBRARY)
  message(TRACE
          "Configuring installation system with prefix ${CMAKE_INSTALL_PREFIX}")

  install(
    TARGETS PREPROC_CONFIG
    EXPORT PREPROC_CONFIG_TARGETS
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR})

  include(CMakePackageConfigHelpers)
  write_basic_package_version_file(
    "preproc_config-config-version.cmake"
    VERSION ${PREPROC_CONFIG_VERSION}
    COMPATIBILITY SameMajorVersion)

  configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/cmake/preproc_config-config.cmake.in"
    "${PROJECT_BINARY_DIR}/preproc_config-config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/preproc_config)

  install(
    EXPORT PREPROC_CONFIG_TARGETS
    FILE preproc_config-targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/preproc_config)

  install(FILES "${PROJECT_BINARY_DIR}/preproc_config-config.cmake"
                "${PROJECT_BINARY_DIR}/preproc_config-config-version.cmake"
          DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/preproc_config)

  install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/preproc_config
          DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endif()
