#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>

void linesBrem(int x0, int y0, int xEnd, int yEnd);
void display();
void setPixel(int x, int y);


int main(int argc, char** argv){


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1080, 720);
    glutCreateWindow(" bresenham");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1080, 0, 720);
    glClearColor(1.0, 1.0,1.0, 1.0);
    glutDisplayFunc(display);

     glutMainLoop();

    return 0;
}

void setPixel (int x, int y){
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,0.0);
    glVertex2i(x, y);
    glEnd();
}

void linesBrem(int x0, int y0, int xEnd, int yEnd){
    int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy- dx);
    int x, y;

    if (x0 > xEnd){
        x = xEnd;
        y = yEnd;
        xEnd = x0;
    }else{
        x = x0;
        y = y0;
    }

    setPixel(x, y);

    while (x<xEnd){
        x++;
        if(p < 0){
            p += twoDy;
        }else{
            y++;
            p += twoDyMinusDx;
        }
        setPixel(x, y);

    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    linesBrem(1000, 1000, 390, 30);
    glutSwapBuffers();
}

