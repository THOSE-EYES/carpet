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

#ifndef GL_WINDOW
#define GL_WINDOW

// Include C headers
#include <stdint.h>

// Include OpenGL headers
#include <GL/gl.h>
#include <GL/glut.h>

// Include project headers
#include "utils.h"

typedef void (*FunctionType)();

static int window = -1;
static ColorRGB default_color;
static FunctionType drawing_function;

/**
 * Initialize GLUT and create a window
 * @param width window's width
 * @param height window's height
 * @param title window's title
 */
void WindowInit(GLsizei width, GLsizei height, char* title);

/**
 * The function is called on window redrawing process
 */
static void WindowRedrawCallback(void);

/**
 * The function is called on window resizing process
 * @param width the width of the window
 * @param height the height of the window
 */
static void WindowResizeCallback(GLsizei width, GLsizei height);

/**
 * Set custom function which is called in the redraw callback function
 * @param function the function to call on window redrawing
 */
void WindowSetDrawingFunction(FunctionType function);

/**
 * Start the main loop of GLUT
 */
void WindowStart();

#endif // GL_WINDOW