#include <cmath>
#include <GL/glut.h>
#include <iostream>
#include <thread>

void linesBrem(int x0, int y0, int xEnd, int yEnd);
void display();
void setPixel(int x, int y);

int main(int argc, char** argv) {
    auto start = std::chrono::high_resolution_clock::now();
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080, 720);
    glutCreateWindow("Line Width");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1080, 0, 720);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display);
    
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Tiempo transcurrido: " << duration.count() << " milisegundos" << std::endl;
    glutMainLoop();

    return 0;
}

void setPixel(int x, int y) {
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(x, y);
    glEnd();
}

void linesBrem(int x0, int y0, int xEnd, int yEnd) {
    int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
    int x, y;

    if (x0 > xEnd) {
        x = xEnd;
        y = yEnd;
        xEnd = x0;
    } else {
        x = x0;
        y = y0;
    }

    setPixel(x, y);

    while (x < xEnd) {
        x++;
        if (p < 0) {
            p += twoDy;
        } else {
            y++;
            p += twoDyMinusDx;
        }
        setPixel(x, y);
    }
}

void tareaLineas() {
   // std::thread hilo{linesBrem, 30, 30, 1080, 720};
//    std::thread hilo1{linesBrem, 30, 50, 1080, 750};
   linesBrem(30, 30, 1000, 700);
//    hilo1.join();
  // hilo.join();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    linesBrem(30, 30, 1000, 700);
    glFlush();
}

