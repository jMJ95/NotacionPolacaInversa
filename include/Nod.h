#ifndef NOD_H
#define NOD_H


class Nod

{
    private:
        int numero;
        int hijos;
        Nod *siguiente;
    public:
        void agregarHijo();
        Nod* getHijos();

        //constructor

        Nod(int numero);

      /*  Nod::Nod(int numero)
        {

        }
       Nodo Nod::getHijos()
        {

        }
        void Nod::agregarHijo()
        {

        }*/
        //destructor
        virtual ~Nod();
        //getter and setters
        //NODO* SIGUIENTE
        void setSiguiente(const Nod*& siguiente)
        {
            //this->siguiente = siguiente;
        }

        const Nod*& getSiguiente() const
        {
           // return siguiente;
        }

        //INT NUMERO
        void setNumero(const int& numero)
        {
           // this->numero = numero;
        }

        const int& getNumero() const
        {
           // return numero;
        }

        //HIJOS

        void setHijos(const int& hijos)
        {
           // this->numero = numero;
        }

        const int& getHijos() const
        {
          //  return hijos;
        }
    protected:


};

#endif // NOD_H
