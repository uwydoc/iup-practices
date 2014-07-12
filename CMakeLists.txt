cmake_minimum_required(VERSION 2.6)
project(iup-examples)

# Configure MSVC runtime library ('/MD' or 'MT')
include(./configure_msvc_runtime.cmake)
set(MSVC_RUNTIME static)
configure_msvc_runtime()

set(IUP_ROOT $ENV{IUP_ROOT})
if(NOT IUP_ROOT)
    set(IUP_ROOT C:/Users/neo/Downloads/iup-3.10.1_Win32_vc10_lib)
endif()

include_directories(${IUP_ROOT}/include)
link_directories(${IUP_ROOT})
set(IUP_RESOURCES
    ${IUP_ROOT}/etc/iup.rc
    ${IUP_ROOT}/etc/iup.manifest
)

# login
add_executable(login login.cpp ${IUP_RESOURCES})
target_link_libraries(login
    iup gdi32 comdlg32 comctl32 uuid oleaut32 ole32
)

