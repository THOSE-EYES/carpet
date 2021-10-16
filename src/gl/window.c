/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *  http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

// Include project headers
#include "gl/window.h"

void WindowInit(GLsizei width, GLsizei height, char* title) {
	// Don't do anything if there is a window already
	if (window != -1) return;

	// Change window parameters
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(width, height);

    // Create a main window
    window = glutCreateWindow(title);
    glutDisplayFunc(WindowRedrawCallback);
    glutReshapeFunc(WindowResizeCallback);

	// Reset the background to the default value
	glClearColor(
		default_color.red, 
		default_color.green, 
		default_color.blue, 
		1.0f);
}

void WindowRedrawCallback(void) {
	// Call the given function
	if (drawing_function != NULL)
		drawing_function();
}

void WindowResizeCallback(GLsizei width, GLsizei height) {
	// Recreate a viewport using window's new size
    glViewport(0,0, width,height);

	// Change the matrix to use projection
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();

	// Change the current projection matrix
	glOrtho(-width/2.f, width/2.f, - height/2.f, height/2.f, -1, 1);

	// Get back to the model view mode
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void WindowSetDrawingFunction(FunctionType function) {
	drawing_function = function;
}

void WindowStart() {
	// Don't do anything if there are no windows
	if (window == -1) return;

	// Start the main loop (VERY important!!!)
    glutMainLoop();
}