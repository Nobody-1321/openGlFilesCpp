#include <GL/freeglut.h>

float pointPositionX = 0.0f; // Posición inicial del punto en el eje X
float pointPositionY = 0.0f; // Posición inicial del punto en el eje Y
float pointPositionZ = 0.0f; // Posición inicial del punto en el eje Z

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Aplicar transformación de traslación para mover el punto a la posición deseada
    glTranslatef(pointPositionX, pointPositionY, pointPositionZ);

    // Establecer el tamaño del punto
    glPointSize(20.0f); // Tamaño del punto en píxeles

    // Dibujar el punto en la posición actual
    glBegin(GL_POINTS);
    glVertex3f(0.0f, 0.0f, 0.0f); // Punto en el origen del sistema de coordenadas
    glEnd();

    glutSwapBuffers();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Color de fondo negro
    glEnable(GL_DEPTH_TEST); // Habilitar el test de profundidad
}

void keyboard(unsigned char key, int x, int y) {
    // Manejar eventos de teclado para mover el punto
    switch (key) {
        case 'w': // Mover hacia adelante en el eje Z
            pointPositionZ += 0.1f;
            break;
        case 's': // Mover hacia atrás en el eje Z
            pointPositionZ -= 0.1f;
            break;
        case 'a': // Mover hacia la izquierda en el eje X
            pointPositionX -= 0.1f;
            break;
        case 'd': // Mover hacia la derecha en el eje X
            pointPositionX += 0.1f;
            break;
    }

    glutPostRedisplay(); // Volver a dibujar la escena
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Punto en 3D");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Registrar la función de manejo de teclado

    glutMainLoop();

    return 0;
}
