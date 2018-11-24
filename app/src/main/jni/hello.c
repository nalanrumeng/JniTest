//

//
//
// Created by Shinelon on 2018/11/13.
//
#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include <string.h>
#include "process_communication_huige_com_myapplication_MainActivity.h"
#include <android/log.h>

#define TAG    "myhello-jni-test" // 这个是自定义的LOG的标识
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__) // 定义LOGD类型


JNIEXPORT jstring JNICALL Java_process_1communication_huige_com_myapplication_MainActivity_sayHello(JNIEnv *env, jobject j_obj, jstring j_str,jboolean flag) {
    // new 一个字符串，返回Hello World
//    const char *c_str = NULL;
    char buff[128] = { 0 };

    //GetStringChars则会出现字符串被截断的现象
    //在调用 GetStringUTFChars 函数从 JVM 内部获取一个字符串之后，
    // JVM 内部会分配一块新的内存，用于存储源字符串的拷贝，以便本地代码访问和修改。
    // 即然有内存分配，用完之后马上释放是一个编程的好习惯。
    // 通过调用ReleaseStringUTFChars 函数通知 JVM 这块内存已经不使用了，你可以清除了。
    // 注意：这两个函数是配对使用的，用了 GetXXX 就必须调用 ReleaseXXX，而且这两个函数的命名也有规律
    const char *c_str = (*env)->GetStringUTFChars(env, j_str, 0);
    LOGD("########## i = %s", c_str);
    if (c_str == NULL)
    {
        printf("out of memory.\n");
        return NULL;
    }
    int len = strlen(c_str);
    char n_name[len];
    strcpy(n_name, c_str);
    char * name=n_name;
    char *s;
    char * jniResponse=" 我来自jni";
    s=strcat(name,jniResponse);

    LOGD("########## i = %s", s);

    (*env)->ReleaseStringUTFChars(env, j_str, c_str);
//    printf("Java Str:%s\n", c_str);
//    sprintf(buff, "hello %s", c_str);
//    LOGD("########## i = %s", c_str);
    return (*env)->NewStringUTF(env, s);

}



