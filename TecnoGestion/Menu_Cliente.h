#ifndef MENU_CLIENTE_H_INCLUDED
#define MENU_CLIENTE_H_INCLUDED

bool Menu_Clien()
{
    const int ANCHO_MENU = 33;
    const int ALTO_MENU = 9;
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
      cout << "MENU CLIENTE";
      locate(POSMENUX+3,POSMENUY+3);
      cout << "1. AGREGAR CLIENTE";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "2. LISTAR CLIENTE POR DNI";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "3. LISTAR TODOS LOS CLIENTES";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "4. MODIFICAR EMAIL";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "5. ELIMINAR CLIENTE";
      locate(POSMENUX+3,POSMENUY+8);
      cout << "0. VOLVER AL MENU PRINCIPAL";
      hidecursor();
     cursorY = opc + POSMENUY + 2;
      locate(cursorX,cursorY);
      cout<<">";
        busqCliente(opc, 5);
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
        busqCliente(opc, 5);
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1:
            	if(Grabar_Cliente()==false)
            {
                cout<<"ERROR DE ARCHIVO"<<endl;
            }
            else
            {
                recuadro(POSMENUX,POSMENUY, 20,2,LETRA,FONDO);
                locate(POSMENUX+1,POSMENUY+1);
                cout<<"REGISTRO GRABADO"<<endl;
            }
                  system("pause > nul");
                break;
        case 2:
		       if(Listar_porDNI()==false)
            {
                    recuadro(20,POSMENUY, 40,2,LETRA,FONDO);
            	    locate(26,11);
                cout<<"ERROR DE LECTURA ARCHIVO"<<endl;
            }
              system("pause > nul");
                break;
        case 3:
		        if(Listar_Cliente()==false)
            {
                cout<<"ERROR DE ARCHIVO"<<endl;
            }
                break;
        case 4:
		        if(Modificar_Email()==false)
            {
                recuadro(POSMENUX,POSMENUY+4, 20,2,LETRA,FONDO);
                locate(POSMENUX+2,POSMENUY+5);
                cout<<"ERROR DE ARCHIVO"<<endl;
            }
            else{
                recuadro(POSMENUX,POSMENUY+4, 20,2,LETRA,FONDO);
                locate(POSMENUX+2,POSMENUY+5);
                cout<<"CAMBIO REALIZADO"<<endl;
            }
                  system("pause > nul");
                break;
	case 5:
		        if(Bajas_Logica()==-1&&Bajas_Logica()==-2)
            {
                cout<<"ERROR DE BAJA LOGICA"<<endl;
            }
            else
            {

    recuadro(POSMENUX-7,POSMENUY, 50,2,LETRA,FONDO);
    locate(POSMENUX-6,POSMENUY+1);
                cout<<"BAJA LOGICA REALIZADO"<<endl;
            }
              system("pause > nul");
		break;
        case 0: return 0;
                break;
        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }

    }
}


#endif // MENU_CLIENTE_H_INCLUDED
