
#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H

#include <iostream>
const int DEFAULT_MAX_HEALTH = 100;

class HealthPoints {
public:

    /*
     * C'tor of healthPoints object
     *
     * @param maxHealth - The maximum amount of health points a player can have
     * @return -
     *      A new instance of healthPoints
     */
    HealthPoints(const int maxHealth = DEFAULT_MAX_HEALTH);

    /*
     * Addition assignment operator of HealthPoints class
     *
     * @param points - Number of points to be added to the current HealthPoints object
     * @return -
     *      A reference to the HealthPoints object
     */
    HealthPoints& operator+=(const int points);


    HealthPoints(const HealthPoints&) = default;
    ~HealthPoints() = default;
    HealthPoints& operator=(const HealthPoints& other) = default;

    /*
     * Subtraction assignment operator of HealthPoints class
     *
     * @param points - Number of points to be decreased from the current HealthPoints object
     * @return -
     *      A reference to the HealthPoints object
     */
    HealthPoints& operator-=(const int points);

    /*
     * Equality operator of HealthPoints class
     *
     * @param current - Reference to the current HealthPoints object being compared
     * @param other - Reference to HealthPoints object to be compared with
     * @ return
     *      True if objects are equal, False if different
     */
    friend bool operator==(const HealthPoints& current, const HealthPoints& other);

    /*
     * Lesser-than operator of HealthPoints class
     *
     * @param current - Reference to the current HealthPoints object being compared
     * @param other - Reference to HealthPoints object to be compared with
     * @ return
     *      True if the value of health of the current object is lesser than the other's,
     *      False otherwise.
     */
    friend bool operator<(const HealthPoints& current, const HealthPoints& other);
    /*
    * Addition operator of HealthPoints class in case that the int added is on the left
    *
    * @param current - Reference to the first HealthPoints object that's being added
    * @param points - Amount of health points to be added to the HealthPoints object
    * @return -
    *      The object with the sum of the received HealthPoints objects
    */
    HealthPoints operator+(const int points);

    /*
     * Output operator of HealthPoints class
     *
     * @param os - Reference to an ostream type cout
     * @param current - Reference to the HealthPoints object being printed
     * @return
     *      Reference to an instance of ostream
     */
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& current);

    class InvalidArgument {};
private:
    int m_healthPoints;
    int m_maxHealthPoints;
};

/*
 * Greater-or-equal than operator of HealthPoints class
 *
 * @param current - Reference to the current HealthPoints object being compared
 * @param other - Reference to HealthPoints object to be compared with
 * @ return
 *      True if the value of health of the current object is greater than the other's,
 *      or equal to it, False otherwise.
 */
bool operator>=(const HealthPoints& current, const HealthPoints& other);

/*
 * Lesser-or-equal than operator of HealthPoints class
 *
 * @param current - Reference to the current HealthPoints object being compared
 * @param other - Reference to HealthPoints object to be compared with
 * @ return
 *      True if the value of health of the current object is lesser than the other's,
 *      or equal to it, False otherwise.
 */
bool operator<=(const HealthPoints& current, const HealthPoints& other);

/*
* Greater-than operator of HealthPoints class
*
* @param current - Reference to the current HealthPoints object being compared
* @param other - Reference to HealthPoints object to be compared with
* @ return
*      True if the value of health of the current object is greater than the other's,
*      False otherwise.
*/
bool operator>(const HealthPoints& current, const HealthPoints& other);

/*
 * Not-Equal operator of HealthPoints class
 *
 * @param current - Reference to the current HealthPoints object being compared
 * @param other - Reference to HealthPoints object to be compared with
 * @ return
 *      True if objects are different, False if equal
 */
bool operator!=(const HealthPoints& current, const HealthPoints& other);

/*
 * Subtraction operator of HealthPoints class
 *
 * @param current - Reference to the first HealthPoints object that's being subtracted from
 * @param points - Number of points to be decreased from the current HealthPoints object
 * @return -
 *      The object after the subtraction
 */
HealthPoints operator-(const HealthPoints& current, const int points);

/*
 * Addition operator of HealthPoints class
 *
 * @param points - Amount of health points to be added to the HealthPoints object
 * @param current - Reference to the first HealthPoints object that's being added
 * @return -
 *      The object with the sum of the received HealthPoints objects
 */
HealthPoints operator+(const int points, const HealthPoints& current);

#endif //EX3_HEALTHPOINTS_H
