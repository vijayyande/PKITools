cmake_minimum_required(VERSION 3.10)
project(EncodingConverter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(EncodingConverter WIN32 main.cpp)

target_link_libraries(EncodingConverter PRIVATE
    bcrypt
    ncrypt
    comdlg32
    comctl32
    shell32
    kernel32
    user32
    gdi32
)

target_compile_definitions(EncodingConverter PRIVATE
    UNICODE
    _UNICODE
    WINVER=0x0A00
    _WIN32_WINNT=0x0A00
    NTDDI_VERSION=0x0A00000A
)

if(MSVC)
    target_compile_options(EncodingConverter PRIVATE /W4 /utf-8)
    set_target_properties(EncodingConverter PROPERTIES
        LINK_FLAGS "/SUBSYSTEM:WINDOWS"
    )
endif()
