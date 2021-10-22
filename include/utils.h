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

#ifndef UTILS
#define UTILS

// Make Windows happy
#ifdef _WIN32
	#include <Windows.h>
#endif

// Include OpenGL headers
#include <GL/gl.h>

// Include C headers
#include <time.h>
#include <stdlib.h>
#include <math.h>

/**
 * This structure holds color representation in RGB
 */
typedef struct {
	GLfloat red;
	GLfloat green;
	GLfloat blue;
	GLfloat alpha;	// Unused for now
} ColorRGB;

/**
 * This function creates a random RGB color and returns it to the caller.
 * @return a random RGB color
 */
ColorRGB GetRandomColorRGB();

/**
 * Get random float in the given range and with the given precision
 * @param min the lower threshold of the new float value
 * @param max the upper threshold of the new float value
 * @param precision amount of integers after the dot to contain
 * @return a random float value
 */
GLfloat getRandomFloat(GLfloat min, GLfloat max, GLint precision);

#endif // UTILS