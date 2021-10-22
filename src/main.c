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

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

// Include project headers
#include "utils.h"
#include "gl/window.h"
#include "gl/shapes/carpet.h"

// Window parameters
#define WINDOW_TITLE "Carpet"
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

// Carpet parameters
#define CARPET_STEPS (GLint) 4
#define CARPET_DIVISOR (GLint) 3
#define CARPET_SIDE 150

void Redraw() {
	// Create an are to draw the carpet
	RectangleType carpet;
	carpet.start_x = -CARPET_SIDE;
	carpet.end_x = CARPET_SIDE;
	carpet.start_y = -CARPET_SIDE;
	carpet.end_y = CARPET_SIDE;

	// Clear the buffer
    glClear(GL_COLOR_BUFFER_BIT);

	// Draw the desired carpet
	DrawCarpet(carpet, CARPET_DIVISOR, CARPET_STEPS);

	// Make OpenGL save redraw the window
    glFlush();
}

int main(int argc, char **argv) {
	// Set randomizer seed
	srand(time(NULL));

    // Initialization stuff
    glutInit(&argc, argv);

	// Initialize the window
	WindowInit(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	WindowSetDrawingFunction(Redraw);

	// Start the main loop
	WindowStart();
}