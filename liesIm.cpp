#include<GL/glut.h>
#include<math.h>

void display(){
     glClear(GL_COLOR_BUFFER_BIT);

    const double TWO_PI = 6.2831853;
    GLuint regHex;
    GLdouble theta;
    GLint x, y, k;
    
    /* Set up a display list for a regular hexagon.
    * Vertices for the hexagon are six equally spaced
    * points around the circumference of a circle.
    */
    
    regHex = glGenLists (1); // Get an identifier for the display list.
   
    glNewList (regHex, GL_COMPILE);
    
    glColor3f(1.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
    for (k = 0; k < 6; k++) {
        theta = TWO_PI * k / 6.0;
        x = 200 + 150 * cos (theta);
        y = 200 + 150 * sin (theta);
        glVertex2i (x, y);
    }
    glEnd ( );  
    
    glEndList ( );
   
    glIsList(2);
    glNewList(2,GL_COMPILE);
    
    int pointA[] = {50, 50};
    int pointB[] = {150, 50};
    int pointC[] = {150, 150};
    int pointD[] = {50, 150};

    // Dibuja un rectángulo rojo en la ventana
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2iv(pointA);
    glVertex2iv(pointB);
    glVertex2iv(pointC);
    glVertex2iv(pointD);
    glEnd();
   
    glEndList();
  
    glCallList (1);

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 800);
    glutCreateWindow("uso de glList");
  
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Color de fondo blanco
    
    glMatrixMode(GL_PROJECTION);
    
    gluOrtho2D(0, 800, 0, 800);  // Ajusta según tus necesidades
    
    glutDisplayFunc(display);
    
    glutMainLoop();

    return 0;
}
