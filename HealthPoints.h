
#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H

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
     * Addition operator of HealthPoints class
     *
     * @param value - The value that the HealthPoints is to be increased by
     * @return -
     *      A reference to the HealthPoints object
     */
    HealthPoints& operator+(const int value);

    /*
     * Subtraction operator of HealthPoints class
     *
     * @param value - The value that the HealthPoints is to be decreased by
     * @return -
     *      A reference to the HealthPoints object
     */
    HealthPoints& operator-(const int value);

    /*
     * Addition assignment operator of HealthPoints class
     *
     * @param value - The value that the HealthPoints is to be increased by
     * @return -
     *      A reference to the HealthPoints object
     */
    HealthPoints& operator+=(const int value);

    /*
     * Subtraction assignment operator of HealthPoints class
     *
     * @param value - The value that the HealthPoints is to be decreased by
     * @return -
     *      A reference to the HealthPoints object
     */
    HealthPoints& operator-=(const int value);

    /*
     *
     */
    bool operator==(const HealthPoints& other)

};
#endif //EX3_HEALTHPOINTS_H
