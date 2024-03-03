/*
    la funcion reshape se encarga de redimencionar la ventana para que los elementos dentro 
    se mantengan estables 

*/

#include <GL/glut.h>


void reshape(int width, int height) {
    glViewport(0, 0, width, height);  // Establece la ventana de visualización para que coincida con el tamaño de la ventana
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);  // Configura la proyección ortográfica 2D
    glMatrixMode(GL_MODELVIEW);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  
    
    int pointA[] = {50, 50};
    int pointB[] = {150, 50};
    int pointC[] = {150, 150};
    int pointD[] = {50, 150};

    // Dibuja un rectángulo rojo en la ventana
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2iv(pointA);
    glVertex2iv(pointB);
    glVertex2iv(pointC);
    glVertex2iv(pointD);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Reshape Example");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 400, 0, 400); 
    glutReshapeFunc(reshape);  // Asigna la función de retorno de llamada para la redimensión
    glutDisplayFunc(display);
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Color de fondo blanco

    glutMainLoop();
    return 0;
}
