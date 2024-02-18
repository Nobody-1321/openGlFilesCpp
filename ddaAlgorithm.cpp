#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
inline int rounds (const float a) { return int (a + 0.1); } //sugerencia para introducir la funcion en la linea 
void lineDda(int x0, int y0, int xEnd, int yEnd);
void setPixel (float x, float y);
void display();

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1080, 720);
    glutCreateWindow(" DDA ");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1080, 0, 720);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display);
    
    glutMainLoop();

    return 0;

}

void lineDda(int x0, int y0, int xEnd, int yEnd){
    int dx = xEnd -x0, dy = yEnd -y0, steps, k; //dx.dy son las diferencias, con estas se puede calcular la pendiente
    float xIncrement, yIncrement, x = x0, y = y0;

    if (fabs(dx) > fabs(dy)){ //esta es una optimizacion, no se calcula la pendiente solo las diferencias 
        steps = fabs(dx);      // apartir de estas diferencias se puede saber si la pendiente es positiva o negativa 0
    }else{
        steps = fabs(dx);
    }

    xIncrement = (float)dx / (float)steps;
    yIncrement = (float)dy / (float)steps;

    setPixel (rounds(x), rounds(y));
    printf("dx(%d) dy(%d) xInc(%f) yInc(%f) x(%f) y(%f)\n",dx,dy,xIncrement,yIncrement,x,y); 

    for (k = 0; k < steps; k++){
        x += xIncrement;
        y += yIncrement;
        setPixel(rounds(x), rounds(y));
    }
    //good acabo de descubrir que += no significa que siempre se esta sumando o iterando positivamente, 
    //c=20 y=-1 c+=y la c va a ser 19 
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    lineDda(700, 700,390,30);
    glutSwapBuffers();
}

void setPixel (float x, float y){
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,0.0);
    glVertex2i(x, y);
    glEnd();
}