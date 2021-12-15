/**
 * \file boolean.h
 * \brief ADT for managing the Boolean type
 * \author Andries Alexandre s196948
 * \author Khaliphi Abdelilah s204896
 * \version 0.1
 * \date 10/11/2021
 *
 * Presents a boolean as an abstract data type
 */

/*----------------------------------------------------------------------------*/
/*--------------------------------INCLUDE GUARD-------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef __BOOLEAN__
#define __BOOLEAN__
/*----------------------------------------------------------------------------*/
/*----------------------------STRUCTURES DE DONNEES---------------------------*/
/*----------------------------------------------------------------------------*/
/**
 * \struct Boolean
 * \brief Data structure representing a boolean.
 */
typedef enum{
    False,
    True
}Boolean;
/*----------------------------------------------------------------------------*/
/*----------------------------FONCTIONS & PROCEDURES--------------------------*/
/*----------------------------------------------------------------------------*/
/**
 * \fn Boolean and(Boolean x, Boolean y)
 * \brief Performs the logical AND between two booleans.
 *
 * \param x, a boolean.
 * \param y, a boolean.
 *
 * \return A boolean giving the result of x AND Y
 */
Boolean and(Boolean x, Boolean y);

/**
 * \fn Boolean or(Boolean x, Boolean y)
 * \brief Performs the logical OR between two booleans.
 *
 * \param x, a boolean.
 * \param y, a boolean.
 *
 * \return A boolean giving the result of x OR Y.
 */
Boolean or(Boolean x, Boolean y);

/**
 * \fn Boolean not(Boolean x)
 * \brief Performs the logical negation.
 *
 * \param x, a boolean.
 *
 * \return A boolean giving the result of NOT x.
 */
Boolean not(Boolean x);
/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU HEADER-------------------------------*/
/*----------------------------------------------------------------------------*/
#endif // __BOOLEAN__
