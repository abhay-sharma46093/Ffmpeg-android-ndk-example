# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.
#set(-DANDROID_NDK= "/home/abhay/Android/Sdk/ndk/17.2.4988734")
#set(-DCMAKE_ANDROID_NDK= "/home/abhay/Android/Sdk/ndk/17.2.4988734")
project("myapplication")

#[[find_library(libavcodec
        avcodec
        PATHS
        ${CMAKE_SOURCE_DIR}/../jni/${CMAKE_ANDROID_ARCH_ABI})
if (NOT libavcodec)
    message(FATAL_ERROR "AVCODEC not found! --> ${CMAKE_SOURCE_DIR}/../jni/${CMAKE_ANDROID_ARCH_ABI} ")
endif()]]
#[[
set(CMAKE_CXX_FLAGS="${CMAKE_CXX_FLAGS} -DANDROID_NDK -O2 -D__STDC_CONSTANT_MACROS
                       -DFROM_PGMS -D_GXX_EXPERIMENTAL_CXX0X_=-fexceptions")]]
add_library(avcodec SHARED IMPORTED)
add_library(avdevice SHARED IMPORTED)
add_library(avfilter SHARED IMPORTED)
add_library(avutil SHARED IMPORTED)
add_library(avformat SHARED IMPORTED)
add_library(swresample SHARED IMPORTED)
add_library(swscale SHARED IMPORTED)

set_target_properties(avcodec PROPERTIES IMPORTED_LOCATION
        /home/abhay/AndroidStudioProjects/Ffmpegandroidndkexample/app/src/main/jni/lib/${ANDROID_ABI}/libavcodec.so)
set_target_properties(avdevice PROPERTIES IMPORTED_LOCATION
        /home/abhay/AndroidStudioProjects/Ffmpegandroidndkexample/app/src/main/jni/lib/${ANDROID_ABI}/libavdevice.so)
set_target_properties(avfilter PROPERTIES IMPORTED_LOCATION
        /home/abhay/AndroidStudioProjects/Ffmpegandroidndkexample/app/src/main/jni/lib/${ANDROID_ABI}/libavfilter.so)
set_target_properties(avformat PROPERTIES IMPORTED_LOCATION
        /home/abhay/AndroidStudioProjects/Ffmpegandroidndkexample/app/src/main/jni/lib/${ANDROID_ABI}/libavformat.so)
set_target_properties(avutil PROPERTIES IMPORTED_LOCATION
        /home/abhay/AndroidStudioProjects/Ffmpegandroidndkexample/app/src/main/jni/lib/${ANDROID_ABI}/libavutil.so)
set_target_properties(swresample PROPERTIES IMPORTED_LOCATION
        /home/abhay/AndroidStudioProjects/Ffmpegandroidndkexample/app/src/main/jni/lib/${ANDROID_ABI}/libswresample.so)
set_target_properties(swscale PROPERTIES IMPORTED_LOCATION
        /home/abhay/AndroidStudioProjects/Ffmpegandroidndkexample/app/src/main/jni/lib/${ANDROID_ABI}/libswscale.so)

include_directories("/home/abhay/AndroidStudioProjects/Ffmpegandroidndkexample/app/src/main/cpp/include")


add_library( # Sets the name of the library.
        myapplication

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        main.cpp
        media_file_builder.cpp
        media_file_builder_jni.cpp
        frame_loader_context.cpp
        frame_loader_context_jni.cpp
        frame_extractor.cpp
        utils.cpp
        native-lib.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.


find_library( # Sets the name of the path variable.
        log-lib

        avcodec
        avfilter
        avdevice
        avutil
        avformat
        swscale
        swresample
        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)


# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        myapplication

        jnigraphics
        avcodec
        avfilter
        avdevice
        avutil
        avformat
        swscale
        swresample
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})