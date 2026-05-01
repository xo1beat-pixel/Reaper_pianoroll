// Updated drawing_utils.cpp file

#include <vector>
#include <algorithm>

// ... other includes and definitions

void DrawPitchBendCurve() {
    // Set thickness for lines
    glLineWidth(3);

    // Loop through bend data and draw curves
    for (const auto& bend : pitchBendData) {
        // Draw larger control points
        DrawCircle(bend.x, bend.y, 5);

        // Extend pitch range by 3 times the note height
        float pitchHeight = bend.value * 3;
        DrawLine(bend.x, bend.baseY, bend.x, bend.baseY + pitchHeight);
    }

    // Better visual feedback when no bend data exists
    if (pitchBendData.empty()) {
        glColor3f(0.5, 0.5, 0.5); // grey color
        DrawLine(startX, baselineY, endX, baselineY);
    }
}

void DrawNotes() {
    if (g_mpeEnabled) {
        // Render pitch bend curves for all notes
        for (const auto& note : notes) {
            DrawPitchBendCurve(note);
        }
    }
    // ... existing note drawing code
}