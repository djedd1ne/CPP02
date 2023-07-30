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
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed&fixed){
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}
Fixed::~Fixed(void){
    std::cout << "Destructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed &fixed){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->_value = fixed.getRawBits();
    return (*this);
}
int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}
void Fixed::setRawBits(const int raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}