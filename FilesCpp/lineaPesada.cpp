#include<math.h>
#include<vector>
#include<GL/glut.h>
#include<chrono>
#include<iostream>
#include<thread>

struct Point_Vector{
    int x;
    int y;
    Point_Vector(int x, int y): x{x}, y{y} {}
};

std::vector<Point_Vector> linesBrem(int x0, int y0, int xEnd, int yEnd);
void display();
void setPixel(int x, int y);



int main(int argc, char** argv){
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


void setPixel (int x, int y){
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,0.0);
    glVertex2i(x, y);
    glEnd();
}

std::vector<Point_Vector> linesBrem(int x0, int y0, int xEnd, int yEnd){
    int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy- dx);
    int x, y;
    std::vector<Point_Vector> poins;

    if (x0 > xEnd){
        x = xEnd;
        y = yEnd;
        xEnd = x0;
    }else{
        x = x0;
        y = y0;
    }

    poins.push_back(Point_Vector(x,y));
    
    //setPixel(x, y);

    while (x<xEnd){
        x++;
        if(p < 0){
            p += twoDy;
        }else{
            y++;
            p += twoDyMinusDx;
        }
        //setPixel(x, y);
        poins.push_back(Point_Vector(x,y));

    }

    return std::move(poins);
}

void puntoMedio(int &x, int &y, int xend, int xstar, int yend, int ystar){
    double x1 = (xstar + xend) / 2;
    double y1 = (ystar + yend) / 2; 
    x = static_cast<int>(x1);
    y = static_cast<int>(y1);
}


int puntomedioX;
int puntomedioY;

void tareaLineas(){

    puntoMedio(puntomedioX, puntomedioY, 30, 30, 1000, 700);
    std::cout << " punto x " <<puntomedioX << " punto y " << puntomedioY << "\n";
    
    std::thread hilo{linesBrem, 30, 30, puntomedioX, puntomedioY};
    std::thread hilo1{linesBrem, puntomedioX+1, puntomedioY+1, 1000, 1000};  

    hilo1.join();
    hilo.join();
    
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT); 
    std::vector<Point_Vector> vectorPoints = linesBrem(30, 30, 1000, 700);

 // Establecer el color de los puntos
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo

    // Dibujar cada punto en el vector
    glPointSize(5.0);
    glBegin(GL_POINTS);
    for (const auto& point : vectorPoints) {
        glVertex2f(point.x, point.y);
    }
    glEnd();

    glFlush();
}


    //setPixel(puntomedioX, puntomedioY);
 
  //  linesBrem(30, 30, 1000, 700);


  