#include <opencv/highgui.h>
int main()
{
    ///Ipl是 Intel performance library 的縮寫

    IplImage * img = cvLoadImage("123.png");///讀圖
    cvShowImage("week09",img);///秀圖
    cvWaitKey(0);///等任意鍵繼續
}
