// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator = atoi(&fraction[0]);
    int denominator = atoi(&fraction[2]);
    int eights = 8 / denominator * numerator;
    return eights;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //handle octaves
    int octave = atoi(&note[strlen(note) - 1]);
    int oDifference = octave - 4;

    // handle accidentals
    int aSemitone = 0;
    if (strlen(note) >= 3)
    {
        aSemitone = note[1] == '#' ? 1 : -1;
    }

    // handle pitch
    int pSemitones = 0;
    switch (note[0])
    {
        case 'A':
            pSemitones = 0;
            break;
        case 'B':
            pSemitones = 2;
            break;
        case 'C':
            pSemitones = -9;
            break;
        case 'D':
            pSemitones = -7;
            break;
        case 'E':
            pSemitones = -5;
            break;
        case 'F':
            pSemitones = -4;
            break;
        case 'G':
            pSemitones = -2;
            break;
        default:
            break;
    }

    // calculate total semitones
    int combinedSemitones = oDifference * 12 + aSemitone + pSemitones;

    // frequency algo
    double frequency = 440 * pow(2, combinedSemitones / 12.);
    return round(frequency);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return strcmp(s, "") == 0;
}
