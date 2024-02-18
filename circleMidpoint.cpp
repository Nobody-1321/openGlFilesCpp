#include<GL/glut.h>

class screenPt{
private: 
    GLint x,y;
public:
    screenPt(){
        x = y = 0;
    }
    void setCootds(GLint xCoordValue, GLint yCoordValue){
        x = xCoordValue;
        y = yCoordValue;
    }

    GLint getx ( ) const{
        return x;
    }

    GLint gety ( ) const {
        return y;
    }

    void incrementx ( ) {
        x++;
    }

    void decrementy ( ) {
    y--;
    }
    
};

void setPixel(GLint xCoord, GLint yCoord){
    glPointSize(5.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
        glVertex2i(xCoord, yCoord);
    glEnd();
}


void circleMidpoint (GLint xc, GLint yc, GLint radius){
    screenPt circPt;
    GLint p = 1 - radius;
    circPt.setCootds (0, radius);

    void circlePlotPoints (GLint, GLint, screenPt);
    circlePlotPoints (xc, yc, circPt);

    while (circPt.getx ( ) < circPt.gety ( )) {
        circPt.incrementx ( );
        if (p < 0)
        p += 2 * circPt.getx ( ) + 1;
    else {
        circPt.decrementy ( );
        p += 2 * (circPt.getx ( ) - circPt.gety ( )) + 1;
    }
        circlePlotPoints (xc, yc, circPt);
    }
}   

void circlePlotPoints (GLint xc, GLint yc, screenPt circPt){
    
    setPixel (xc + circPt.getx ( ), yc + circPt.gety ( ));
    setPixel (xc - circPt.getx ( ), yc + circPt.gety ( ));
    setPixel (xc + circPt.getx ( ), yc - circPt.gety ( ));
    setPixel (xc - circPt.getx ( ), yc - circPt.gety ( ));
    setPixel (xc + circPt.gety ( ), yc + circPt.getx ( ));
    setPixel (xc - circPt.gety ( ), yc + circPt.getx ( ));
    setPixel (xc + circPt.gety ( ), yc - circPt.getx ( ));
    setPixel (xc - circPt.gety ( ), yc - circPt.getx ( )); 

}
 

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    circleMidpoint(500,500,200);
    glutSwapBuffers();
}

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



