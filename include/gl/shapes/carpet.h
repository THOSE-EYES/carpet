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

#ifndef GL_SHAPES_CARPET
#define GL_SHAPES_CARPET

// Include C headers
#include <stdbool.h>

// Include OpenGL headers
#include <GL/gl.h>

// Include project headers
#include "utils.h"
#include "gl/window.h"
#include "gl/shapes/rectangle.h"

// Constants essential for the carpet drawing
#define CARPET_DISTORTION_MAX 2.0
#define CARPET_DISTORTION_PRECISION 2

/**
 * This struct defines a carpet of different squares
 */
typedef struct{
	Rectangle* squares;
	GLint size;
} Carpet;

/**
 * Draw the carpet on the given rectangle
 */
void DrawCarpet(Rectangle carpet, GLint divisor, GLint steps);

/**
 * Check if the square should be skipped
 * @param row the row of the square
 * @param column the row of the square
 * @param divisor the devisor defined to cut the parent square
 * @return true if the square should be skipped
 */
bool IsSquareSkipped(GLint row, GLint column, GLint divisor);

#endif // GL_SHAPES_CARPET
