#ifndef MENU_VENTA_H_INCLUDED
#define MENU_VENTA_H_INCLUDED

bool Menu_VentaCabecera()
{
    const int ANCHO_MENU = 33;
    const int ALTO_MENU = 6;
    int key, opc, cursorX, cursorY;

opc=1;
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
      cout << "MENU CABECERA";
      locate(POSMENUX+3,POSMENUY+3);
      cout << "1. CARGAR VENTA";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "2. MOSTRAR VENTAS";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "0. MENU PRINCIPAL";
      hidecursor();
     cursorY = opc + POSMENUY + 2;
      locate(cursorX,cursorY);
      cout<<">";
        busqVenta(opc, 3);
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 3){
            locate(cursorX,cursorY);
      cout<<" ";
                opc++;
            }else{
                opc=1;
            }
            break;
        case KEY_UP:
            if(opc > 1){
            locate(cursorX,cursorY);
      cout<<" ";
                opc--;
            }else{
                opc=3;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 4;
        }
        locate(cursorX,cursorY);
        cout<<">";
        busqVenta(opc, 3);
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1:
            	if(Grabar_VentPrincipal()==false)
            {
                recuadro(30,POSMENUY+2, 20,2,LETRA,FONDO);
                locate(30+2, POSMENUY+3);
                cout<<"ERROR DE ARCHIVO"<<endl;
                rlutil::hidecursor();
            }
            else
            {
                recuadro(30,POSMENUY+11, 20,2,LETRA,FONDO);
                locate(30+1, POSMENUY+12);
                cout<<"REGISTRO GUARDADO"<<endl;
            rlutil::hidecursor();
            }
                  system("pause > nul");
                break;
        case 2:
		       ListarTodo();
                break;
        case 3:
                return false;
                break;
        default:cout<<" OPCION INCORRECTA"<<endl;
        break;

      }

    }

}


#endif // MENU_VENTA_H_INCLUDED
