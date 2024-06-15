
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:46:18 by oldault           #+#    #+#             */
/*   Updated: 2024/06/14 11:02:28 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include "Colors.hpp"
#include <unistd.h>
#include <iostream>

// ! error_handling.cpp
int invalid_input(int ac, char **av, const std::string& filename);
bool file_exists (const std::string& filename);

#endif // __UTILS_HPP__