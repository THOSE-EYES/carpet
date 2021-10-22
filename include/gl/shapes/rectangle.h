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

#ifndef GL_SHAPES_SQUARE
#define GL_SHAPES_SQUARE

// Make Windows happy
#ifdef _WIN32
	#include <Windows.h>
#endif

// Include OpenGL headers
#include <GL/gl.h>

// Include project headers
#include "utils.h"

/**
 * This structure holds data about an abstract rectangle with only points
 */
typedef struct {
	GLfloat start_x;
	GLfloat start_y;
	GLfloat end_x;
	GLfloat end_y;
} RectangleType;

/**
 * Create a rectangle out of the given points
 * @param x the X position of the bottom left corner
 * @param y the Y position of the bottom left corner
 * @param width rectangle's width
 * @param height rectangle's heigh
 * @return a filed instance of the RectangleType structure
 */
RectangleType CreateRectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height);

/**
 * Draw the given rectangle
 * @param rectangle the rectangle to draw
 * @param color the color of the rectangle
 */
void DrawRectangle(RectangleType rectangle, ColorRGB color);

#endif // GL_SHAPES_SQUARE