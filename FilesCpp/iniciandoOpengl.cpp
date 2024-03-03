/*
    Primeros pasos con opengl y la libreira GLUT 
    compilacion g++ reShape.cpp -o inicioX -lGL -lGLU -lglut  

*/
#include<GL/glut.h>

void display(){

    glClear(GL_COLOR_BUFFER_BIT); // Borra el búfer de color de la ventana actual, utilizando el color de borrado previamente especificado
   
    glPointSize(20.00);           // Establece el tamanio del punto
    
    glBegin(GL_POINTS);            // Inicia la definición de un conjunto de primitivas de puntos en OpenGL. 
                                  // Los puntos se renderizarán según las coordenadas especificadas con glVertex*() entre glBegin() y glEnd().
   
    glColor3f(1.0, 0.0, 0.0);     // Establece el color actual de OpenGL en rojo (R=1.0, G=0.0, B=0.0)
    glVertex2i(200, 200);  // Establece la posición del vertice para la siguiente operación de rasterización.
                                   // En este caso, se establece la posición a (200.00, 200.00) en coordenadas de ventana.
    glEnd();                       // Finaliza la definición del conjunto de primitivas de puntos.
   
    glutSwapBuffers();             // Intercambia los buffers de pantalla. Útil cuando se utiliza el modo de renderizado de doble buffer (GLUT_DOUBLE), 
                                   // donde se renderiza en un buffer oculto y se intercambia con el buffer visible para evitar parpadeos.
}


int main(int argc, char** argv) {

    glutInit(&argc, argv);                       // Inicializa GLUT con los argumentos de línea de comandos proporcionados
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Configura el modo de visualización para la ventana (doble buffer y modo de color RGB)
    glutInitWindowSize(400, 400);                // Establece el tamaño inicial de la ventana a 400x400 píxeles
    glutCreateWindow("OpenGL Texto con GLUT");   // Crea una ventana con el título "OpenGL Texto con GLUT"
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 400, 0, 400);                  // Establece una proyección ortográfica 2D con coordenadas que van de 0 a 400 en ambos ejes (x, y)
    glClearColor(1.0, 1.0, 1.0, 1.0);            // Establece el color de borrado de la ventana como blanco
    glutDisplayFunc(display);                    // Establece la función de visualización que se llamará cuando se necesite redibujar la ventana

    glutMainLoop();                              // Inicia el bucle principal de GLUT, donde la aplicación espera eventos de entrada de usuario y 
                                                 // solicitudes de redibujado. La aplicación permanece activa y responde a eventos hasta que se cierra 
                                                 // la ventana creada por GLUT. Una vez que se cierra la ventana, el control se devuelve al programa
                                                 // principal y el flujo de ejecución continúa más allá de la llamada a glutMainLoop(). Esencialmente, 
                                                 // esta función mantiene viva la aplicación hasta que el usuario decida cerrarla.

    return 0;
}
