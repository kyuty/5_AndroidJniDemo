#include <jni.h>
#include <string>
#include "jnipp/jnipp.h"
#include "android_jni_wrap/fwd.h"
//#include "android_jni_wrap/android.graphics.h"

#if defined(ANDROID)    // ANDROID
#include <android/log.h>

#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "123123", __VA_ARGS__)
#else                   // ANDROID
#define LOGE(...)
#endif                  // ANDROID

extern "C" JNIEXPORT jstring JNICALL
Java_com_wd_jnidemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_wd_jnidemo_MainActivity_initJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement initJNI()
}

extern "C"
JNIEXPORT void JNICALL
Java_com_wd_jnidemo_JniEnter_initJNI2(JNIEnv *env, jclass clazz) {
    // try catch method
    //try {
    //
    //} catch (jni::Exception e) {
    //
    //}

    LOGE("123123 init");
    jni::init(env);
    LOGE("123123 init end");

    {
        jni::Array<int> a(10);
        jni::Array<std::string> s(10);

        LOGE("a.getElement %s", a.getElement(0) == 0 ? "true" : "false");
        LOGE("s.getElement %s", s.getElement(0).length() == 0 ? "true" : "false");
    }

    {
        int width = 200;
        int height = 200;

        LOGE("123123 test 1");
        //wrap::android::graphics::Bitmap_Config config = wrap::android::graphics::Bitmap_Config::ARGB_8888();
        jni::Enum config("android/graphics/Bitmap$Config");
        LOGE("123123 test 2");
        jni::Object argb8888 = config.get("ARGB_8888");
        wrap::android::graphics::Bitmap bitmap = wrap::android::graphics::Bitmap::createBitmap((int32_t)width, (int32_t)height, argb8888);
        LOGE("123123 test 3");
        wrap::android::graphics::Canvas canvas = wrap::android::graphics::Canvas::construct(bitmap);
        LOGE("123123 test 4");
        wrap::android::graphics::Paint paint = wrap::android::graphics::Paint::construct();
        LOGE("123123 test 5");
        paint.setTextSize(24);
        LOGE("123123 test 6");
        paint.setColor(wrap::android::graphics::Color::BLACK());
        LOGE("123123 test 7");

        std::string text = "123123";
        float x = 50;
        float y = 100;

        canvas.drawText(text, x, y, paint);
        LOGE("123123 test 8");

        std::string dataFileDir = "/data/user/0/com.wd.jnidemo/files";
        wrap::java::io::File file = wrap::java::io::File::construct(dataFileDir);
        LOGE("123123 test 8 1");
        if (!file.exists()) {
            LOGE("123123 test 8 2");
            file.mkdirs();
            LOGE("123123 test 8 3");
        }
        std::string pngName = dataFileDir.append("/123123.png");
        wrap::java::io::FileOutputStream stream = wrap::java::io::FileOutputStream::construct(pngName);
        LOGE("123123 test 9");
        jni::Enum compressFormat("android/graphics/Bitmap$CompressFormat");
        LOGE("123123 test 10");
        jni::Object pngObject = compressFormat.get("PNG");
        bitmap.compress(pngObject, 100, stream.object());
        LOGE("123123 test 11");
        stream.close();
        LOGE("123123 test 12");
    }
}