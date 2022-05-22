
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
    HealthPoints& operator+(const int value) const;

    /*
     * Subtraction operator of HealthPoints class
     *
     * @param value - The value that the HealthPoints is to be decreased by
     * @return -
     *      A reference to the HealthPoints object
     */
    HealthPoints& operator-(const int value) const;

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
     * Equality operator of HealthPoints class
     *
     * @param current - Reference to the current HealthPoints object being compared
     * @param other - Reference to HealthPoints object to be compared with
     * @ return
     *      True if objects are equal, False if different
     */
    friend bool operator==(const HealthPoints& current, const HealthPoints& other);

    /*
     * Not-Equal operator of HealthPoints class
     *
     * @param current - Reference to the current HealthPoints object being compared
     * @param other - Reference to HealthPoints object to be compared with
     * @ return
     *      True if objects are different, False if equal
     */
    friend bool operator!=(const HealthPoints& current, const HealthPoints& other);
};
#endif //EX3_HEALTHPOINTS_H
