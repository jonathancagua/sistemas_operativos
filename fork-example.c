/**
 * @file fork-example.c
 * @author Jonathan
 * @brief uso de fork:
 * Fork(). Proceso padre, hijo, huerfano , zombie
 * -pid_t for(void)
 *  Crea un nuevo proceso "hijo"
 *  el proceso hijo es un duplicado del proceso "padre"
 *  Los dos procesos tienen PIDs diferentes y corren en 
 *  direcciones de memoraia diferentes.
 *  retorna: 
 *      - en el proceso padre retorna el PID del hijo
 *      - retorna 0 en el proceso hijo
 *      - Si existe un error retorna -1, eso significa 
 *          que el hijo no fue creado
 * @version 0.1
 * @date 2021-11-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

