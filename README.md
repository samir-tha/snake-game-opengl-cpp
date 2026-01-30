# 🐍 Snake Game using C++ and OpenGL

A classic **2D Snake Game** implemented using **C++ and OpenGL (GLUT)** as part of the **CSC214 – Computer Graphics** course for **BSc CSIT (3rd Semester)**.

This project demonstrates fundamental **computer graphics concepts** such as raster graphics, 2D transformations, orthographic projection, and interactive graphics using keyboard input.

---

## 📌 Features

- 2D snake movement using keyboard (arrow keys)
- Food generation at random positions
- Snake growth on eating food
- Score display on screen
- Collision detection (wall & self)
- Game over screen
- Smooth animation using timer function

---

## 🛠 Technologies Used

- **Language:** C++
- **Graphics Library:** OpenGL (GLUT / FreeGLUT)
- **IDE:** DEV-C++
- **Graphics Type:** 2D Raster Graphics
- **Platform:** Windows

---

## 🧠 Computer Graphics Concepts Used

- Raster graphics
- OpenGL primitives (`GL_QUADS`)
- Orthographic projection (`gluOrtho2D`)
- Window and viewport transformation
- Timer-based animation
- Keyboard interaction
- Bitmap text rendering

---

## ▶️ How to Run the Project (DEV-C++)

### Prerequisites
- DEV-C++ (TDM-GCC)
- FreeGLUT installed

---

### Step 1: Get the Project

#### Option A: Download ZIP
1. Open the repository:  
   https://github.com/samir-tha/snake-game-opengl-cpp
2. Click **Code**
3. Select **Download ZIP**
4. Extract the folder

#### Option B: Clone Using Git
```bash
cd <working-directory>
git clone https://github.com/samir-tha/snake-game-opengl-cpp
cd snake-game-opengl-cpp

---

### Step 2: Open in DEV-C++

1. Open **DEV-C++**
2. Create a **Console Application (C++)**
3. Delete the default code
4. Copy and paste the `main.cpp` file from this project
5. Save the file

---

### Step 3: Add OpenGL Linker Libraries

In DEV-C++:

1. Go to  
   **Tools → Compiler Options**
2. Select  
   **Parameters → Linker**
3. Add the following line:
-lopengl32 -lglu32 -lglut32

---

## 🎮 Controls

| Key | Action |
|----|-------|
| ↑ | Move Up |
| ↓ | Move Down |
| ← | Move Left |
| → | Move Right |

---

## 📄 License

This project is for **educational purposes only**.