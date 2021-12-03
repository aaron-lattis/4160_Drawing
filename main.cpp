// CS 4160 - starter code written by Victor Zordan

#include <iostream>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>


const int fps = 60;
const int frame_duration = 1000 / fps;

//Screen dimension
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* my_window = NULL;
SDL_Renderer* my_renderer = NULL;
SDL_Event input;

void my_SDL_init(){

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl; 
  }

  //Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);
  
  my_window = SDL_CreateWindow("my_game", 
			       SDL_WINDOWPOS_CENTERED, 
			       SDL_WINDOWPOS_CENTERED, 
			       SCREEN_WIDTH,
			       SCREEN_HEIGHT, 0);
  my_renderer = SDL_CreateRenderer(my_window,-1,0);

}

int main() 
{ 
  my_SDL_init();
  
  SDL_Texture* sun_texture = NULL;
  SDL_Texture* moon_texture = NULL;
  SDL_Texture* tree1_texture = NULL;
  SDL_Texture* tree2_texture = NULL;
  SDL_Texture* tree3_texture = NULL;
  SDL_Texture* mtn_texture = NULL;
  SDL_Texture* castle_texture = NULL;
  SDL_Texture* road_texture = NULL;
  SDL_Texture* bush_texture = NULL;
  //SDL_Texture* pond_texture = NULL;
  //SDL_Texture* hut_texture = NULL;
  
  SDL_Surface* temp = IMG_Load("./imgs/sun.png");
  sun_texture = SDL_CreateTextureFromSurface(my_renderer, temp);
  
  temp = IMG_Load("./imgs/moon.png");
  moon_texture = SDL_CreateTextureFromSurface(my_renderer, temp);
  
  temp = IMG_Load("./imgs/tree1.jpg");
  tree1_texture = SDL_CreateTextureFromSurface(my_renderer, temp);
  
  temp = IMG_Load("./imgs/tree2.png");
  tree2_texture = SDL_CreateTextureFromSurface(my_renderer, temp);
  
  temp = IMG_Load("./imgs/tree3.jpg");
  tree3_texture = SDL_CreateTextureFromSurface(my_renderer, temp);
  
  temp = IMG_Load("./imgs/mtn.png");
  mtn_texture = SDL_CreateTextureFromSurface(my_renderer, temp);
  
  temp = IMG_Load("./imgs/castle.png");
  castle_texture = SDL_CreateTextureFromSurface(my_renderer, temp);
  
  temp = IMG_Load("./imgs/road.png");
  road_texture = SDL_CreateTextureFromSurface(my_renderer, temp);
  
  temp = IMG_Load("./imgs/bush.png");
  bush_texture = SDL_CreateTextureFromSurface(my_renderer, temp);
  
  //temp = IMG_Load("./pond.png");
  //pond_texture = SDL_CreateTextureFromSurface(my_renderer, temp);
  
  //temp = IMG_Load("./hut1.png");
  //hut_texture = SDL_CreateTextureFromSurface(my_renderer, temp);
  
  SDL_FreeSurface(temp);
    
    
  SDL_Rect ground;
  ground.x = 0;
  ground.y = 340;
  ground.w = 640;
  ground.h = 140;
  
  SDL_Rect sky;
  sky.x = 0;
  sky.y = 0;
  sky.w = 640;
  sky.h = 360;
  
  //SDL_Rect sky_2;
  //sky_2.x = 0;
  //sky_2.y = 0;
  //sky_2.w = 640;
  //sky_2.h = 360;
  
  //SDL_Rect pond;
  //pond.x = 45;
  //pond.y = 375;
  //pond.w = 115;
  //pond.h = 65;
  
  //SDL_Rect hut;
  //hut.x = 17;
  //hut.y = 335;
  //hut.w = 70;
  //hut.h = 70;
  
  //SDL_Rect sun;
  //sun.x = 195;
  //sun.y = 25;
  //sun.w = 105;
  //sun.h = 105;
  
  SDL_Rect sun;
  sun.x = -95;
  sun.y = 245;
  sun.w = 95;
  sun.h = 95;
  
  
  
  
  SDL_Rect moon;
  moon.x = -70;
  moon.y = 0;
  moon.w = 45;
  moon.h = 45;
  
  SDL_Rect tree1;
  tree1.x = 100;
  tree1.y = 320;
  tree1.w = 105;
  tree1.h = 105;
  
  SDL_Rect tree2_1;
  tree2_1.x = 360;
  tree2_1.y = 330;
  tree2_1.w = 45;
  tree2_1.h = 45;
  
  SDL_Rect tree2_2;
  tree2_2.x = 190;
  tree2_2.y = 330;
  tree2_2.w = 45;
  tree2_2.h = 45;
  
  SDL_Rect tree3;
  tree3.x = 20;
  tree3.y = 300;
  tree3.w = 105;
  tree3.h = 105;
  
  SDL_Rect mtn1;
  mtn1.x = 240;
  mtn1.y = 290;
  mtn1.w = 415;
  mtn1.h = 60;
  
  SDL_Rect mtn2;
  mtn2.x = 0;
  mtn2.y = 270;
  mtn2.w = 360;
  mtn2.h = 80;
  
  SDL_Rect castle;
  castle.x = 200;
  castle.y = 165;
  castle.w = 200;
  castle.h = 200;
  
  SDL_Rect road;
  road.x = 251;
  road.y = 365;
  road.w = 145;
  road.h = 200;
  
  SDL_Rect bush_1;
  bush_1.x = 270;
  bush_1.y = 360;
  bush_1.w = 15;
  bush_1.h = 15;
  
  SDL_Rect bush_2;
  bush_2.x = 321;
  bush_2.y = 360;
  bush_2.w = 15;
  bush_2.h = 15;
  
  SDL_Rect bush_3;
  bush_3.x = 264;
  bush_3.y = 375;
  bush_3.w = 30;
  bush_3.h = 30;
  
  SDL_Rect bush_4;
  bush_4.x = 326;
  bush_4.y = 375;
  bush_4.w = 30;
  bush_4.h = 30;
  
  
  SDL_Rect bush_5;
  bush_5.x = 227;
  bush_5.y = 405;
  bush_5.w = 70;
  bush_5.h = 70;
  
  SDL_Rect bush_6;
  bush_6.x = 339;
  bush_6.y = 405;
  bush_6.w = 70;
  bush_6.h = 70;
  


  int X = 1;
  int Y = 2; 

  
  SDL_Rect stars [1000]; 
  
  
  for (int i = 0; i < 1000; i ++)
  {
    
     if (X > 640) { X = 0; }
     else { X += 17; }
        
     if (Y > 480) { Y = 0; }
     else { Y += 9; }
        

     stars[i].x = X;
     stars[i].y = Y;
     stars[i].w = 1;
     stars[i].h = 1;
     
     
  
  }
  
  
  
  //bool moonIsOut = false;
  
  int sunMvmt = -1;
  
  int this_start_time = 0;
  int fps_counter = 0;
  int last_count_start_time = 0;
  //int current_fps = 0;
  int this_duration = 0;
  //int frame_duration = 0; 

  
  int frame = 0;

  int moveStraight = 0;
  
  bool sunIsOut = true;
  
  bool sunGoingUp = true;
  
  
  int skyG = 153;
  int skyB = 204;
  
  
  //int rand1 = 3;
  //int rand2 = 5;
  //int rand3 = 4;
  //int rand4 = 2;
  //int rand5 = 6;
  
  int cntr1 = 0;
  int cntr2 = 1;
  int cntr3 = 2;
  int cntr4 = 3;
  int cntr5 = 4;

  while(true){
    
    SDL_RenderClear(my_renderer);
    
    this_start_time = SDL_GetTicks();
    
    
    SDL_SetRenderDrawColor(my_renderer, 0, skyG, skyB, 255);
    SDL_RenderFillRect(my_renderer, &sky);
    
    
	    if (!sunIsOut && !(!sunGoingUp && moon.y > 205))
	    {
	    
	    
	    /*
              if (moon.y < 205 && moon.y > 190)
              {
		    for (int i = 0; i < 1000; i ++ )
		    {  
		    
		         cntr1 += 74 + (i % 11);
		         cntr2 += 73 + (i % 11);
		         cntr3 += 73 + (i % 11);
		         cntr4 += 74 + (i % 11);
		         cntr5 += 73 + (i % 11);
		         
			 
			 if (cntr1 > 999) { cntr1 = 0; }
			 if (cntr2 > 999) { cntr2 = 1; }
			 if (cntr3 > 999) { cntr3 = 2; }
			 if (cntr4 > 999) { cntr4 = 3; }
			 if (cntr5 > 999) { cntr5 = 4; }
			 
			 
			  
			 if ( 1 ==2 ) //if (i % 15 == 0 || i % 15 == 1 || i % 15 == 2)
			 {
			  
			    SDL_SetRenderDrawColor(my_renderer, 255,255,255,255);
			    //SDL_RenderFillRect(my_renderer, &stars[cntr1]);

		 	 }
			 
			    
			 
			else if ( 1 == 2) //else if (i % 15 == 3 || i % 15 == 4 || i % 15 == 5)
			{
			  
			    SDL_SetRenderDrawColor(my_renderer, 255,255,255,255);
			    //SDL_RenderFillRect(my_renderer, &stars[cntr2]);

			    
			 
			}		  
			   
			else if (i % 15 == 6 || i % 15 == 7 || i % 15 == 8)
			{
			  
			    SDL_SetRenderDrawColor(my_renderer, 255,255,255,255);
			    //SDL_RenderFillRect(my_renderer, &stars[cntr3]);

			 
			}
			else if (i % 15 == 9 || i % 15 == 10 || i % 15 == 11)
			{
			  
			    SDL_SetRenderDrawColor(my_renderer, 255,255,255,255);
			  //  SDL_RenderFillRect(my_renderer, &stars[cntr4]);

			 
			}    
			else if (3 == 4) //else if (i % 15 == 12 || i % 15 == 13 || i % 15 == 14)
			{
			  
			    SDL_SetRenderDrawColor(my_renderer, 255,255,255,255);
			  //  SDL_RenderFillRect(my_renderer, &stars[cntr5]);

			 
			}        
		    }
	    
	    }
    */
                 if (moon.y < 160)
                 {

		    for (int i = 0; i < 1000; i ++ )
		    {  
		    
		         cntr1 += 54 + (i % 11);
		         cntr2 += 54 + (i % 3);
		         cntr3 += 54 + (i % 11);
		         cntr4 += 54 + (i % 3);
		         cntr5 += 54 + (i % 11);
		         
			 
			 if (cntr1 > 999) { cntr1 = 0; }
			 if (cntr2 > 999) { cntr2 = 1; }
			 if (cntr3 > 999) { cntr3 = 2; }
			 if (cntr4 > 999) { cntr4 = 3; }
			 if (cntr5 > 999) { cntr5 = 4; }
			 
			 
			 /* 
			 if (frame % 15 == 0 || frame % 15 == 1 || frame % 15 == 2)
			 {
			  
			    SDL_SetRenderDrawColor(my_renderer, 255,255,255,255);
			   // SDL_RenderFillRect(my_renderer, &stars[cntr1]);
		 	 }
			 
			    
			 
			else if (frame % 15 == 3 || frame % 15 == 4 || frame % 15 == 5)
			{
			  
			    SDL_SetRenderDrawColor(my_renderer, 255,255,255,255);
			  //  SDL_RenderFillRect(my_renderer, &stars[cntr2]);
			 
			}		  
			   */
			//if (i % 4 == 0 || i % 4 == 1)
			//{
			  
			    SDL_SetRenderDrawColor(my_renderer, 255,255,255,255);
			    SDL_RenderFillRect(my_renderer, &stars[cntr3]);
			 
			//}
			//else if (frame % 15 == 9 || frame % 15 == 10 || frame % 15 == 11)
			//{
			  
			   // SDL_SetRenderDrawColor(my_renderer, 255,255,255,255);
			   // SDL_RenderFillRect(my_renderer, &stars[cntr4]);
			 
			//}    
			//else if (i % 4 == 2 || i % 4 == 3)
			//{
			  
			  //  SDL_SetRenderDrawColor(my_renderer, 255,255,255,255);
			 //   SDL_RenderFillRect(my_renderer, &stars[cntr5]);
			 ///
			//}        
		    }
	    
    }
    /*
     else if (moon.y < 171)
    {
	    

		  for (int i = 0; i < 1000; i ++ )
		    {  
		    
		         cntr1 += 31 + (i % 11);
		         cntr2 += 31 + (i % 3);
		         cntr3 += 31 + (i % 11);
		         cntr4 += 31 + (i % 3);
		         cntr5 += 31 + (i % 11);
		         
			 
			 if (cntr1 > 999) { cntr1 = 0; }
			 if (cntr2 > 999) { cntr2 = 1; }
			 if (cntr3 > 999) { cntr3 = 2; }
			 if (cntr4 > 999) { cntr4 = 3; }
			 if (cntr5 > 999) { cntr5 = 4; }
			 
			 
			  
			 if (frame % 15 == 0 || frame % 15 == 1 || frame % 15 == 2)
			 {
			  
			    SDL_SetRenderDrawColor(my_renderer, 255,255,255,255);
			//    SDL_RenderFillRect(my_renderer, &stars[cntr1]);
		 	 }
			 
			    
			 
			else if (frame % 15 == 3 || frame % 15 == 4 || frame % 15 == 5)
			{
			  
			    SDL_SetRenderDrawColor(my_renderer, 255,255,255,255);
			//    SDL_RenderFillRect(my_renderer, &stars[cntr2]);
			 
			}		  
			   
			else if (frame % 15 == 6 || frame % 15 == 7 || frame % 15 == 8)
			{
			  
			    SDL_SetRenderDrawColor(my_renderer, 255,255,255,255);
			//    SDL_RenderFillRect(my_renderer, &stars[cntr3]);
			 
			}
			else if (frame % 15 == 9 || frame % 15 == 10 || frame % 15 == 11)
			{
			  
			    SDL_SetRenderDrawColor(my_renderer, 255,255,255,255);
			//   SDL_RenderFillRect(my_renderer, &stars[cntr4]);
			 
			}    
			else if (frame % 15 == 12 || frame % 15 == 13 || frame % 15 == 14)
			{
			  
			    SDL_SetRenderDrawColor(my_renderer, 255,255,255,255);
			 //   SDL_RenderFillRect(my_renderer, &stars[cntr5]);
			 
			}        
		    }
           }*/
	    
    }
    
    
    
    
    //SDL_SetRenderDrawColor(my_renderer, 100,100,100,howDark);
    //SDL_RenderFillRect(my_renderer, &sky_2);
  
    
    SDL_RenderCopy(my_renderer, sun_texture, NULL, &sun);
    SDL_RenderCopy(my_renderer, moon_texture, NULL, &moon);
    
    
    
    if (sunIsOut)
    {
	    if (frame % 2 == 0) { sun.x += 1; }
	    
	    if (sun.y < 115) 
	    {
	    
	       moveStraight ++;
	       
	       if (moveStraight >= 50) { sunMvmt = 1; }
	       else { sun.y += 1; }
	    }
	    
	    if (moveStraight <= 125 && moveStraight >= 75) { sun.y -= 1; }
	    else if (moveStraight <= 75 && moveStraight >= 50) { sun.y -= 2; }
	    
	    sun.x += 2;
	    sun.y += 2 * sunMvmt;
	    
	    if (sun.y > 115 && sunGoingUp && skyG < 255 && skyG > 0 && skyB < 255 && skyB > 0) { skyG ++; skyB ++; }
	    else if (sun.y > 115 && !sunGoingUp && skyG < 255 && skyG > 0 && skyB < 255 && skyB > 0) { skyG --; skyB --; }
	    else if (sun.y < 115 && sunGoingUp) { sunGoingUp = false; skyG --; skyB --; }
	    
	    
	 
	    
	    if (sun.x >= 640)
	    {
	       sunIsOut = false;
	       sunGoingUp = true;
	       
	       moon.x = -95;
  	       moon.y = 245;
  	       moon.w = 95;
  	       moon.h = 95;
  	       
  	       frame = 0;
               moveStraight = 0;
  	       sunMvmt = -1;
  	       
  	       cntr1 = 0;
  	       cntr2 = 1;
  	       cntr3 = 2;
  	       cntr4 = 3;
  	       cntr5 = 4;
	    }
    }
    else
    {
            if (frame % 2 == 0) { moon.x += 1; }
	    
	    if (moon.y < 115) 
	    { 
	       moveStraight ++;
	       
	       if (moveStraight >= 50) { sunMvmt = 1; }
	       else { moon.y += 1; }
	    }
	    
	    if (moveStraight <= 125 && moveStraight >= 75) { moon.y -= 1; }
	    else if (moveStraight <= 75 && moveStraight >= 50) { moon.y -= 2; }
	    
	    moon.x += 2;
	    moon.y += 2 * sunMvmt;
	    
	    if (moon.y > 190 && sunGoingUp && skyG < 255 && skyG > 3 && skyB < 255 && skyB > 3) { skyG -= 3; skyB -= 3; }
	    else if (moon.y > 200 && !sunGoingUp && skyG < 255 && skyG > 0 && skyB < 255 && skyB > 0) { skyG += 4; skyB += 4; }
	    else if (moon.y < 190 && sunGoingUp) { sunGoingUp = false; skyG += 4; skyB += 4; }
	    
	  
	    
	    
	    if (moon.x == 640)
	    {
	       sunIsOut = true;
	       sunGoingUp = true;
	       
	       sun.x = -95;
  	       sun.y = 245;
  	       sun.w = 95;
  	       sun.h = 95;
  	       
  	       frame = 0;
               moveStraight = 0;
  	       sunMvmt = -1;
	    }
    }
    
    
    frame ++;
    
    
        
    
    
    
    
    SDL_SetRenderDrawColor(my_renderer, 86,138,0,255);
    SDL_RenderFillRect(my_renderer, &ground);
    
    
    SDL_RenderCopy(my_renderer, tree1_texture, NULL, &tree1);
    
    SDL_RenderCopy(my_renderer, tree3_texture, NULL, &tree3);
    SDL_RenderCopy(my_renderer, mtn_texture, NULL, &mtn1);
    SDL_RenderCopy(my_renderer, mtn_texture, NULL, &mtn2);
    SDL_RenderCopy(my_renderer, castle_texture, NULL, &castle);
    SDL_RenderCopy(my_renderer, road_texture, NULL, &road);
    
    SDL_RenderCopy(my_renderer, tree2_texture, NULL, &tree2_1);
    SDL_RenderCopy(my_renderer, tree2_texture, NULL, &tree2_2);
    
    //SDL_RenderCopy(my_renderer, pond_texture, NULL, &pond);
    //SDL_RenderCopy(my_renderer, hut_texture, NULL, &hut);
    
    SDL_RenderCopy(my_renderer, bush_texture, NULL, &bush_1);
    SDL_RenderCopy(my_renderer, bush_texture, NULL, &bush_2);
    SDL_RenderCopy(my_renderer, bush_texture, NULL, &bush_3);
    SDL_RenderCopy(my_renderer, bush_texture, NULL, &bush_4);
    SDL_RenderCopy(my_renderer, bush_texture, NULL, &bush_5);
    SDL_RenderCopy(my_renderer, bush_texture, NULL, &bush_6);
    

    
    SDL_RenderPresent(my_renderer);
    
    
    fps_counter++;
    
    if (this_start_time >= (last_count_start_time + 1000))
    {
       last_count_start_time = this_start_time;
       //current_fps = fps_counter;
       fps_counter = 0;
    }
    
    //std::cout << current_fps << "\n";
    
    this_duration = SDL_GetTicks() - this_start_time;
    
    if (this_duration < frame_duration)
    {
       SDL_Delay(frame_duration - this_duration);
    }
    
    
    
    

  }

  SDL_DestroyRenderer(my_renderer);
  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();
  
  return 0; 
}







