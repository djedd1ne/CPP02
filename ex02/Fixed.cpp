/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki <djmekki@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:31:29 by djmekki           #+#    #+#             */
/*   Updated: 2023/07/30 21:31:29 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _value(0){
    //std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed&fixed){
    //std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}
Fixed::Fixed(const int num){
    //std::cout << "Int constructor called" << std::endl;
    this->_value = num << _bits;
}
Fixed::Fixed(const float float_num){
    //std::cout << "Float constructor called" << std::endl;
    this->_value = (int)roundf(float_num * (1 << this->_bits));
}
Fixed::~Fixed(void){
    //std::cout << "Destructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed &fixed){
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->_value = fixed.getRawBits();
    return (*this);
}
int Fixed::getRawBits(void) const{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}
void Fixed::setRawBits(const int raw){
    //std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}
float Fixed::toFloat(void) const{
    return ((float)_value / (1 << _bits));
}
int Fixed::toInt(void) const{
    return ((int)(roundf((float)_value / (1 << _bits))));
}
std::ostream &operator << (std::ostream &out, const Fixed &fixed){
    out << fixed.toFloat();
    return (out);
}

//COMPARAISON
bool Fixed::operator>(const Fixed &obj) const {
	return (this->_value > obj._value);
}

bool Fixed::operator<(const Fixed &obj) const {
	return (this->_value < obj._value);
}

bool Fixed::operator>=(const Fixed &obj) const {
	return (this->_value >= obj._value);
}

bool Fixed::operator<=(const Fixed &obj) const {
	return (this->_value <= obj._value);
}

bool Fixed::operator==(const Fixed &obj) const {
	return (this->_value == obj._value);
}

bool Fixed::operator!=(const Fixed &obj) const {
	return (this->_value != obj._value);
}

//ARITHMETICS 

Fixed	Fixed::operator + (const Fixed &obj) {
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed	Fixed::operator - (const Fixed &obj) {
	return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed	Fixed::operator * (const Fixed &obj) {
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed	Fixed::operator / (const Fixed &obj) {
	return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed& Fixed::operator++(void)
{
	_value++;
	return *this;
}

Fixed& Fixed::operator--(void)
{
	_value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed ret(*this);
	_value++;
	return (ret);
}

Fixed Fixed::operator--(int)
{
	Fixed ret(*this);
	_value--;
	return (ret);
}

// MIN_MAX

Fixed Fixed::min (Fixed &first, Fixed &second) {
	if (first > second)
		return (second);
	return (first);
}

Fixed Fixed::max (Fixed &first, Fixed &second) {
	if (first < second)
		return (second);
	return (first);
}

const Fixed Fixed::min(const Fixed &first, const Fixed &second) {
	if (first > second)
		return (second);
	return (first);
}

const Fixed Fixed::max(const Fixed &first, const Fixed &second) {
	if (first < second)
		return (second);
	return (first);
}