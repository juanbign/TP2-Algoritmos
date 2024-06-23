"asistente.h"

Funciones útiles para consultas a la base de datos

    /**
    * pre: 
    * post: Devuelve el número maxímo de líneas de colectivo posibles (195 por defecto)
    */
    const int obtenerMaximoNumLineaColectivo();

    /**
    * pre: 
    * post: Devuelve una lista de la cantidad de paradas de colectivo en todos los barrios
    */
    Lista<int>* obtenerCantidadParadasPorBarrio(Lista<Barrio*>* barrios);

    /**
    * pre: 
    * post: Devuelve una lista de las paradas de un colectivo en todos los barrios 
    */
    Lista<Parada*>* obtenerParadasDeColectivo(Lista<Barrio*>* barrios, int colectivo);

    /**
    * pre: 
    * post: Devuelve una lista de la cantidad de paradas de todos los colectivos en todos los barrios 
    */
    Lista<int>* obtenerCantidadParadasPorColectivo(Lista<Barrio*>* barrios);

    /**
    * pre: 
    * post: Devuelve la parada más cercana a una coordenada  
    */
    Parada* obtenerParadaMasCercana(Lista<Barrio*>* barrios, long double lat, long double lon);

    /**
    * pre: 
    * post: Devuelve una lista de todas las paradas de un colectivo en un barrio, ordenadas por distancia de una coordenada 
    */
    Lista<Parada*>* obtenerParadasOrdenadasPorDistancia(Barrio* barrio, int colectivo, long double lat, long double lon);

"barrio.h"

Clase dedicada a agrupar paradas bajo el nombre de un barrio

    /**
    * pre: 
    * post: Devuelve un barrio sin paradas y el nombre especificado
    */
    Barrio(std::string nombre);
    
    /**
    * pre: 
    * post: Devuelve un barrio sin paradas y nombre vacío
    */
    Barrio();

    /**
    * pre: 
    * post: Devuelve el nombre del barrio
    */
    std::string obtenerNombre();

    /**
    * pre: 
    * post: Cambia el nombre del barrio
    */
    void cambiarNombre(std::string nombre);

    /**
    * pre: 
    * post: Devuelve la parada en la posición indicada de la lista de paradas del barrio
    */
    Parada* obtenerParada(int posicion);

    /**
    * pre: 
    * post: Agrega una parada a la lista de paradas del barrio
    */
    void agregarParada(Parada* parada);
    
    /**
    * pre: 
    * post: Devuelve la cantidad de paradas en la lista de paradas del barrio
    */
    int contarParadas();

    /**
    * pre: 
    * post: Devuelve true si no hay paradas en la lista de paradas del barrio 
    */
    bool estaVacio();

    /**
    * pre: 
    * post: Cambia la parada en la posición indicada de la lista de paradas del barrio
    */
    void asignarParada(Parada* parada, int posicion);
    
    /**
    * pre: 
    * post: Remueve la parada en la posición indicada de la lista de paradas del barrio
    */
    void removerParada(int posicion);

"lectura.h"

Funciones útiles para leer y procesar la base de datos de paradas

    /**
    * pre: El string pasado debe ser la dirección + nombre de un archivo csv ("C:/Documentos/archivo.csv") con el formato indicado en el manual de programador
    * post: Devuelve una lista de barrios con paradas, basado en el csv pasado por parámetro
    */
    Lista<Barrio*>* leerArchivo(std::string archivo);

"lista.h"

Clase dedicada a agrupar variables del mismo tipo en una lista

    /**
	 * pre:
	 * pos: crea una lista vacia
	 */
	Lista();

	/**
	 * pre:
	 * pos: indica si la Lista tiene algún elemento.
	 */
	bool estaVacia();

    /*
	 * post: devuelve la cantidad de elementos que tiene la Lista.
	 */
	int getTamanio();

	/**
	 * pre: -
	 * pos: agrega el elemento al final de la Lista, en la posición:
     *       contarElementos() + 1.
	 */
	void agregar(T elemento);

	void agregarAlInicio(T elemento);

	/**
	 * pre: posición pertenece al intervalo: [1, contarElementos() + 1]
	 * pos: agrega el elemento en la posición indicada.
	 */
	void agregar(T elemento, int posicion);

    /*
     * pre : posición pertenece al intervalo: [1, contarElementos()]
     * post: remueve de la Lista el elemento en la posición indicada.
     */
	void remover(int posicion);

	/**
	 * pre : posición pertenece al intervalo: [1, contarElementos()]
	 * pos: devuelve el dato de la posicion
	 */
	T obtener(int posicion);

	/**
	 * pre : posición pertenece al intervalo: [1, contarElementos()]
	 * pos: cambia el elemento de la posicion
	 */
	void cambiar(T elemento, int posicion);

    /*
	 * post: deja el cursor de la Lista preparado para hacer un nuevo
	 *       recorrido sobre sus elementos.
	 */
	void iniciarCursor();

	/*
	 * pre : se ha iniciado un recorrido (invocando el método
	 *       iniciarCursor()) y desde entonces no se han agregado o
	 *       removido elementos de la Lista.
	 * post: mueve el cursor y lo posiciona en el siguiente elemento
	 *       del recorrido.
	 *       El valor de retorno indica si el cursor quedó posicionado
	 *       sobre un elemento o no (en caso de que la Lista esté vacía o
	 *       no existan más elementos por recorrer.)
	 */
	bool avanzarCursor();

	/*
	 * pre : el cursor está posicionado sobre un elemento de la Lista,
	 *       (fue invocado el método avanzarCursor() y devolvió true)
	 * post: devuelve el elemento en la posición del cursor.
	 *
	 */
	T obtenerCursor();

"menu.h"

Clase dedicada a 

    /**
    * pre:
    * post: Crea una lista de los nombres de los barrios
    */
    Menu(Lista<Barrio*>* barrios);

    /**
    * pre: 
    * post: Muestra el menú y pide una entrada. Termina su ejecución cuando el usuario indica que quiere salir.
    */
    void mostrarMenu();

"nodo.h"

Clase dedicada a guardar elementos de la clase lista

    /**
	 * pre: -
	 * pos: el Nodo resulta inicializado con el dato dado
     *       y sin un Nodo siguiente.
	 */
	Nodo(T dato);

	/**
	 * pre:
	 * pos: devuelve el dato del nodo
	 */
	T getDato();

	/**
	 * pre:
	 * pos: cambia el dato del nodo
	 */
	void setDato(T dato);

	/**
	 * pre:
	 * pos: devuelve el siguiente nodo
	 */
	Nodo<T>* getSiguiente();

	/**
	 * pre:
	 * pos: cambia el nodo siguiente
	 */
	void setSiguiente(Nodo<T>* siguiente);

"parada.h"

Clase dedicada a guardar identificar paradas con su dirección, línea de colectivo, y coordenadas

    /**
    * pre: El número del colectivo debe ser mayor o igual a 1 
    * post: Devuelve una parada con las propiedades indicadas
    */
    Parada(std::string direccion, int colectivo, long double lat, long double lon);

    /**
    * pre: 
    * post: Devuelve una parada genérica (dirección: "", colectivo: 0, lat: 0, lon: 0)
            (compatibilidad con clase nodo)
    
    */
    Parada();

    /**
    * pre: 
    * post: Devuelve la dirección de la parada
    */
    std::string obtenerDireccion();

    /**
    * pre: 
    * post: Devuelve el número de la línea de colectivo de la parada
    */
    int obtenerColectivo();

    /**
    * pre: 
    * post: Devuelve la coordenada latitud de la parada
    */
    long double obtenerLatitud();

    /**
    * pre: 
    * post: Devuelve la coordenada longitud de la parada
    */
    long double obtenerLongitud();

    /**
    * pre: 
    * post: Cambia la dirección de la parada
    */
    void cambiarDireccion(std::string direccion);

    /**
    * pre: El número del colectivo debe ser mayor o igual a 1
    * post: Cambia el número del colectivo de la parada
    */
    void cambiarColectivo(int colectivo);

    /**
    * pre: 
    * post: Cambia la coordenada latitud de la parada
    */
    void cambarLatitud(long double lat);

    /**
    * pre: 
    * post: Cambia la coordenada longitud de la parada
    */
    void cambiarLongitud(long double lon);


Todas las clases se encargan de su propia alocación de memoria, excepto Menu, quien es instanciada por el desarrollador
Cuando no tenga que usar más el menú, borre el espacio que toma en la memoria

"paradas-de-colectivo.csv"

Demostración del formato necesario para la función "leerArchivo" de la "lectura.h"

CALLE,ALT PLANO,DIRECCION,coord_X,coord_Y,COMUNA,BARRIO,L1,l1_sen,L2,l2_sen,L3,l3_sen,L4,l4_sen,L5,l5_sen,L6,l6_sen
SAN MARTIN AV.,"2811",2811 SAN MARTIN AV.,-58.465563,-34.602645,"15",PATERNAL,"24",V,"57",I,"105",I,"109",V,"135",V,"146",I