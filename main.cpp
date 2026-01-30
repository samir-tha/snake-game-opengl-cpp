#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/* -------------------- GLOBAL CONSTANTS -------------------- */
const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
const int BLOCK_SIZE = 20;

/* -------------------- DATA STRUCTURES -------------------- */
struct Point {
    int x, y;
};

/* -------------------- GLOBAL VARIABLES -------------------- */
vector<Point> snake;
Point food;

int direction = 1;   // 0 = UP, 1 = RIGHT, 2 = DOWN, 3 = LEFT
bool gameOver = false;
int score = 0;

/* -------------------- FUNCTION DECLARATIONS -------------------- */
void init();
void display();
void timer(int);
void keyboard(int, int, int);
void drawBlock(int, int);
void placeFood();
bool checkCollision(Point);

/* -------------------- INITIALIZATION -------------------- */
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);

    snake.clear();
    snake.push_back({100, 100});

    srand(time(0));
    placeFood();
}

/* -------------------- DRAW SINGLE BLOCK -------------------- */
void drawBlock(int x, int y) {
    glBegin(GL_QUADS);
        glVertex2i(x, y);
        glVertex2i(x + BLOCK_SIZE, y);
        glVertex2i(x + BLOCK_SIZE, y + BLOCK_SIZE);
        glVertex2i(x, y + BLOCK_SIZE);
    glEnd();
}

/* -------------------- FOOD GENERATION -------------------- */
void placeFood() {
    food.x = (rand() % (WINDOW_WIDTH / BLOCK_SIZE)) * BLOCK_SIZE;
    food.y = (rand() % (WINDOW_HEIGHT / BLOCK_SIZE)) * BLOCK_SIZE;
}

/* -------------------- COLLISION CHECK -------------------- */
bool checkCollision(Point head) {
    // Wall collision
    if (head.x < 0 || head.x >= WINDOW_WIDTH ||
        head.y < 0 || head.y >= WINDOW_HEIGHT)
        return true;

    // Self collision
    for (size_t i = 1; i < snake.size(); i++) {
        if (head.x == snake[i].x && head.y == snake[i].y)
            return true;
    }

    return false;
}
void drawText(int x, int y, const char* text) {
    glRasterPos2i(x, y);
    for (int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}
/* -------------------- DISPLAY FUNCTION -------------------- */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (gameOver) {
        glColor3f(1.0, 0.0, 0.0);
        drawText(200, 260, "GAME OVER");

        char scoreText[30];
        sprintf(scoreText, "Final Score : %d", score);
        drawText(170, 230, scoreText);

        glFlush();
        return;
    }

    // Draw Score
    glColor3f(1.0, 1.0, 1.0);
    char scoreText[20];
    sprintf(scoreText, "Score : %d", score);
    drawText(10, 480, scoreText);

    // Draw Snake
    glColor3f(0.0, 1.0, 0.0);
    for (int i = 0; i < snake.size(); i++)
        drawBlock(snake[i].x, snake[i].y);

    // Draw Food
    glColor3f(1.0, 0.0, 0.0);
    drawBlock(food.x, food.y);

    glFlush();
}

/* -------------------- GAME LOOP -------------------- */
void timer(int) {
    if (gameOver) return;

    Point head = snake[0];

    if (direction == 0) head.y += BLOCK_SIZE;
    if (direction == 1) head.x += BLOCK_SIZE;
    if (direction == 2) head.y -= BLOCK_SIZE;
    if (direction == 3) head.x -= BLOCK_SIZE;

    if (checkCollision(head)) {
        gameOver = true;
        cout << "Game Over! Score: " << score << endl;
        glutPostRedisplay();
        return;
    }

    snake.insert(snake.begin(), head);

    if (head.x == food.x && head.y == food.y) {
        score += 10;
        placeFood();
    } else {
        snake.pop_back();
    }

    glutPostRedisplay();
    glutTimerFunc(150, timer, 0);
}

/* -------------------- KEYBOARD INPUT -------------------- */
void keyboard(int key, int, int) {
    if (key == GLUT_KEY_UP && direction != 2) direction = 0;
    if (key == GLUT_KEY_RIGHT && direction != 3) direction = 1;
    if (key == GLUT_KEY_DOWN && direction != 0) direction = 2;
    if (key == GLUT_KEY_LEFT && direction != 1) direction = 3;
}

/* -------------------- MAIN FUNCTION -------------------- */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Snake Game - OpenGL ");

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutTimerFunc(150, timer, 0);

    glutMainLoop();
    return 0;
}
