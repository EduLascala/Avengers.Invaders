#include <stdio.h>
#include <locale.h>
#include <allegro.h>

//Variáveis Globais
int sai    = 0;
int width  = 740;
int height = 700;
int shoot  =   0;

struct objetos
{
    int  x;
    int  y;
    int wx;
    int wy;
    int  w;
    int  h;
} vingadores [5][10];

void sair();
void controle();
int colisao(int Ax, int Ay, int Bx, int By, int Aw, int Ah, int Bw, int Bh);

struct objetos  //Posição inicial de cada objeto para fazer o desenho//
nave = {294, 626, 294, 626, 34, 68},
bullet = {-10, -10, 7, 683, 3, 8},
binvaders[2] = {-10, -10, 13, 683, 3, 8, -10, -10, 13, 683, 3, 8},
disco = {495, 163, 495, 163, 56, 64},
destroy = {27, 216, 27, 216, 58, 54}
                         ;
                         
int main()
{
    setlocale(LC_ALL, "portuguese");

    //Iniciação
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_window_title("Avengers Invaders");
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    set_close_button_callback(sair);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 740, 700, 0, 0);

    //Variáveis Locais
    int passo  		 =  0;
    int tempo  		 = 65;
    int t	   		 =  0;
    int face   		 =  0;
    int left  		 =  0;
    int down 	     =  0;
    int dscx		 = 2000;
    int pontos		 =  0;
    int vida  		 =  0;
    int vidas	     =  3;
    int	play	     =  0;
    int dano   	  	 =  0;
    int nInvaders    = 	0;
    int nInvadersOld = 	0;
    int dificuldade  =  1;
    int multipasso   =  8;
    char music;

    //Imagens, BITMAPS e Fontes//
    BITMAP *buffer  = create_bitmap(width, height);
    BITMAP *fundo   = load_bitmap("img/fundo.bmp", NULL);
    BITMAP *invad   = load_bitmap("img/invaders.bmp", NULL);
    //Sons//
    SAMPLE *fase  = load_sample("sounds/vingadores.wav");
    SAMPLE *fase2 = load_sample      ("sounds/duck.wav");
    SAMPLE *fase3 =	load_sample("sounds/bokunohero.wav");
    SAMPLE *fase4 =	load_sample    ("sounds/bleach.wav");
    SAMPLE *fase5 =	load_sample  ("sounds/shingeki.wav");
	SAMPLE *fase6 =	load_sample  ("sounds/undertale.wav");
	SAMPLE *fim   =	load_sample  ("sounds/inevitable.wav");
/////////////////////////////////////////////////////////

    int i, j;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 10; j++)
        {
            vingadores[j][i].x = 38 + j*62;
            vingadores[j][i].y = 251 + i*53;
            vingadores[j][i].wx = 38;
            vingadores[j][i].wy = 291 + i*53;
            vingadores[j][i].w = 41;
            vingadores[j][i].h = 40;
        }
    }
    while (!(sai || key[KEY_ESC]))
    {
        while(!(sai || key[KEY_ESC] || play))
        {
            shoot = 0;
            dscx = 2000;
            dano = 0;
            binvaders[0].y = height;
            binvaders[1].y = height;
            binvaders[0].x = -10;
            binvaders[1].x = -10;
            rectfill(buffer, 0, 0, width, height, 0);
            if(vida || !pontos)
                textout_centre_ex(buffer, font, "Press SPACE", width/2, height/2, 0xffffff, 0);
            else
                textout_centre_ex(buffer, font, "GAME OVER", width/2, height/2, 0xffffff, 0);
            	textout_centre_ex(buffer, font, "AVENGERS INVADERS", width/2, height/6.3, 0xffffff, 0);
            //Printf musicas//
            textout_centre_ex(buffer, font, "ESCOLHA SUA MUSICA", width/2, height/5.4, 0xffffff, 0);
            textout_centre_ex(buffer, font, "Vingadores:      1", width/2, height/5, 0xffffff, 0);
            textout_centre_ex(buffer, font, "Duck Tales:      2", width/2, height/4.5, 0xffffff, 0);
            textout_centre_ex(buffer, font, "You Say Run:     3", width/2, height/4.2, 0xffffff, 0);
            textout_centre_ex(buffer, font, "Change:          4", width/2, height/3.9, 0xffffff, 0);
            textout_centre_ex(buffer, font, "Shingeki:        5", width/2, height/3.6, 0xffffff, 0);
            textout_centre_ex(buffer, font, "Undertale:       6", width/2, height/3.3, 0xffffff, 0);
            textout_centre_ex(buffer, font, "Sem Musica:      0", width/2, height/3.1, 0xffffff, 0);
            textout_centre_ex(buffer, font, "Continuar a Mesma:  Space", width/2, height/2.9, 0xffffff, 0);

			//Printf Dificuldades//
			textout_centre_ex(buffer, font, "ESCOLHA A DIFICULDADE:", width/2, height/1.8, 0xffffff, 0);
            textout_centre_ex(buffer, font, "EASY:   Press E.", width/2, height/1.7, 0xffffff, 0);
            textout_centre_ex(buffer, font, "MEDIUM: Press M.", width/2, height/1.6, 0xffffff, 0);
            textout_centre_ex(buffer, font, "HARD:   Press H.", width/2, height/1.5, 0xffffff, 0);
            
            //Printf Nomes do grupo//
            textout_centre_ex(buffer, font, "GRUPO:", width/5, height/1.16, 0xffffff, 0);
            textout_centre_ex(buffer, font, "Eduardo Lascala Mari", width/5, height/1.12, 0xffffff, 0);
            textout_centre_ex(buffer, font, "Caio Nogueira Erbiste", width/5, height/1.1, 0xffffff, 0);
            textout_centre_ex(buffer, font, "Lucas Lira Sassett", width/5, height/1.08, 0xffffff, 0);
            textout_centre_ex(buffer, font, "Kassio Kochann", width/5, height/1.06, 0xffffff, 0);
            textout_centre_ex(buffer, font, "Gabriel Regis Ribeiro", width/5, height/1.04, 0xffffff, 0);
            
			//Printf fixos//
            textprintf_centre_ex(buffer, font, width/2, height/10, 0xffffff, -1, "SCORE: %i", pontos);
            textprintf_centre_ex(buffer, font, width/1.2, height/1.04, 0xffffff, -1, "LIFES: 0%i", vida);
            draw_sprite(screen, buffer, 0, 0);

			//Musica tocando no Menu//
            if(key[KEY_1])
            {
                music = 1;
                stop_sample(fase);
                stop_sample(fase2);
                stop_sample(fase3);
                stop_sample(fase4);
                stop_sample(fase5);
                stop_sample(fase6);
				stop_sample(fim);
                play_sample(fase, 255, 128, 1000, 1);
            }
            if(key[KEY_2])
            {
                music = 2;
                stop_sample(fase);
                stop_sample(fase2);
                stop_sample(fase3);
                stop_sample(fase4);
                stop_sample(fase5);
                stop_sample(fase6);
                stop_sample(fim);
                play_sample(fase2, 255, 128, 1000, 1);
            }
            if(key[KEY_3])
            {
                music = 3;
                stop_sample(fase);
                stop_sample(fase2);
                stop_sample(fase3);
                stop_sample(fase4);
                stop_sample(fase5);
                stop_sample(fase6);
                stop_sample(fim);
                play_sample(fase3, 255, 128, 1000, 1);
            }
            if(key[KEY_4])
            {
                music = 4;
                stop_sample(fase);
                stop_sample(fase2);
                stop_sample(fase3);
                stop_sample(fase4);
                stop_sample(fase5);
                stop_sample(fase6);
                stop_sample(fim);
                play_sample(fase4, 255, 128, 1000, 1);
            }
            if(key[KEY_5])
            {
                music = 5;
                stop_sample(fase);
                stop_sample(fase2);
                stop_sample(fase3);
                stop_sample(fase4);
                stop_sample(fase5);
                stop_sample(fase6);
                stop_sample(fim);
                play_sample(fase5, 255, 128, 1000, 1);
            }
            if(key[KEY_6])
            {
                music = 6;
                stop_sample(fase); 
                stop_sample(fase2);
                stop_sample(fase3);
                stop_sample(fase4);
                stop_sample(fase5);
                stop_sample(fase6);
                stop_sample(fim);
                play_sample(fase6, 255, 128, 1000, 1);
            }
            if(key[KEY_0])
            {
				music = 0;
                stop_sample(fase);
                stop_sample(fase2);
                stop_sample(fase3);
                stop_sample(fase4);
                stop_sample(fase5);
                stop_sample(fase6);
                stop_sample(fim);
            }
            
            //Dando Start, Musica e Dificuldade//
            if(key[KEY_E])
				{
				multipasso = multipasso;	
				}
		 		if(key[KEY_M])
				{
				multipasso = 10;	
				}
		 		if(key[KEY_H])
		 		{
				multipasso = 15;	
				}		
            if(key[KEY_SPACE])
            {
                switch (music)
                {
                case 1:
					stop_sample(fim);
                	stop_sample(fase);
                    play_sample(fase, 255, 128, 1000, 1);
                    break;
                case 2:
					stop_sample(fim);
                	stop_sample(fase2);
                    play_sample(fase2, 255, 128, 1000, 1);
                    break;
                case 3:
					stop_sample(fim);
                	stop_sample(fase3);
                    play_sample(fase3, 255, 128, 1000, 1);
                    break;
                case 4:
					stop_sample(fim);
                	stop_sample(fase4);
                    play_sample(fase4, 255, 128, 1000, 1);
                    break;
                case 5:
					stop_sample(fim);
                	stop_sample(fase5);
                    play_sample(fase5, 255, 128, 1000, 1);
                    break;
                case 6:
					stop_sample(fim);
                	stop_sample(fase6);
                    play_sample(fase6, 255, 128, 1000, 1);
                    break;  
				default: 
					stop_sample(fase);
               		stop_sample(fase2);
                	stop_sample(fase3);
                	stop_sample(fase4);
                	stop_sample(fase5);
                	stop_sample(fase6);
                	stop_sample(fim);
					break;		  
                }
                play = 1;
                rest(30);
                //Posicionando e dando movimento aos Invaders//
                if(!vida || nInvaders >= 50)
                {
                    int i, j;
                    for(i = 0; i < 5; i++)
                    {
                        for(j = 0; j < 10; j++)
                        {
                            vingadores[j][i].x = 38 + j*62;
            				vingadores[j][i].y = 251 + i*53;
            				vingadores[j][i].wx = 38;
            				vingadores[j][i].wy = 291 + i*53;
            				vingadores[j][i].w = 41;
            				vingadores[j][i].h = 40;
                        }
                    }
                    tempo = 65;
                    nInvaders = 0;
                    nave.x = width/2;
                }
                if(!vida)
                {
                    vida = vidas;
                    pontos = 0;
                }
            }
            rest (30);
            clear(buffer);
        }
        controle();
        nInvadersOld = nInvaders;
        t++;
        passo = 0;
        if(t > tempo)
        {
            t = 0;
            passo = 1;
            face = !face;
        }
        draw_sprite(buffer, fundo, 0, 0);
       
	    //Declarando e Desenhando o Disco Voador://
        dscx--;
        disco.x = dscx;
        if(disco.x < -disco.w)
        dscx = 2000;
        masked_blit(invad, buffer, disco.wx, disco.wy, disco.x, disco.y, disco.w, disco.h);

        //Declarando, Desenhando e Dando função ao Tiro dos Invaders://
        int sort = rand()%10;
        if(binvaders[0].y < height)
            binvaders[0].y += 2;
        if(binvaders[1].y < height)
            binvaders[1].y += 2;
		int i, j;
        for(i = 0; i < 5; i++)
        {
            if(binvaders[1].y >= height && vingadores[sort][4-i].y < height)
            {
                binvaders[1].x = vingadores[sort][4-i].x + vingadores[sort][4-i].w/2;
                binvaders[1].y = vingadores[sort][4-i].y + vingadores[sort][4-i].h/2;
            }
            for(j = 0; j < 10; j++)
            {		
                if(vingadores[j][i].y < height)
                {
                    if(vingadores[j][i].x <  4 && !left)
                    {
                        down = 1;
                        vingadores[j][i].x += passo*multipasso;
                    }
                    if(vingadores[j][i].x > 704 &&  left)
                    {
                        down = 1;
                        vingadores[j][i].x -= passo*multipasso;
                    }
                    left ? 	(vingadores[j][i].x += passo*multipasso) : (vingadores[j][i].x -= passo*multipasso);
                }
                if(vingadores[9-j][4-i].x == nave.x && binvaders[0].y >= height && vingadores[9-j][4-i].y < height)
                {
                    binvaders[0].x = vingadores[9-j][4-i].x + vingadores[9-j][4-i].w/2;
                    binvaders[0].y = vingadores[9-j][4-i].y + vingadores[9-j][4-i].h/2;
                }
                masked_blit(invad, buffer, vingadores[j][i].wx + face*62, vingadores[j][i].wy, vingadores[j][i].x, vingadores[j][i].y, vingadores[j][i].w, vingadores[j][i].h);
                //colisões//
                //Colisão entre Nave e Tiro dos Invaders//
                if(colisao(binvaders[0].x, binvaders[0].y, nave.x, nave.y, binvaders[0].w, binvaders[0].h, nave.w, nave.h) || colisao(binvaders[1].x, binvaders[1].y, nave.x, nave.y, binvaders[1].w, binvaders[1].h, nave.w, nave.h))
                {
                    dano = 1;
                    stop_sample(fase);
                    stop_sample(fase2);
                    stop_sample(fase3);
                    stop_sample(fase4);
                    stop_sample(fase5);
                    stop_sample(fase6);
					stop_sample(fim);
                }
                //Colisão entre Meu tiro e Disco Voador//
                if(colisao(bullet.x, bullet.y, disco.x, disco.y, bullet.w, bullet.h, disco.w, disco.h))
                {
                    masked_blit(invad, buffer, destroy.wx, destroy.wy, disco.x, disco.y, destroy.w+10, destroy.h+10);
                    masked_blit(invad, buffer, disco.wx, disco.wy, disco.x, disco.y, disco.w, disco.h);
                    pontos += 2;
                    dscx = 2000;
                    shoot = 0;
                }
                //Colisão entre meu tiro e Invaders
                if(colisao(bullet.x, bullet.y, vingadores[j][i].x, vingadores[j][i].y, bullet.w, bullet.h, vingadores[j][i].w, vingadores[j][i].h))
                {
                    masked_blit(invad, buffer, destroy.wx, destroy.wy, vingadores[j][i].x, vingadores[j][i].y, destroy.w, destroy.h);
                    vingadores[j][i].y = height;
                    nInvaders++;
	                pontos += 15;
                    shoot = 0;
                }
            }
        }
        //Velocidade dos Invaders conforme eles são atingidos//
        if(nInvaders != nInvadersOld)
        {
            if(nInvaders == 10)
            {
                tempo = 25;
            }
            if(nInvaders == 20)
            {
                tempo = 15;
            }
            if(nInvaders == 30)
            {
                tempo =  12;
            }
            if(nInvaders == 40)
            {
                tempo =  8;
            }
            if(nInvaders == 45)
            {
                tempo =  4;
            }


        }
        //Quando todos os 50 invaders são Eliminados//
        if(nInvaders == 50)
        {
			if(vida >= 3)
			{
				pontos += 100;				
			}
        	dscx--;
        	disco.x = dscx;
            stop_sample(fase);
            stop_sample(fase2);
            stop_sample(fase3);
            stop_sample(fase4);
            stop_sample(fase5);
            stop_sample(fase6);
            vida++;
            play_sample(fim, 255, 128, 1000, 0);
            play = 0;
	    }
        //Descendo vingadores ao tocar no canto da tela(Esquerda ou direita)//
        if(down)
        {
            left = !left;
            for(i = 0; i < 5; i++)
            {
                for(j = 0; j < 10; j++)
                {
                    vingadores[j][i].y += 20; //Quantidade de pixels que os vingadores descem//
                    if(vingadores[j][i].y + vingadores[j][i].h >= nave.y && vingadores[j][i].y <height)
                    {
                        play =0;
                        vida = 0;
                    }
                }
            }
        }
        down = 0;
        if(dano)
        {
            masked_blit(invad, buffer, destroy.wx-5, destroy.wy-5, nave.x, nave.y, destroy.w+10, destroy.h+10);
            nave.x = width/2;

        }
        else
        {
            masked_blit(invad, buffer, nave.wx, nave.wy, nave.x, nave.y, nave.w, nave.h);
            masked_blit(invad, buffer, bullet.wx, bullet.wy, bullet.x, bullet.y, bullet.w, bullet.h);
            masked_blit(invad, buffer, binvaders[0].wx, binvaders[0].wy, binvaders[0].x, binvaders[0].y, binvaders[0].w, binvaders[0].h);
            masked_blit(invad, buffer, binvaders[1].wx, binvaders[1].wy, binvaders[1].x, binvaders[1].y, binvaders[1].w, binvaders[1].h);
        }
        textprintf_centre_ex(buffer, font, width/2, 6, 0xffffff, -1, "SCORE: %i", pontos);
        textprintf_centre_ex(buffer, font, width/1.2, height/1.04, 0xffffff, -1, "LIFES: %i", vida);

        draw_sprite(screen, buffer, 0, 0);
        if(dano)
        {
            vida--;
            play = 0;
            rest(2000);
            dano = 0;
        }

        rest(10);
        clear(buffer);
    }
    
    destroy_bitmap(buffer);
    return 0;
}
END_OF_MAIN();

//Função de colisão//
int colisao(int Ax, int Ay, int Bx, int By, int Aw, int Ah, int Bw, int Bh)
{
    if(Ax + Aw > Bx && Ax < Bx + Bw && Ay + Ah > By && Ay < By + Bh)
        return 1;
    return 0;
}

//Função de Controle//
void controle()
{
    if(key[KEY_LEFT]  && nave.x > 2) 				  //Nave sendo direcionada para a esquerda, com maximo de 2 pixels//
        nave.x -= 3;
    if(key[KEY_RIGHT] && nave.x < 705) 				  //Nave sendo direcionada para a esquerda, com maximo de 705 pixels//
        nave.x += 3;
    if(key[KEY_SPACE] && bullet.y > nave.y && !shoot) //Nave atirando//
        shoot = 1;
    if(shoot)										  //Meu tiro se movimentando para cima//
        bullet.y -= 4;                                
    if(bullet.y < height/4)
        shoot = 0;
    if(!shoot)
    {
        bullet.x = nave.x + nave.w/2;
        bullet.y = nave.y + nave.h/2;
    }



}

//Função sair//
void sair()
{
    sai= 1;
}
END_OF_FUNCTION(sair);
