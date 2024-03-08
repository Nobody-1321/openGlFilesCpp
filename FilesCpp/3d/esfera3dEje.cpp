#include <GL/glut.h>
#include <cmath>
#include <GL/gl.h>

int lastX = 0;
int lastY = 0;
bool mouseDown = false;

float cameraAngleX = 0.0f;
float cameraAngleY = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glTranslatef(0.0f, 0.0f, -5.0f); // Trasladamos la escena hacia atrás
    
    glRotatef(cameraAngleX, 1.0f, 0.0f, 0.0f); // Rotamos la escena según el ángulo X
    glRotatef(cameraAngleY, 0.0f, 1.0f, 0.0f); // Rotamos la escena según el ángulo Y
    
    // Dibujamos los ejes de coordenadas
    glLineWidth(2.0f); // Establecemos el ancho de la línea
    glBegin(GL_LINES);
    // Eje X (rojo)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(3.0f, 0.0f, 0.0f);
    // Eje Y (verde)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 3.0f, 0.0f);
    // Eje Z (azul)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 3.0f);
    glEnd();
    
    glColor3f(1.0f, 0.0f, 0.0f); // Establecemos el color a rojo
    glutWireSphere(1.0, 30, 30); // Dibujamos una esfera con malla de vértices
    
    glutSwapBuffers();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Establecemos el color de fondo a negro
    glEnable(GL_DEPTH_TEST); // Habilitamos el z-buffer para renderizar en 3D
    
    glMatrixMode(GL_PROJECTION); // Seleccionamos la matriz de proyección
    glLoadIdentity(); // Reiniciamos la matriz
    
    // Configuramos una proyección perspectiva
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f); // Ángulo de visión, aspect ratio, zNear, zFar
    
    glMatrixMode(GL_MODELVIEW); // Volvemos a la matriz de modelo-vista
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        lastX = x;
        lastY = y;
    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        mouseDown = false;
    }
}

void motion(int x, int y) {
    if (mouseDown) {
        cameraAngleY += (x - lastX) * 0.5f;
        cameraAngleX += (y - lastY) * 0.5f;
        lastX = x;
        lastY = y;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Esfera 3D");
    
    init();
    
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    
    glutMainLoop();
    
    return 0;
}
