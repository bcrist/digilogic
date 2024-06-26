/*
   Copyright 2024 Ryan "rj45" Sanche

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef RENDER_H
#define RENDER_H

#include "render/fons_sgp.h"
#include "render/polyline.h"

#include "sokol_gfx.h"
#include "sokol_gp.h"

#include "render/draw.h"

typedef struct FonsFont {
  FONScontext *fsctx;
  int mainFont;
  int iconFont;
} FonsFont;

typedef struct DrawContext {
  PolyLiner *polyliner;
  FONScontext *fontstash;

  HMM_Vec2 pan;
  float zoom;

  sgp_mat2x3 transform;

  int lineVertices;
  int filledRects;
  int strokedRects;
  int texts;
} DrawContext;

void draw_init(DrawContext *draw, FONScontext *fontstash);
void draw_free(DrawContext *draw);
void draw_begin_frame(DrawContext *draw);
void draw_end_frame(DrawContext *draw);

void draw_text(
  DrawContext *draw, Box rect, const char *text, int len, float fontSize,
  FontHandle font, HMM_Vec4 fgColor, HMM_Vec4 bgColor);
void draw_screen_text(
  DrawContext *draw, Box rect, const char *text, int len, float fontSize,
  FontHandle font, HMM_Vec4 fgColor, HMM_Vec4 bgColor);

#endif // RENDER_H