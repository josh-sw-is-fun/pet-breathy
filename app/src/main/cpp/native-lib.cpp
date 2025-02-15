#include <jni.h>
#include <string>

#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_petbreathy_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    cv::Mat output = cv::Mat::zeros(120, 350, CV_8UC3);
    (void) output;

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_petbreathy_MainActivity__salt(JNIEnv *env, jobject instance,
                                                                           jlong matAddrGray,
                                                                           jint nbrElem) {
    cv::Mat &mGr = *(cv::Mat *) matAddrGray;
    for (int k = 0; k < nbrElem; k++) {
        int i = rand() % mGr.cols;
        int j = rand() % mGr.rows;
        mGr.at<uchar>(j, i) = 255;
    }
}
