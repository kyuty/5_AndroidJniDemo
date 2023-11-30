package com.wd.jnidemo;

import android.os.Handler;
import android.os.HandlerThread;

public class JniEnter {

    private static final Handler mWorker;

    static {
        System.out.println("123123 load");
        System.loadLibrary("jnidemo");
        System.out.println("123123 load 1");
        HandlerThread mWorkerThread = new HandlerThread("WorkerHandlerThread");
        mWorkerThread.start();
        System.out.println("123123 load 2");
        mWorker = new Handler(mWorkerThread.getLooper());
        System.out.println("123123 load 3");
        System.out.println("123123 load end");
    }

    public static void init() {
        mWorker.post(JniEnter::initJNI2);
    }

    private static native void initJNI2();
}
