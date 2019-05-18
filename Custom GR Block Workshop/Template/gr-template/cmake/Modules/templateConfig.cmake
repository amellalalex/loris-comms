INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_TEMPLATE template)

FIND_PATH(
    TEMPLATE_INCLUDE_DIRS
    NAMES template/api.h
    HINTS $ENV{TEMPLATE_DIR}/include
        ${PC_TEMPLATE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    TEMPLATE_LIBRARIES
    NAMES gnuradio-template
    HINTS $ENV{TEMPLATE_DIR}/lib
        ${PC_TEMPLATE_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TEMPLATE DEFAULT_MSG TEMPLATE_LIBRARIES TEMPLATE_INCLUDE_DIRS)
MARK_AS_ADVANCED(TEMPLATE_LIBRARIES TEMPLATE_INCLUDE_DIRS)

