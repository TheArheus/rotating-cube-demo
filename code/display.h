#if !defined(DISPLAY_H_)

#include <SDL2\SDL.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;

typedef int8_t      i8;
typedef int16_t     i16;
typedef int32_t     i32;
typedef uint64_t    i64;

typedef float       r32;
typedef double      r64;

#define FPS 30
#define FRAME_TARGET_TIME (1000/FPS)

extern SDL_Window*      window;
extern SDL_Renderer*    renderer;
extern SDL_Texture*     texture;
extern u32*             color_buffer;
extern u32              window_width;
extern u32              window_height;

#include "hmath.h"

bool InitWindow();
void RenderColorBuffer();
void ClearColorBuffer(u32);
void DrawPixel(u32, u32, u32);
void DrawGrid(u32);
void DrawRect(v2, u32, u32, u32 );
void DestroyWindow();

#define DISPLAY_H_
#endif
