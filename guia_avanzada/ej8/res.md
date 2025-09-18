char* str1 apunta a el dato "Hola", que sólo se puede leer tiene tamaño fijo

char str2[] apunta a un array que sizeof(char) * cantDeElems("Hola") memoria reservada (en este caso, 1 * 5 = 4 bytes, recordemos que los str terminan con el char \n), se pueden modificar las posiciones.