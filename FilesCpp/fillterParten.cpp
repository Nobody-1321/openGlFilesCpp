/*
El fragmento de código que proporcionaste muestra el uso de 
glPolygonStipple y glEnable(GL_POLYGON_STIPPLE) 
en OpenGL. Estas funciones se utilizan para dibujar 
polígonos con un patrón de relleno personalizado.
*/

#include <GL/glut.h>

//g++ tu_programa.cpp -o tu_programa -lGL -lGLU -lglut
/*GLubyte fillPattern1[] = {
    0x55, 0xaa, 0x55, 0xaa,
    0x55, 0xaa, 0x55, 0xaa,
    0x55, 0xaa, 0x55, 0xaa,
    0x55, 0xaa, 0x55, 0xaa
};

//se pueden generar diferentes patrones de dibujado 
*/

GLubyte fillPattern2[] = {
    0xAA, 0x55, 0xAA, 0x55,
    0xAA, 0x55, 0xAA, 0x55,
    0xAA, 0x55, 0xAA, 0x55,
    0xAA, 0x55, 0xAA, 0x55,
    0xAA, 0x55, 0xAA, 0x55,
    0xAA, 0x55, 0xAA, 0x55,
    0xAA, 0x55, 0xAA, 0x55,
    0xAA, 0x55, 0xAA, 0x55
};


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Configuramos el nuevo patrón de relleno
    glPolygonStipple(fillPattern2);
    glEnable(GL_POLYGON_STIPPLE);
   
    int pointA[] = {50, 50};
    int pointB[] = {350, 50};
    int pointC[] = {350, 350};
    int pointD[] = {50, 350};

    // Dibuja un polígono azul más grande en la ventana
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2iv(pointA);
    glVertex2iv(pointB);
    glVertex2iv(pointC);
    glVertex2iv(pointD);
    glEnd();

    glDisable(GL_POLYGON_STIPPLE);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Polygon Stipple Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 400, 0, 400);

    glutDisplayFunc(display);

    glutMainLoop();
}


