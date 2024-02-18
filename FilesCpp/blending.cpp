#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Renderiza objetos semi-transparentes
    glColor4f(1.0, 0.0, 0.0, 0.2);  // Rojo semi-transparente
    glBegin(GL_POLYGON);
    glVertex2f(100, 100);
    glVertex2f(300, 100);
    glVertex2f(200, 300);
    glEnd();

    // Desactiva el mezclado después de usarlo
    glDisable(GL_BLEND);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Blending Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Color de fondo blanco
    gluOrtho2D(0, 400, 0, 400);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
