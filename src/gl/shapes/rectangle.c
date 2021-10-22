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
#include "gl/shapes/rectangle.h"

RectangleType CreateRectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height) {
    RectangleType square;
    square.start_x = x;
	square.end_x = square.start_x + width;
	square.start_y = y;
	square.end_y = square.start_y + height;

    return square;
}

void DrawRectangle(RectangleType square, ColorRGB color) {
    // Set color of drawing
    glColor3f(color.red, color.green, color.blue);

    // Draw the rectangle
    glRectf(square.start_x, square.start_y, square.end_x, square.end_y);
}