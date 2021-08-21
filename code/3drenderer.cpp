#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "display.h"

bool is_running;

const int N_POINTS = (9*9*9);
v3 cube_points[N_POINTS];
v2 projected_points[N_POINTS];
v3 CameraPos = {0.0f, 0.0f, -5.0f};
v3 CubeRotation = {0.0f, 0.0f, 0.0f};

i32 PreviousFrameTime = 0;

r32 CubeRot = 0;

u32 CubeFOV = 700;

static void 
setup(void)
{
    color_buffer = (u32*)malloc(sizeof(u32)*window_width*window_height);

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, 
                                SDL_TEXTUREACCESS_STREAMING, 
                                window_width, window_height);

    int point_count = 0;
    for(r32 Z = -1; Z <= 1; Z+=0.25)
    {
        for(r32 Y = -1; Y <= 1; Y+=0.25)
        {
            for(r32 X = -1; X <= 1; X+=0.25)
            {
                v3 new_point = {X, Y, Z};
                cube_points[point_count++] = new_point;
            }
        }
    }
}

static void 
process_input(void)
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type)
    {
        case SDL_QUIT:
            is_running = false;
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE) is_running = false;
            break;
    }
}

static v2 
project(v3 P)
{
    v2 Result;

    Result.X = (CubeFOV*P.X)/P.Z;
    Result.Y = (CubeFOV*P.Y)/P.Z;

    return Result;
}

static void 
update(void)
{
    int TimeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() + PreviousFrameTime);

    if(TimeToWait > 0 && (TimeToWait <= FRAME_TARGET_TIME))
    {
        SDL_Delay(TimeToWait);
    }

    CubeRot += 0.01;
    for(int PointIndex = 0; PointIndex < N_POINTS; ++PointIndex)
    {
        v3 point = cube_points[PointIndex];
        point = rotate_x(point, CubeRot);
        point = rotate_y(point, CubeRot);
        point = rotate_z(point, CubeRot);
        point.Z -= CameraPos.Z;

        //v2 projected_point = project(point);
        v2 NewPoint = project(point);

        projected_points[PointIndex] = NewPoint;
    }
}

static void 
render(void)
{
    DrawGrid(0xFFFFFFFF);

    for(int PointIndex = 0; PointIndex < N_POINTS; ++PointIndex)
    {
        v2 point = projected_points[PointIndex];
        v2 MidDim = {(r32)window_width/2, (r32)window_height/2};
        DrawRect(point + MidDim, 6, 6, 0xFFFF0000);
    }

    RenderColorBuffer();
    ClearColorBuffer(0xFF000000);

    SDL_RenderPresent(renderer);
}

int main(int argc, char** argv)
{
    is_running = InitWindow();

    setup();

    while(is_running)
    {
        process_input();
        update();
        render();
    }

    DestroyWindow();

    return 0;
}
