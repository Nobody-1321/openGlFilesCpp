#include <GL/glut.h>

float angle = 0.0f; // Ángulo de rotación del cubo

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Borra el búfer de color y el búfer de profundidad

    glLoadIdentity(); // Reinicia la matriz de transformación

    glTranslatef(0.0f, 0.0f, -5.0f); // Traslada la escena hacia el observador

    glRotatef(angle, 0.0f, 1.0f, 0.0f); // Rota el cubo sobre su eje vertical

    // Dibuja un cubo
    glBegin(GL_QUADS);
    // Cara frontal
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    // Cara posterior
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    // Cara superior
    glColor3f(0.0f, 0.0f, 1.0f); // Azul
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    // Cara inferior
    glColor3f(1.0f, 1.0f, 0.0f); // Amarillo
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    // Cara derecha
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    // Cara izquierda
    glColor3f(0.0f, 1.0f, 1.0f); // Cian
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();

    glutSwapBuffers(); // Intercambia los buffers de pantalla
}

void update(int value) {
    angle += 2.0f; // Incrementa el ángulo de rotación
    if (angle > 360) {
        angle -= 360; // Restablece el ángulo cuando supera los 360 grados
    }

    glutPostRedisplay(); // Solicita un redibujado de la escena
    glutTimerFunc(16, update, 0); // Llama a la función update cada 16 milisegundos (aproximadamente 60 FPS)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inicializa GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Habilita el modo de doble buffer, color RGB y búfer de profundidad
    glutInitWindowSize(500, 500); // Establece el tamaño de la ventana
    glutCreateWindow("Espera 3D"); // Crea la ventana con el título "Espera 3D"
    glEnable(GL_DEPTH_TEST); // Habilita el z-buffer para la renderización en 3D
    glutDisplayFunc(display); // Registra la función de visualización
    glutTimerFunc(16, update, 0); // Inicia el temporizador para la animación
    glutMainLoop(); // Inicia el bucle principal de GLUT
    return 0;
}
