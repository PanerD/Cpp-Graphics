## Prerequisites

Before you begin, ensure you have the following installed on your machine:

- [Visual Studio](https://visualstudio.microsoft.com/) (Community edition or higher)
- [CMake](https://cmake.org/download/) (optional, for generating project files)
- [GLFW](https://www.glfw.org/download.html)
- [GL3W](https://github.com/rougier/gl3w)

## Getting Started

Follow these steps to set up the project on your local machine:

1. **Clone the Repository**:
   Download or clone the repository using the following command:
   ```bash
   git clone https://github.com/PanerD/Cpp-Graphics.git
   ```
   Alternatively, you can download the repository as a ZIP file and extract it.

2. **Open the Solution**:
   Navigate to the downloaded or cloned repository folder and open the solution file (`*.sln`) in **Visual Studio**.

3. **Configure Dependencies**:
   Make sure that the GLFW and GL3W libraries are correctly linked in your project settings. You may need to adjust the include directories and library paths in Visual Studio.

4. **Build the Project**:
   In Visual Studio, build the project by clicking on `Build` -> `Build Solution` or pressing `Ctrl + Shift + B`.

5. **Run the Application**:
   After building the project, run the application by clicking on `Debug` -> `Start Debugging` or pressing `F5`.

6. **Control the Window**:
   - Press the **Escape** key to close the application.

## Code Overview

- **KeyCallback**: Handles key input, allowing the user to close the window with the Escape key.
- **ResizeCallback**: Adjusts the viewport when the window is resized.
- **CreateCircle**: Generates vertex data for a circle composed of triangles.
- **OpenGL Rendering Loop**: Renders the circle continuously until the window is closed.

## Important Notes

- Ensure that your graphics drivers are updated to support OpenGL.
- If you encounter any issues with large files or libraries, consider using Git Large File Storage (LFS) for handling large assets.
- You may need to install additional dependencies based on your system configuration.


## Acknowledgments

- [GLFW](https://www.glfw.org/)
- [GL3W](https://github.com/rougier/gl3w)

For any questions or contributions, feel free to open an issue or submit a pull request.
