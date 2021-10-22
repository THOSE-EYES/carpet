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
#include "gl/shapes/carpet.h"

bool IsSquareSkipped(GLint row, GLint column, GLint divisor) {
	return row == (GLint) round(divisor / 2) && 
					(GLint) column == round(divisor / 2);
}

void DrawCarpet(RectangleType carpet, GLint divisor, GLint steps) {
	// Exit the recursion if there are no steps left
	if (steps == 0) return;

	// Calculate square parameters
	const GLfloat width = carpet.end_x - carpet.start_x;
	const GLfloat height = carpet.end_y - carpet.start_y;
	const GLfloat horizontal_step = width / divisor;
	const GLfloat vertical_step = width / divisor;

	// Iterate over the grid of squares
	for (GLint row = 0; row < divisor; ++row) {
		for (GLint column = 0; column < divisor; ++column) {
			// Get some values to distort the carpet
			const GLfloat x_shift = 
				getRandomFloat(0.0, CARPET_DISTORTION_MAX, CARPET_DISTORTION_PRECISION);
			const GLfloat y_shift = 
				getRandomFloat(0.0, CARPET_DISTORTION_MAX, CARPET_DISTORTION_PRECISION);

			// Calculate the new square vertexes
			RectangleType square = CreateRectangle(
				carpet.start_x + column * horizontal_step + x_shift,
				carpet.start_y + row * vertical_step + y_shift,
				horizontal_step,
				vertical_step);

			// Draw a sub-carpet over the existing square
			if (!IsSquareSkipped(row, column, divisor)) 
				DrawCarpet(square , divisor, steps - 1);

			// Draw actual squares only on the last step
			if (steps == 1) DrawRectangle(square,  GetRandomColorRGB());
		}
	}
}