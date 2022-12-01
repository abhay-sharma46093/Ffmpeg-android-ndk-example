#include <jni.h>

#include "frame_loader_context.h"
#include "frame_extractor.h"
#include <jni.h>

// File with JNI bindings for FrameLoader java class.

extern "C" void
Java_com_infostride_myapplication_FrameLoader_nativeRelease(JNIEnv
* env,
jclass clazz, jlong
handle) {
    frame_loader_context_free(jFrameLoaderContextHandle);
}


extern "C" jboolean
Java_com_infostride_myapplication_FrameLoader_nativeLoadFrame(JNIEnv *env, jclass,
                                                                   jlong jFrameLoaderContextHandle,
                                                                   jint index,
                                                                   jobject jBitmap) {
    bool successfullyLoaded = frame_extractor_load_frame(env, jFrameLoaderContextHandle, index, jBitmap);
    return static_cast<jboolean>(successfullyLoaded);
}
}