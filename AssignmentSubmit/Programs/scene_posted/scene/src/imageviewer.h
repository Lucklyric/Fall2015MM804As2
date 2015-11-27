
// Herb Yang
// Updated: Oct. 2, 2010
// Updated: June 30, 2015

#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <gl/glut.h>
#include <malloc.h>
#include <string>
#include<math.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <FreeImage.h>
using namespace std;

#include "mathtypes.h"
#include "color.h"
#include "parser.h"
#include "scene.h"
#include "camera.h"
#define GAMMA 1.0
extern GLubyte *image;
class ImageViewer
{   
public:
        ImageViewer();
		void render();
		void open();
		void save();
        void generateImage(Scene *scene, Camera *camera);
        void img_init(screen_res_t width, screen_res_t height);
        void img_clear(screen_res_t width, screen_res_t height);
        void clearRawImage();
        void normalizeRawImage();
        void gammaCorrection(double gamma);
        void copyRawImageToImage();
        void setPixel(int x,int y, Color c);
		void setSample();
        Scene sceneData;
        Camera theCamera;
        GLubyte *image;
        Color *rawImage;
        int i, j;
		char  fileName[100];
		ifstream infile;
		int NSAMPLES;
};

#endif
 // IMAGEVIEWER_H
