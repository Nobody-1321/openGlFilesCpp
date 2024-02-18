#include <GL/glut.h>
#include <iostream>

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Query Example");

    // Variable para almacenar el resultado de la consulta
    GLint redBitSize;

    // Consulta del número de bits para el componente rojo
    glGetIntegerv(GL_RED_BITS, &redBitSize);

    // Imprime la información obtenida
    std::cout << "Número de bits para el componente rojo por píxel: " << redBitSize << std::endl;

    // Otras consultas posibles
    GLint greenBitSize, blueBitSize, alphaBitSize;
    glGetIntegerv(GL_GREEN_BITS, &greenBitSize);
    glGetIntegerv(GL_BLUE_BITS, &blueBitSize);
    glGetIntegerv(GL_ALPHA_BITS, &alphaBitSize);

    // Imprime información adicional
    std::cout << "Número de bits para el componente verde por píxel: " << greenBitSize << std::endl;
    std::cout << "Número de bits para el componente azul por píxel: " << blueBitSize << std::endl;
    std::cout << "Número de bits para el componente alfa por píxel: " << alphaBitSize << std::endl;

    return 0;
}
