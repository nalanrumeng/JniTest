//

//
//
// Created by Shinelon on 2018/11/13.
//
#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include "process_communication_huige_com_myapplication_MainActivity.h"
#include <android/log.h>

#define TAG    "myhello-jni-test" // 这个是自定义的LOG的标识
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__) // 定义LOGD类型


JNIEXPORT jstring JNICALL Java_process_1communication_huige_com_myapplication_MainActivity_sayHello(JNIEnv *env, jobject j_obj, jstring j_str,jboolean flag) {
    // new 一个字符串，返回Hello World
//    const char *c_str = NULL;
    char buff[128] = { 0 };

    //GetStringChars则会出现字符串被截断的现象
    const char *c_str = (*env)->GetStringUTFChars(env, j_str, 0);
    LOGD("########## i = %s", c_str);
    if (c_str == NULL)
    {
        printf("out of memory.\n");
        return NULL;
    }
    (*env)->ReleaseStringChars(env, j_str, c_str);
    printf("Java Str:%s\n", c_str);
    sprintf(buff, "hello %s", c_str);
    LOGD("########## i = %s", c_str);
    return (*env)->NewStringUTF(env, c_str);

}
