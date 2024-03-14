#ifndef MENU_ARTICULO_H_INCLUDED
#define MENU_ARTICULO_H_INCLUDED

bool Menu_Arti()
{
    const int ANCHO_MENU = 33;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;

      opc=1;
while(true){

      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 3;
     setBackgroundColor(COLOR_PANTALLA);
      cls();

      setColor(LETRA);
      setBackgroundColor(FONDO);

      recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU+1,LETRA,FONDO);
      separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);

      locate(POSMENUX+11,POSMENUY+1);
      cout << "MENU ARTICULO";
      locate(POSMENUX+3,POSMENUY+3);
      cout << "1. AGREGAR ARTICULOS";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "2. LISTAR ARTICULO POR ID";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "3. LISTAR TODOS LOS ARTICULOS";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "4. MODIFICAR PRECIO";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "5. BAJA LOGICA";
      locate(POSMENUX+3,POSMENUY+8);
      cout << "0. VOLVER AL MENU PRINCIPAL";
      hidecursor();
     cursorY = opc + POSMENUY + 2;
      locate(cursorX,cursorY);
      cout<<">";
              busqArticulo(opc, 5);

      key = getkey();
      while(key != KEY_ENTER){

        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){

        case KEY_DOWN:
            if(opc < 5){
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
                opc=5;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 8;
        }
        locate(cursorX,cursorY);
        cout<<">";
        busqArticulo(opc, 5);
        key = getkey();
      }
     setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1:
            	if(Agregar_Articulo()==false)
            	{
                recuadro(20,POSMENUY, 40,2,LETRA,FONDO);
            	    locate(21,11);
                	cout<<endl;
                	cout<<"ERROR DE ARCHIVO                      "<<endl;
            	}
            	else{
                    recuadro(20,11, 40,2,LETRA,FONDO);
            	    locate(32,12);
                	cout<<"REGISTRO GUARDADO";
            	}
            	system("pause > nul");
                break;
        case 2:
		if(Listar_Articulos_ID()==false)
            	{
            	    recuadro(20,POSMENUY, 40,2,LETRA,FONDO);
            	    locate(26,11);
                	cout<<"ERROR DE LECTURA ARCHIVO"<<endl;
            	}
            	      system("pause > nul");
                break;
        case 3:
		if(Listar_Articulos()==false)
            	{
            	    recuadro(20,POSMENUY, 40,2,LETRA,FONDO);
            	    locate(21,11);
                	cout<<"ERROR DE LECTURA ARCIVO                "<<endl;
            	}
                        system("pause > nul");
                break;
        case 4:
		if(Modificar_Precio()==false)
            	{
                recuadro(36,POSMENUY+4, 25,2,LETRA,FONDO);
            	    locate(37, POSMENUY+5);
                	cout<<"ERROR DE LECTURA ARCHIVO"<<endl;
            	}
            	else
            	{
                recuadro(38,POSMENUY+4, 20,2,LETRA,FONDO);
            	    locate(40, POSMENUY+5);
                	cout<<"REGISTRO CAMBIADO"<<endl;
            	}
               system("pause > nul");
                break;
	case 5:
		if(Baja_Logica()==-1&&Baja_Logica()==-2)
            	{
                	recuadro(20,POSMENUY, 40,2,LETRA,FONDO);
            	    locate(21,11);
                	cout<<"ERROR DE BAJA LOGICA                    "<<endl;
            	}
            	else
            	{
                	recuadro(23,POSMENUY, 40,2,LETRA,FONDO);
            	    locate(24,11);
                	cout<<"BAJA LOGICA REALIZADA"<<endl;
            	}
            system("pause > nul");
		break;
        case 0: return 0;
              system("pause > nul");
                break;
        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }

      cls();
    }
}


#endif // MENU_ARTICULO_H_INCLUDED
