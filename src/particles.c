#include "particles.h"
#include <raylib.h>
#include <raymath.h>

void initParticles (Particles particles[], int max)
{
    max = 200;
    for (int i = 0; i < max; i++)
    {
        particles[i].active = false;
    }
}

void spawnParticles (Particles particles [], int max)
{
    max = 200;
    for (int i = 0; i < max; i++)
    {
      if (particles[i].active == false) 
      {
        particles[i].active = true;
        particles[i].posXY = (Vector2) {
            (float) GetRandomValue(0, 800), 600.0f 
        };
        
        float randomSpeed = (float) GetRandomValue(8, 22) / 10.0f;
        particles[i].speedXY = (Vector2) {0.0f, randomSpeed};
        
        particles[i].alpha = 0;
        break;
      }
    }
}

void drawParticles (Particles particles [], int max, Texture2D *sprite)
{
  max = 200;
  for (int i = 0; i < max; i++) 
  {
    if (particles[i].active == true)
    {
      Color starColor = (Color){ 255, 255, 255, (unsigned char)particles[i].alpha };
      DrawTexture (*sprite, particles[i].posXY.x, particles[i].posXY.y, starColor);
    }
  }
}


//NOTE: the way i did wasn't decent in visual terms
// so i asked AI on how to do a better way of doing fade/fade out
//so this func is AI generated
void updateParticles (Particles particles [], int max, int *counter)
{
  max = 200;
  for (int i = 0; i < max; i++)
  {
    if (particles[i].active == true)
    {
      particles[i].posXY.y -= particles[i].speedXY.y;
      
      if (particles[i].posXY.y > 500.0f)
      {
        float progress = (600.0f - particles[i].posXY.y) / 100.0f;
        particles[i].alpha = (int)(progress * 255.0f);
      }
      else if (particles[i].posXY.y >= 100.0f)                    
      {
        particles[i].alpha = 255;
      }
      else
      {
        float progress = particles[i].posXY.y / 100.0f;  
        particles[i].alpha = (int)(progress * 255.0f);
      }

      if (particles[i].posXY.y <= 0.0f)
      {
        particles[i].active = false;
      }
    }
  }
}