#ifndef MENU_BACKUP_H_INCLUDED
#define MENU_BACKUP_H_INCLUDED

bool Menu_BackUp()
{
    const int ANCHO_MENU = 57;
    const int ALTO_MENU = 10;
    int key, opc, cursorX, cursorY;

        opc=1;
    while(true)
    {

        cursorX=POSMENUX+1;
        cursorY=POSMENUY + 3;
        setBackgroundColor(COLOR_PANTALLA);
        cls();
        setColor(LETRA);
        setBackgroundColor(FONDO);
        recuadro(16,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
        separadorH(POSMENUX-17,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);

        locate(POSMENUX+5,POSMENUY+1);
        cout << "MENU DE BACKUP";
        locate(POSMENUX-13,POSMENUY+3);
        cout << "1. HACER COPIA DE SEGURIDAD DEL ARCHIVO DE ARTICULOS";
        locate(POSMENUX-13,POSMENUY+4);
        cout << "2. HACER COPIA DE SEGURIDAD DEL ARCHIVO DE CLIENTES";
        locate(POSMENUX-13,POSMENUY+5);
        cout << "3. HACER COPIA DE SEGURIDAD DEL ARCHIVO DE VENTAS";
        locate(POSMENUX-13,POSMENUY+6);
        cout << "4. RESTAURAR EL ARCHIVO DE ARTICULOS";
        locate(POSMENUX-13,POSMENUY+7);
        cout << "5. RESTAURAR EL ARCHIVO DE CLIENTES";
        locate(POSMENUX-13,POSMENUY+8);
        cout << "6. RESTAURAR EL ARCHIVO DE VENTAS";
        locate(POSMENUX-13,POSMENUY+9);
        cout << "0. MENU PRINCIPAL";
        hidecursor();
             cursorY = opc + POSMENUY + 2;
      locate(cursorX-=16,cursorY);
      cout<<">";
        busqBackup(opc, 7);

        key = getkey();
        while(key != KEY_ENTER)
        {
            locate(cursorX,cursorY);
            cout<<" ";
            switch(key)
            {
            case KEY_DOWN:
                if(opc < 7)
                {
            locate(cursorX,cursorY);
            cout<<" ";
                    opc++;
                }
                else
                {
                    opc=1;
                }
                break;
            case KEY_UP:
                if(opc > 1)
                {
            locate(cursorX,cursorY);
            cout<<" ";
                    opc--;
                }
                else
                {
                    opc=7;
                }
                break;
            }
            if(opc != 0)
            {
                cursorY = opc + POSMENUY +2;
            }
            else
            {
                cursorY = POSMENUY + 6;
            }
            locate(cursorX,cursorY);
            cout<<">";
            busqBackup(opc, 7);
            key = getkey();
        }
        setBackgroundColor(COLOR_PANTALLA);
        cls();
        showcursor();
        switch(opc)
        {
        case 1:
            if(hacerBackupArticulo()==false)
            {
                cout<<"ERROR DE BACKUP"<<endl;
            }
            else
            {
            recuadro(POSMENUX-7,POSMENUY-4, 40,2,LETRA,FONDO);
    locate(POSMENUX+2,POSMENUY-3);
                cout<<"BACKUP REALIZADO"<<endl;
            }
            break;
        case 2:
            if(hacerBackupCliente()==false)
            {
                cout<<"ERROR DE BACKUP"<<endl;
            }
            else
            {
        recuadro(POSMENUX-7,POSMENUY, 40,2,LETRA,FONDO);
    locate(POSMENUX+2,POSMENUY+1);
                cout<<"BACKUP REALIZADO"<<endl;
            }
            break;
        case 3:
            if(hacerBackupVenta()==false)
            {
                cout<<"ERROR DE BACKUP"<<endl;
            }
            else
            {
        recuadro(POSMENUX-7,POSMENUY, 40,2,LETRA,FONDO);
    locate(POSMENUX+2,POSMENUY+1);
                cout<<"BACKUP REALIZADO"<<endl;
            }
            break;
        case 4:
            if(Restaura_Arti()==false)
            {
                cout<<"ERROR DE ARCHIVO"<<endl;
            }
            else
            {
        recuadro(POSMENUX-7,POSMENUY, 40,2,LETRA,FONDO);
    locate(POSMENUX+2,POSMENUY+1);
                cout<<"RESTAURACION REALIZADA"<<endl;
            }
            break;
        case 5:
            if(Restaura_Cliente()==false)
            {
                cout<<"ERROR DE ARCHIVO"<<endl;
            }
            else
            {
        recuadro(POSMENUX-7,POSMENUY, 40,2,LETRA,FONDO);
    locate(POSMENUX+2,POSMENUY+1);
                cout<<"RESTAURACION REALIZADA"<<endl;
            }
            break;
        case 6:
            if(Restaura_Venta()==false)
            {
                cout<<"ERROR DE ARCHIVO"<<endl;
            }
            else
            {
        recuadro(POSMENUX-7,POSMENUY, 40,2,LETRA,FONDO);
    locate(POSMENUX+2,POSMENUY+1);
                cout<<"RESTAURACION REALIZADA"<<endl;
            }
            break;
        case 7:
            return 0;
            break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
            break;
        }
        system("pause > nul");
    }
}


#endif // MENU_BACKUP_H_INCLUDED
