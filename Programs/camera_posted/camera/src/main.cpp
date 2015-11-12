//  A simple raytracer
//        by
//  Herb Yang
//  March 9, 2010
// June 30, 2015
#include "imageviewer.h"
#include "geomObj.h"
geomObj* geomObj::list =0;
ImageViewer *im =new ImageViewer();
GLuint texName;
//  OpenGL window handling routines
//  initialize some opengl parameters
void initGL(int w, int h) 
{
	glViewport(0, 0, w, h);			// use a screen size of WIDTH x HEIGHT
	glEnable(GL_TEXTURE_2D);		// Enable 2D texturing
	glMatrixMode(GL_PROJECTION);    // Make a simple 2D projection on the entire window
	glLoadIdentity();
	glOrtho(0.0, w, h, 0.0, 0.0, 100.0);
	glMatrixMode(GL_MODELVIEW);		// Set the matrix mode to object modeling
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	glClearDepth(0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the window
}
//  display function
void display(void) 
{   
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);     // Operate on model-view matrix
	glBindTexture(GL_TEXTURE_2D, texName);
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	glGenTextures(1,&texName);
	glBindTexture(GL_TEXTURE_2D,texName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D,0, GL_RGB  ,im->theCamera.Nx,im->theCamera.Ny, 0,  GL_RGB ,GL_UNSIGNED_BYTE, (void*)im->image);
	/* Draw a quad */
	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2i(0,   im->theCamera.Ny);
	glTexCoord2i(0, 1); glVertex2i(0,   0);
	glTexCoord2i(1, 1); glVertex2i(im->theCamera.Nx, 0);
	glTexCoord2i(1, 0); glVertex2i(im->theCamera.Nx,im->theCamera.Ny);
	glEnd();
	glDeleteTextures(1, &texName);
	glutSwapBuffers();
	glFlush();
}
// reshape function
void reshape(GLsizei newwidth, GLsizei newheight) 
{  

	glutReshapeWindow(im->theCamera.Nx,im->theCamera.Ny); // do not let the window change size
}
// mouse handler
void mouse(int button, int state, int x, int y)
{
	if(button==GLUT_LEFT_BUTTON && state ==GLUT_DOWN)
	{
		// do something with the mouse
		glutPostRedisplay();
	}
}
// keyboard handler
void keyPressed (unsigned char key, int x, int y) { 
	switch(key){
	case 'r':
		im->render();
		break;
	case 'o': // open another scene file
		im->open();
		im->setSample();
		im->render();
		break;
	case 's': // save the rendered image as a bmp file
		im->save();
		break;
	
	}
	glutReshapeWindow(im->theCamera.Nx,im->theCamera.Ny);
	initGL(im->theCamera.Nx,im->theCamera.Ny);
	glutPostRedisplay();
}
void main(int argc, char *argv[])
{   
	im->open();
	im->setSample();
	im->render();
	glutInit(&argc, argv);            
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH); 
	im->copyRawImageToImage();
	glutInitWindowSize(im->theCamera.Nx,im->theCamera.Ny);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Raytracing");
	initGL(im->theCamera.Nx,im->theCamera.Ny);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape); 
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyPressed); 
	glutMainLoop(); 
	return ;
}
