cmake_minimum_required(VERSION 4.0.1)

# https://github.com/llvm/llvm-project/issues/135459
# https://github.com/matiassimon/cmake-modules-example/blob/main/CMakeLists.txt

if (APPLE)
    set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")
    set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")

    # Upstream clang doesn't set macOS's sysroot automatically
    execute_process(
            COMMAND xcrun --show-sdk-path
            OUTPUT_VARIABLE MACOS_SDK_PATH
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    set(CMAKE_OSX_SYSROOT ${MACOS_SDK_PATH})
elseif (UNIX)
    # TODO: set clang for linux
#    set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")
#    set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")
endif ()

project(HelloCppModules)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(HelloCppModules
        src/main.cpp)

target_sources(HelloCppModules
    PUBLIC
        FILE_SET modules
        TYPE CXX_MODULES
        FILES
            src/modules/AdvancedTrigonometry.cppm
)

if (APPLE)
    # std.cppm needs to be compiled with:
    # ./clang++ -std=c++23 -stdlib=libc++ -Wno-reserved-identifier -Wno-reserved-module-identifier \
    #     --precompile -o std.pcm /opt/homebrew/opt/llvm/share/libc++/v1/std.cppm
    target_compile_options(HelloCppModules PRIVATE -fmodule-file=std=/opt/homebrew/Cellar/llvm/19.1.7_1/bin/std.pcm)
elseif (UNIX)
    # TODO: set std.pcm for linux
endif ()
