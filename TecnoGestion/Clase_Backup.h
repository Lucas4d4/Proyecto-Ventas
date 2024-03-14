#ifndef CLASE_BACKUP_H_INCLUDED
#define CLASE_BACKUP_H_INCLUDED

class Backup
{
private:
    Articulo art;
    Cliente cli;
    Venta_Principal vent;
public:
    ///sets()
    void setart(Articulo a)
    {
        art=a;
    }
    void setcli(Cliente c)
    {
        cli=c;
    }
    void setvent(Venta_Principal v)
    {
        vent=v;
    }
    ///gets()
    Articulo getart()
    {
        return art;
    }
    Cliente getcli()
    {
        return cli;
    }
    Venta_Principal getvent()
    {
        return vent;
    }
    ///Prototipos
    bool leerdeDisco(int);
};

bool Backup::leerdeDisco(int pos)
{
    FILE *pBackup;
    pBackup=fopen("articulo.bkp", "rb");

    if(pBackup==NULL)
    {
        return false;
    }
    fseek(pBackup, pos*sizeof(Backup), 0);
    bool leyo=fread(this,sizeof(Backup),1,pBackup);

    fclose(pBackup);
    return leyo;
}


void mostrarArchivoBackup()
{
    FILE *p;
    Articulo reg;
    int c=0;
    p=fopen("articulo.bkp","rb");
    if(p==NULL) return;

    while(fread(&reg, sizeof reg, 1, p)==1)
    {
        c++;
        reg.Mostrar(c);
        system("pause > nul");
    }
    setBackgroundColor(COLOR_PANTALLA);
    cls();
    fclose(p);
}

bool hacerBackupArticulo()
{
    FILE *p;
    Articulo aux;
    int pos=0;
    p=fopen("articulo.bkp","wb");
    if(p==NULL) return false;

    while(aux.leerdeDisco(pos++)==1)
    {
        fwrite(&aux, sizeof aux, 1,p);
    }

    fclose(p);
    mostrarArchivoBackup();
    return true;
}

void mostrarArchivoBackupCliente()
{
    FILE *p;
    Cliente reg;
    int c=0;
    p=fopen("cliente.bkp","rb");
    if(p==NULL) return;

    while(fread(&reg, sizeof reg, 1, p)==1)
    {
                c++;
        if(c>1){
            c=c+5;
        }
        reg.Mostrar(c);
        system("pause > nul");
    }
    setBackgroundColor(COLOR_PANTALLA);
    cls();
    fclose(p);
}

bool hacerBackupCliente()
{
    FILE *p;
    Cliente aux;
    int pos=0;
    p=fopen("cliente.bkp","wb");
    if(p==NULL) return false;

    while(aux.leerdeDisco(pos++)==1)
    {
        fwrite(&aux, sizeof aux, 1,p);
    }
    fclose(p);

    mostrarArchivoBackupCliente();

    return true;
}

void mostrarArchivoBackupVenta()
{
    FILE *p;
    Venta_Principal reg;
    p=fopen("venta.bkp","rb");
    if(p==NULL) return;

    while(fread(&reg, sizeof reg, 1, p)==1)
    {
        reg.Mostrar();
        system("pause > nul");
    }
    setBackgroundColor(COLOR_PANTALLA);
    cls();
    fclose(p);
}

bool hacerBackupVenta()
{
    FILE *p, *p2;
    Venta_Principal aux;
    Venta_Detalle aux2;
    int pos=0, pos2;
    p=fopen("ventaPrincipal.bkp","wb");
    p2=fopen("ventaDetalle.bkp", "wb");
    if(p==NULL) return false;
    if(p2==NULL) return false;
    while(aux.leerdeDisco(pos++)==1)
    {
        fwrite(&aux, sizeof aux, 1,p);
    }
    pos2=0;
    while(aux2.leerdeDisco(pos2++)==1)
    {
        fwrite(&aux2, sizeof aux2, 1,p2);
    }

    fclose(p);
    fclose(p2);

    return true;
}

bool Restaura_Arti()
{
    FILE *p, *pb;
    Articulo reg;
    int c=0;
    p=fopen("articulo.bkp","rb+");
    pb=fopen("articulo.lgg", "wb");
    if(p==NULL) return false;

    while(fread(&reg, sizeof reg, 1, p)==1)
    {
        c++;
        fwrite(&reg, sizeof reg, 1, pb);
    }
    recuadro(POSMENUX-7,POSMENUY-3, 40,2,LETRA,FONDO);
    locate(POSMENUX+4,POSMENUY-2);
    cout<<"REGISTROS: "<<c<<endl;
    fclose(p);
    fclose(pb);
    return true;
}

bool Restaura_Cliente()
{
    FILE *p, *pb;
    Cliente reg;
    int c=0;
    p=fopen("cliente.bkp","rb+");
    pb=fopen("cliente.lgg", "wb");
    if(p==NULL) return false;

    while(fread(&reg, sizeof reg, 1, p)==1)
    {
        c++;
        fwrite(&reg, sizeof reg, 1, pb);
    }
        recuadro(POSMENUX-7,POSMENUY-3, 40,2,LETRA,FONDO);
    locate(POSMENUX+4,POSMENUY-2);
    cout<<"REGISTROS: "<<c<<endl;
    fclose(p);
    fclose(pb);
    return true;
}


bool Restaura_Venta()
{
    FILE *p, *pb, *pc, *pd;
    Venta_Principal reg;
    Venta_Detalle reg2;
    int c=0, c2=0;
    p=fopen("ventaPrincipal.bkp","rb+");
    pb=fopen("ventaPrincipal.lgg", "wb");
    pc=fopen("ventaDetalle.bkp", "rb+");
    pd=fopen("ventaDetalle.lgg", "wb");
    if(p==NULL) return false;
if(pb==NULL) return false;
if(pc==NULL) return false;
if(pd==NULL) return false;
    while(fread(&reg, sizeof reg, 1, p)==1)
    {
        c++;
        fwrite(&reg, sizeof reg, 1, pb);
    }
    recuadro(POSMENUX-7,POSMENUY-3, 40,2,LETRA,FONDO);
    locate(POSMENUX+4,POSMENUY-2);
    cout<<"REGISTROS: "<<c<<endl;
    while(fread(&reg2, sizeof reg2, 1, pc)==1)
    {
        c2++;
        fwrite(&reg2, sizeof reg2, 1, pd);
    }
    recuadro(POSMENUX-7,POSMENUY-6, 40,2,LETRA,FONDO);
    locate(POSMENUX+4,POSMENUY-2);
    cout<<"REGISTROS: "<<c2<<endl;
    fclose(p);
    fclose(pb);
    fclose(pc);
    fclose(pd);
    return true;
}


#endif // CLASE_BACKUP_H_INCLUDED
