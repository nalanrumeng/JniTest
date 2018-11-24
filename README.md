# JniTest
 这是一个jni测试小demo。主要是把java端数据通过native函数传给c层，c层再通过jni把处理后的数据回传给java层。  
 开发工具使用的是Android Studio 2.2.2; ndk是NDK-r14。 (ps:NDK-r17以上的版本已不支持构造armeabi的so包)  
 在hello.c文件中还添加了Log打印日志  
 注意要配置Log日志，在Android Studio中build.gradle的ndk节点要加下以下内容  
   ndk {   
              moduleName 'hello'  
              abiFilters "armeabi", "armeabi-v7a","x86"  
              ldLibs "log"     //Android Studio要加上，否则无法识别Log  
         }
 
