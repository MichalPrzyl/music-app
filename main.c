
#include "raylib.h"
#include <math.h>

#define NUM_BANDS 16
#define AMPLITUDE 100
#define SPEED 2.0f

int main(void)
{
    InitWindow(800, 600, "Equalizer Simulation");
    InitAudioDevice();

    Sound sound = LoadSound("music/last_resort.mp3");

    PlaySound(sound);

    float bands[NUM_BANDS] = { 0 };
    float time = 0.0f;

    while (!WindowShouldClose())
    {
        // update time
        time += GetFrameTime();

        // Simulate different frequencies by modulating the amplitude
        for (int i = 0; i < NUM_BANDS; i++)
        {
            float frequency = (i + 1) * 0.1f;  // Simulate different frequencies
            bands[i] = fabs(sinf((frequency * PI) + (time * SPEED))) * AMPLITUDE;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        // Draw bars representing the simulated frequencies
        for (int i = 0; i < NUM_BANDS; i++)
        {
            float x = (800 / NUM_BANDS) * i;
            float height = bands[i];
            DrawRectangle(x, 600 - height, (800 / NUM_BANDS) - 2, height, i % 2 == 0 ? RED : GREEN);
        }

        DrawText("Playing audio... Press ESC to exit", 190, 550, 20, LIGHTGRAY);
        EndDrawing();

        if (!IsSoundPlaying(sound)) break;
    }

    UnloadSound(sound);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

