#include "raylib.h"

int main(void)
{
    InitWindow(800, 600, "Audio Example");
    InitAudioDevice();

    Sound sound = LoadSound("music/last_resort.mp3");

    PlaySound(sound);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Playing audio... Press ESC to exit", 190, 280, 20, LIGHTGRAY);
        EndDrawing();
    }

    UnloadSound(sound);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

