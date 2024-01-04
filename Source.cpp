#include <stdio.h>
#include <windows.h>
#include "CC212SGL.h"
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#define PI 3.14159265
#pragma comment (lib,"CC212SGL.lib")
CC212SGL grfk;







int main()
{
	
	int spaceship_size = 125;
	grfk.setup();
	grfk.setFullScreenMode(); //895X518
	grfk.hideCursor();
	grfk.setDrawingColor(BLACK);
	grfk.setFontSizeAndBoldness(500, 10);

	int y_down=grfk.getWindowHeight();
	int x_right=grfk.getWindowWidth();


	int x_spaceship =(x_right / 2) - (spaceship_size/2);  
	int y_spaceship=y_down - spaceship_size;

	int x_blast=x_spaceship;
	int y_blast=y_spaceship;
	

	int enemyblaster = grfk.loadImage("Enemyblaster.png");
	int enemy1 = grfk.loadImage("Enemy1.png");
	int enemy2 = grfk.loadImage("Enemy2.png");
	int spaceship = grfk.loadImage("Spaceship2.png"); //256X256
	int blast = grfk.loadImage("blast1.png");
	//int background = grfk.loadImage("background.png"); //960x540

	

	grfk.setDrawingColor(RED);
	
	int offwhite=grfk.generateFromRGB(247, 247, 247);

	int background=grfk.loadImage("snowbasesnow.png");
	int x_bkg=0;
	int y_bkg=0;
	int background2 = grfk.loadImage("snowbasesnow2.png");
	int x_bkg2 = 0;
	int y_bkg2= 0;
	
	int spaceshiplifecounter = 0;
	int enemylifecounter = 0;
	int enemy2lifecounter = 0;
	int x_enemy1 = 40;
	int y_enemy1 = 60;
	int z = 1;
	int t = 1;
	int x_enemy2 = grfk.getWindowWidth() - 110;
	int y_enemy2 = 60;
	
	
	int y_enemyblaster1= y_enemy1 + 100;
	int x_enemyblaster1 = x_enemy1 + 37;
	int x_enemyblaster2 = x_enemy2 + 37;
	int y_enemyblaster2 = y_enemy1 + 100;
	int difference = 100;
	int difference2 = 100;
	int differenceforenemyline = 100;
	int zoomcounter = 0;
	



	while (1) {
		grfk.beginDraw();


		grfk.drawImage(background, x_bkg++, y_bkg, BROWN);
		x_bkg2 = x_bkg - 1500;
		grfk.drawImage(background2, x_bkg2, y_bkg2, BROWN);
		//if (zoomcounter % 7 == 0) {
			//grfk.resizeImage(background, x_right++, y_down);
		//}
		grfk.setFontSizeAndBoldness(50, 500);
		grfk.setDrawingColor(WHITE);
		grfk.drawText(500, 100, "Space nebula");
		grfk.drawText(500, 700, "Press Space To Start");
		if (GetAsyncKeyState(' '))
			break;

		grfk.endDraw();
	}
	while (1)
	{
		int x_line2 = x_spaceship + difference;
		//differenceforenemyline = differenceforenemyline - 20;
		int x_line1 = x_enemy2 + difference2;
		
		int x_line = x_enemy1 + differenceforenemyline;
		grfk.setDrawingColor(RED);
		grfk.beginDraw();
		//grfk.drawImage(background,0,0,BROWN);
		//grfk.drawCircle(x_right/2, 500, 400);
		//grfk.drawImage(background,0,0,BROWN);

	/*grfk.drawImage(background, x_bkg++, y_bkg, BLACK);
	x_bkg2 = x_bkg - 1500;
	grfk.drawImage(background2, x_bkg2, y_bkg2, BLACK);*/



		grfk.setDrawingThickness(7);
		grfk.drawImage(spaceship, x_spaceship, y_spaceship, BLACK);
		if (GetAsyncKeyState('A') && x_spaceship > 10)
			x_spaceship = x_spaceship-=2;

		if (GetAsyncKeyState('D') && x_spaceship < x_right - spaceship_size - 10)
			x_spaceship = x_spaceship+=2;

		if (GetAsyncKeyState('W') && y_spaceship > y_down - 400)
			y_spaceship = y_spaceship--;


		if (GetAsyncKeyState('S') && y_spaceship < y_down - spaceship_size - 10)
			y_spaceship = y_spaceship++;

		grfk.drawImage(spaceship, x_spaceship, y_spaceship, BROWN);
		grfk.drawImage(blast, x_blast, y_blast = y_blast - 3, BLACK);
		if (y_blast < 0)
		{

			y_blast = y_spaceship - 20;
			x_blast = x_spaceship + 55;

		}
		int offwhite2 = grfk.generateFromRGB(255, 255, 255);
		if (x_enemy1 == grfk.getWindowWidth()/2 || x_enemy1 == 0)
			z *= -1;
		grfk.drawImage(enemy1, x_enemy1+=z, y_enemy1, offwhite2);
		grfk.drawImage(enemyblaster, x_enemyblaster1, y_enemyblaster1++, BROWN);
		grfk.drawImage(enemyblaster, x_enemyblaster2, y_enemyblaster2++, BROWN);
		grfk.drawImage(enemy2, x_enemy2 += t, y_enemy2, BLACK);

		if (y_enemyblaster1 > y_down && y_enemy1 > 0)
		{
			y_enemyblaster1 = y_enemy1 + 125;
			x_enemyblaster1 = x_enemy1 + 45;

		}
		if (y_enemyblaster2 > y_down && y_enemy2 > 0)
		{
			y_enemyblaster2 = y_enemy2 + 125;
			x_enemyblaster2 = x_enemy2 + 45;

		}
		if (x_enemy1 > x_right)
		{

			x_enemy1 = 30;

		}
		
		grfk.drawLine(x_enemy1, y_enemy1 - 20, x_line, y_enemy1 - 20);
		grfk.drawLine(x_enemy2, y_enemy2 - 20, x_line1, y_enemy2 - 20);
		grfk.drawLine(x_spaceship + 12, y_spaceship + 120, x_line2 + 12, y_spaceship + 120);

		
		if (x_enemy2 == grfk.getWindowWidth() - 109 || x_enemy2 == (grfk.getWindowWidth() / 2) + 20)
			t *= -1;

		if ((x_blast) >= (x_enemy1) && (x_blast) <= (x_enemy1 + 70) && y_blast >= (y_enemy1 - 50) && y_blast <= (y_enemy1 + 50))
		{
			enemylifecounter++;
			y_blast = y_spaceship - 20;
			x_blast = x_spaceship + 55;
			 //x_line > x_enemy1
		
			differenceforenemyline -= 10;
			
			if (enemylifecounter == 10)
			{
				x_enemy1 = -200;
				y_enemy1 = -200;
			}
		}
		if ((x_blast) >= (x_enemy2) && (x_blast) <= (x_enemy2 + 70) && y_blast >= (y_enemy2 - 50) && y_blast <= (y_enemy2 + 50))
		{
			enemy2lifecounter++;
			y_blast = y_spaceship - 20;
			x_blast = x_spaceship + 55;
			//x_line > x_enemy1

			difference2 -= 10;

			if (enemy2lifecounter == 10)
			{
				x_enemy2 = -200;
				y_enemy2 = -200;
			}
		}
		if ((x_enemyblaster1) >= (x_spaceship) && (x_enemyblaster1) <= (x_spaceship + 100) && y_enemyblaster1 >= (y_spaceship - 50) && y_enemyblaster1 <= (y_spaceship + 50))
		{
			spaceshiplifecounter++;
			y_enemyblaster1 = y_enemy1 + 60;
			x_enemyblaster1 = x_enemy1 + 40;
			difference = difference - 20;
			if (spaceshiplifecounter == 5)
			{
				break;
			}
		}
		if ((x_enemyblaster2) >= (x_spaceship) && (x_enemyblaster2) <= (x_spaceship + 100) && y_enemyblaster2 >= (y_spaceship - 50) && y_enemyblaster2 <= (y_spaceship + 50))
		{
			spaceshiplifecounter++;
			y_enemyblaster2 = y_enemy2 + 60;
			x_enemyblaster2 = x_enemy2 + 40;
			difference = difference - 20;
			if (spaceshiplifecounter == 5)
			{
				break;
			}
		}
		grfk.endDraw();
	}



		return 0;
}