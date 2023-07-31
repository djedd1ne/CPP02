/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki <djmekki@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:10:14 by djmekki           #+#    #+#             */
/*   Updated: 2023/07/30 21:10:14 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed{
    private:
        int _value;
        static const int _bits = 8;
    
    public:
        Fixed(void);
        Fixed(const Fixed &fixed);
        Fixed(const int num);
        Fixed(const float float_num);
        Fixed &operator=(const Fixed&fixed);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(const int raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif