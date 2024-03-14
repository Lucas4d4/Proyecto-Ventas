#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include "rlutil.h"
/**
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
**/

using namespace std;
using namespace rlutil;


const int POSMENUX = 33;
const int POSMENUY = 10;
const int COLOR_PANTALLA = BLUE;
const int LETRA = WHITE;
const int FONDO = GREEN;
#include "Presentacion.h"
#include "utilidades.h"

///PARTE CLASE
#include "Clase_Articulo.h"
#include "Clase_Cliente.h"
#include "Clase_Venta.h"
#include "Clase_Backup.h"
///PARTE MENU
#include "Menu_Articulo.h"
#include "Menu_Cliente.h"
#include "Menu_Venta.h"
#include "Menu_Backup.h"

int main()
{
 int key, opc, cursorX, cursorY;
 rlutil::hidecursor();
      opc=1;
       AjustarVentana(50,50);
       cursorX=POSMENUX+1;
      cursorY=POSMENUY + 3;
      setBackgroundColor(COLOR_PANTALLA);
      setColor(WHITE);
      cls();


int ent;
/**
Marco2(89);
Objetivo(89);
Objetivo2(89);
Nombres(89);
///Nombres(80);
Continuar(89);
system("pause > nul");
**/
     setlocale(LC_ALL, "spanish");
    setConsoleTitle("TecnoGestion");
    const int ANCHO_MENU = 23;
    const int ALTO_MENU = 8;


while(true){

      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 3;
      setBackgroundColor(COLOR_PANTALLA);
      cls();

      setColor(LETRA);
      setBackgroundColor(FONDO);

      recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
      separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);

      locate(POSMENUX+5,POSMENUY+1);
      cout << "MENÚ PRINCIPAL";
      locate(POSMENUX+3,POSMENUY+3);
      cout << "1. ARTICULOS";
      locate(POSMENUX+3,POSMENUY+4);

      cout << "2. CLIENTES";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "3. VENTAS";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "4. BACKUP";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "0. FIN DEL PROGRAMA";
      hidecursor();
           cursorY = opc + POSMENUY + 2;
      locate(cursorX,cursorY);
      cout<<">";
        busq(opc, 4);
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 4){
        locate(cursorX,cursorY);
        cout<<" ";
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
            locate(cursorX,cursorY);
        cout<<" ";
                opc--;
            }else{
                opc=4;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 7;
        }
        locate(cursorX,cursorY);
        cout<<">";
        busq(opc, 4);
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1: Menu_Arti();
                break;
        case 2: Menu_Clien();
                break;
        case 3: Menu_VentaCabecera();
                break;
        case 4: Menu_BackUp();
                break;
        case 0: return false;
                break;

      }

    }
    return 0;
}
