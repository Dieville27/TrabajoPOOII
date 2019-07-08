#include <iostream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include "string.h"
//Encabezado adicional para el uso de imágenes
#include <allegro5/allegro_image.h>

 // Atributos de la pantalla
 #define LARGO_PANTALLA 800
 #define ALTURA_PANTALLA 530


using namespace std;

void error_msg(char *text) {
al_show_native_message_box(NULL,"ERROR",
"Ocurrió el siguiente error y el programa terminará:",
text,NULL,ALLEGRO_MESSAGEBOX_ERROR);
 }




 int main(void){
     ALLEGRO_DISPLAY *pantalla = NULL;
     ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
     ALLEGRO_BITMAP *boton_salir = NULL,*area_central = 0, *area_derecha = 0;


     // Flag que condicionará el bucle
     int sair = 0;

     if (!al_init()){
         error_msg("Falla al inicializar Allegro");
         return -1;
     }

     pantalla = al_create_display(LARGO_PANTALLA,ALTURA_PANTALLA);
     if (!pantalla){
         error_msg("Falla al crear la pantalla");
         return -1;
     }

al_init();

    // Configura el titulo de la ventana
     al_set_window_title(pantalla, "Juego de ludo creado por Salvador, Ali, Diego");




     // Habilita el uso del mouse en la aplicación.
     if (!al_install_mouse()){
         error_msg("Falla al inicializar el mouse");
         al_destroy_display(pantalla);
         return -1;
     }

     // Asigna el cursor predeterminado del sistema para ser usado
     if (!al_set_system_mouse_cursor(pantalla, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)){
         error_msg("Error al asignar el puntero del mouse");
         al_destroy_display(pantalla);
         return -1;
     }
al_init_image_addon();//Revisará si hay errores


    ALLEGRO_BITMAP* imagen1 = al_load_bitmap("FONDO1.bmp");
    ALLEGRO_BITMAP* imagen2 = al_load_bitmap("FONDO2.bmp");
    ALLEGRO_BITMAP* imagen3 = al_load_bitmap("FONDO3.bmp");

     // // Asignar el izquierdo central de la pantalla
     area_central = imagen2; //320, 50
     if (!area_central){
         error_msg("Falla al crear el bitmap");
         al_destroy_display(pantalla);
         return -1;
     }

     // // Configuramos el botón para cerrar la aplicación.
      area_derecha = imagen3;
     if (!area_derecha){
         error_msg("Falla al crear el bitmap");
         al_destroy_display(pantalla);
         return -1;
     }

     boton_salir = imagen1; //163, 55
     if (!boton_salir){
         error_msg("Error al crear el boton de salida");
        // al_destroy_bitmap(area_central);
         al_destroy_display(pantalla);
         return -1;
     }

     fila_eventos = al_create_event_queue();
     if (!fila_eventos){
         error_msg("Falha ao inicializar o fila de eventos");
         al_destroy_display(pantalla);
         return -1;
     }

     // Decimos que vamos a manejar los eventos que vienen del mouse
     al_register_event_source(fila_eventos, al_get_mouse_event_source());




     // Bandera que indica si el mouse esta posicionado sobre el rectangulo
     int na_area_central = 0;
     int na_area_derecha = 0;



     while (!sair){

         // Verificar eventos en cola
         while (!al_is_event_queue_empty(fila_eventos)){
             ALLEGRO_EVENT evento;
             al_wait_for_event(fila_eventos, &evento);

             // Si el evento fue movimiento del mouse
             if (evento.type == ALLEGRO_EVENT_MOUSE_AXES){

                 // Verificamos si está sobre la región del rectángulo central
                 if (evento.mouse.x >= 80 && evento.mouse.x <= 396 && evento.mouse.y >= 418 && evento.mouse.y <= 478){
                     na_area_central = 1;
                 }
                 else{
                     na_area_central = 0;
                 }
             }


             if (evento.type == ALLEGRO_EVENT_MOUSE_AXES){

                 if (evento.mouse.x >= 530 && evento.mouse.x <= 690 && evento.mouse.y >= 410 && evento.mouse.y <= 476){
                     na_area_derecha = 1;
                 }
                 else{
                     na_area_derecha = 0;
                 }
             }

//O si el evento fue un click del mouse
         if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                 if (evento.mouse.x >=530 &&
                 evento.mouse.x <= 690 &&
                 evento.mouse.y >= 410 && evento.mouse.y<=475 )

                    {


                     sair = 1;


                     }


         }


}

         // Colorea el mapa de bits correspondiente al centro del rectángulo,
         // con el color condicionado al contenido de la bandera na_area_central

 al_set_target_bitmap(area_central);
         if (!na_area_central){
            al_set_target_bitmap(al_get_backbuffer(pantalla));
              al_draw_bitmap(imagen1,0,0,0);
         }
         else{
             al_set_target_bitmap(al_get_backbuffer(pantalla));
              al_draw_bitmap(imagen2,0,0,0);


         }



         // Coloreo del bitmap de salida

al_set_target_bitmap(area_derecha);
         if (!na_area_derecha){
            al_set_target_bitmap(al_get_backbuffer(pantalla));
              al_draw_bitmap(imagen1,0,0,0);
         }
         else{
             al_set_target_bitmap(al_get_backbuffer(pantalla));
              al_draw_bitmap(imagen3,0,0,0);


         }





         // Actualizar la pantalla
         al_flip_display();



}



     // Desaloca os recursos utilizados na aplicação

     al_destroy_bitmap(boton_salir);
     al_destroy_bitmap(area_central);
     al_destroy_bitmap(area_derecha);
     al_destroy_display(pantalla);
     al_destroy_event_queue(fila_eventos);



     return 0;
 }
