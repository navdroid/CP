#include <jni.h>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


extern "C"
{
    void JNICALL Java_com_droid_nav_cp_MainActivity_salt(JNIEnv *env, jobject instance, jlong matAddrGray, jint nbrElem) {

        Mat &mGr = *(Mat *) matAddrGray;
        for (int k = 0; k < nbrElem; k++) {
            int i = rand() % mGr.cols;
            int j = rand() % mGr.rows;
            mGr.at<uchar>(j, i) = 255;
        }
    }

    void JNICALL Java_com_droid_nav_cp_MainActivity_chr(JNIEnv *env, jobject instance, jlong matAddrGray) {

        Mat &img = *(Mat *) matAddrGray;
        Ptr<MSER> ms = MSER::create();
        vector<vector<Point> > regions;
        vector<cv::Rect> mser_bbox;
        ms->detectRegions(img, regions, mser_bbox);

        for (int i = 0; i < regions.size(); i++)
        {
            rectangle(img, mser_bbox[i], CV_RGB(0, 255, 0));
        }

    }

    void JNICALL Java_com_droid_nav_cp_MainActivity_hr(JNIEnv *env, jobject instance, jlong matAddrGray) {




    }
}