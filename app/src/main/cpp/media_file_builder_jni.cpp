#include <jni.h>

#include "media_file_builder.h"
#include "frame_extractor.h"

// File with JNI bindings for MediaFileBuilder java class.

extern "C" void
Java_com_infostride_myapplication_creator_MediaFileBuilder_nativeCreateFromFD(JNIEnv *,
                                                                              jobject instance,
                                                                              jint fileDescriptor,
                                                                              jint mediaStreamsMask) {
    media_file_build(instance, fileDescriptor, mediaStreamsMask);
}
extern "C" void
Java_com_infostride_myapplication_creator_MediaFileBuilder_nativeCreateFromAssetFD(JNIEnv
*env,
jobject instance,
        jint
assetFileDescriptor,
jlong startOffset,
        jstring
jShortFormatName,
jint mediaStreamsMask
) {
const char *cShortFormatName = env->GetStringUTFChars(jShortFormatName, nullptr);

media_file_build(instance, assetFileDescriptor, startOffset, cShortFormatName, mediaStreamsMask);

env->ReleaseStringUTFChars(jShortFormatName, cShortFormatName);
}
extern "C" void
Java_com_infostride_myapplication_creator_MediaFileBuilder_nativeCreateFromPath(JNIEnv
*env,
jobject instance,
        jstring
jFilePath,
jint mediaStreamsMask
) {
const char *cFilePath = env->GetStringUTFChars(jFilePath, nullptr);

media_file_build(instance, cFilePath, mediaStreamsMask
);

env->
ReleaseStringUTFChars(jFilePath, cFilePath
);
}